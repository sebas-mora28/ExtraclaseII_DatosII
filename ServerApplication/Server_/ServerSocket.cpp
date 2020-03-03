#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include "../Graph/GraphLoader.cpp"



/**
 * @class This class handles the server and the communication with the client
 */
class ServerSocket{

private:
    bool bodyTxtSended{true};
    int clientSocket;
    const std::string COMMAND_LOAD_GRAPH = "loadGraph";



public:


    /**
     * @brief This methods creates the server and set up the communication with the client.
     * @param graphLoader
     */
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


            std::string messageReceive = std::string(buf, 0, bytesReceived);

            if(messageReceive.compare(COMMAND_LOAD_GRAPH) == 0){
                sendMessage(clientSocket, const_cast<char *>(graphLoader->getBody().c_str()));
                bodyTxtSended = false;
            }else{
                searchShortestPath(buf, graphLoader);
            }
        }
        close(clientSocket);
    }





    /**
     * @brief This method receives the information of two nodes to search de shortest path
     * @param buf
     * @param graphLoader
     */
    void searchShortestPath(char buf[128], GraphLoader* graphLoader){
        int indexNumber = 0; //INDEX BY DEFAULT
        char* piece = strtok(buf, ",");
        int i = 0;
        while(piece != NULL) {
            indexNumber  = atoi(piece);
            piece = strtok(NULL, ",");
            i++;
        }
        std::string valuesShortestPath  = graphLoader->getGraph()->shortestPath(indexNumber-1);
        sendMessage(clientSocket, const_cast<char *>(valuesShortestPath.c_str()));

    }

    /**
     * @brief This methods receive a new message and send it to the client
     * @param clientSocket
     * @param message
     */

    void sendMessage(int clientSocket, char *message) {
        std::cout << "TAMANO DEL MENSAJE " << strlen(message)  << "MENSAJE " << message << "\n";
            int sendMessage = send(clientSocket, message, strlen(message), 0);
            if(sendMessage == -1){
                std::cout << "Ocurrió un problema" << "\n";
            }

    }

};