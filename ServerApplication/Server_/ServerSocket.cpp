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
    int clientSocket;



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

        clientSocket = accept(listening, (sockaddr *) &client, &clientSize);

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
                searchShortestPath(buf, graphLoader);
            }
        }
        close(clientSocket);
    }




    void searchShortestPath(char buf[128], GraphLoader* graphLoader){
        int* indexNumber = (int*) malloc(sizeof(int) * 2);
        char* piece = strtok(buf, ",");
        int i = 0;
        while(piece != NULL) {
            std::cout << piece << "\n";
            indexNumber[i] = atoi(piece);
            piece = strtok(NULL, ",");
            i++;
        }
        int valueShortestPath  = graphLoader->getGraph()->shortestPath(indexNumber[0]-1, indexNumber[1]-1);
        char* message = const_cast<char *>(std::to_string(valueShortestPath).c_str());
        sendMessage(clientSocket, message);

    }

    void sendMessage(int clientSocket, char *message) {
        std::cout << "TAMANO DEL MENSAJE " << strlen(message) << "\n";
        std::cout << message << "\n";
        if(strlen(message) > 1) {
            int sendMessage = send(clientSocket, message, strlen(message) - 2, 0);
        }else{
            int sendMessage = send(clientSocket, message, strlen(message), 0);

        }
    }




};