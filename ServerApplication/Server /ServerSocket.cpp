#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

using namespace std;


class ServerSocket{

public:

    void createSocket(){

        int listening = socket(AF_INET, SOCK_STREAM, 0);
        if (listening == -1)
        {
            cerr << "Can't create a socket! Quitting" << endl;
        }

        sockaddr_in hint;
        hint.sin_family = AF_INET;
        hint.sin_port = htons(54000);
        inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

        bind(listening, (sockaddr*)&hint, sizeof(hint));


        listen(listening, SOMAXCONN);


        sockaddr_in client;
        socklen_t clientSize = sizeof(client);

        int clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

        char host[NI_MAXHOST];
        char service[NI_MAXSERV];

        memset(host, 0, NI_MAXHOST);
        memset(service, 0, NI_MAXSERV);

        if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
        {
            cout << host << " connected on port " << service << endl;
        }
        else
        {
            inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
            cout << host << " connected on port " << ntohs(client.sin_port) << endl;
        }


        close(listening);


        char buf[4096];

        while (true)
        {
            memset(buf, 0, 4096);


            int bytesReceived = recv(clientSocket, buf, 4096, 0);

            cout << "BytesReceived " << bytesReceived << "\n";

            if (bytesReceived == -1)
            {
                cerr << "Error in recv(). Quitting" << endl;
                break;
            }

            if (bytesReceived == 0)
            {
                cout << "Client disconnected " << endl;
                break;
            }

            cout << string(buf, 0, bytesReceived) << endl;

            sendMessage(clientSocket,"Se ha enviado");

        }


        close(clientSocket);
    }


    void sendMessage(int clientSocket, char* message){
        cout << sizeof(message);
        send(clientSocket, message, sizeof(message), 0);
    }


};






































/*
class ServerSocket{

private:
    int socketServer;
    int socketClient;
    sockaddr_in hint;
    sockaddr_in client;
    int bytesReceived;
    char messageReceived[250];



    void bindSocket(){
        hint.sin_family = AF_INET;
        hint.sin_port = htons(54000);
        inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);
        bind(socketServer, (sockaddr*)&hint, sizeof(hint));
        listen(socketServer, SOMAXCONN);

        acceptConnection();

    }

    void acceptConnection(){
        socklen_t clientSize = sizeof (client);

        socketClient = accept(socketServer, (sockaddr*)&client, &clientSize);

        connetingToPort();

    }



    void connetingToPort(){
        char host[NI_MAXHOST];
        char service[NI_MAXSERV];
        memset(host, 0, NI_MAXHOST);
        memset(service, 0, NI_MAXSERV);


        if(getnameinfo((sockaddr*)&client, sizeof (client),host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0){
            cout << host << "connected on port " << service << "\n";
        }else{
            inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
            cout << host << "connected on port " <<  ntohs(client.sin_port) << "\n";
        }

        closeSocketServer();
        receiveData();


    }

    void closeSocketServer(){
        close(socketServer);
    }


    void receiveData(){

        while(true){
            memset(messageReceived, 0, 250);

            bytesReceived = recv(socketClient, messageReceived, 250, 0);

            if(bytesReceived == -1){
                cerr << "Error recibiendo el mensaje";
                break;
            }else if(bytesReceived == 0){
                cout << "Client Disconnected " << "\n";
                break;

            }

            //cout << string(messageReceived, 0, bytesReceived) << "\n";

            closeSocketClient();




        }


    }

    void closeSocketClient() {
        close(socketClient);
    }

public :
    void createSocket(){
        socketServer = socket(AF_INET, SOCK_STREAM, 0);
        if(socketServer == -1){
            cerr << "Ocurrio un error en el socker"<< "\n";
        }

        bindSocket();

    }

    void sendMessage(char messageToSend[250]){
        cout << "Mensaje enviado " << messageToSend << "\n";
        send(socketClient, messageToSend, bytesReceived +1, 0);


    }



};
*/
