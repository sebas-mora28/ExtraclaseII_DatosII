#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include "../Graph/GraphLoader.cpp"


class ServerSocket{

private:
    bool bodyTxtSended{true};



public:

    void createSocket(GraphLoader* graphLoader) {

        int listening = socket(AF_INET, SOCK_STREAM, 0);
        if (listening == -1) {
            std::cerr << "Can't create a socket! Quitting" << "\n";
        }

        sockaddr_in hint;
        hint.sin_family = AF_INET;
        hint.sin_port = htons(54000);
        inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

        bind(listening, (sockaddr *) &hint, sizeof(hint));


        listen(listening, SOMAXCONN);


        sockaddr_in client;
        socklen_t clientSize = sizeof(client);

        int clientSocket = accept(listening, (sockaddr *) &client, &clientSize);

        char host[NI_MAXHOST];
        char service[NI_MAXSERV];

        memset(host, 0, NI_MAXHOST);
        memset(service, 0, NI_MAXSERV);

        if (getnameinfo((sockaddr *) &client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0) {
            std::cout << host << " connected on port " << service << "\n";
        } else {
            inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
            std::cout << host << " connected on port " << ntohs(client.sin_port) << "\n";
        }


        close(listening);


        char buf[128];

        while (true) {
            std::cout << "INGRESA" << "\n";
            memset(buf, 0, 128);

            int bytesReceived = recv(clientSocket, buf, 128, 0);

            std::cout << "BytesReceived " << bytesReceived << "\n";

            if (bytesReceived == -1) {
                std::cerr << "Error in recv(). Quitting" << "\n";
                break;
            }

            if (bytesReceived == 0) {
                std::cout << "Client disconnected " "\n";
                break;
            }
            std::cout << std::string(buf, 0, bytesReceived) << "\n";


            if(bodyTxtSended){
                sendMessage(clientSocket, const_cast<char *>(graphLoader->getBody().c_str()));
                bodyTxtSended = false;
            }else{

                send(clientSocket, buf, bytesReceived + 1, 0);
            }


            sendMessage(clientSocket,"Se ha enviado");

        }


        close(clientSocket);
    }


    void sendMessage(int clientSocket, char *message) {
        std::cout << "TAMANO DEL MENSAJE " << strlen(message) << "\n";
        std::cout << message << "\n";
        int sendMessage = send(clientSocket, message, strlen(message)-2, 0);
        if (sendMessage == -1) {
            std::cout << "No se ha podido enviar el mensaje";
        }
    }




};