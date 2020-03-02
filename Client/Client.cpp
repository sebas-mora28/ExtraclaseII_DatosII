#include <QApplication>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string>


class Client{


public:
    Client() = default;

    ~Client() = default;

    void createSocket(){
        client = socket(AF_INET, SOCK_STREAM, 0);

         if(client == -1){
             std::cout << "No se pudo crear el server" << "\n";
         }

         connectClient();

    }

    QString sendMessage(std::string message){
        int sendMessage = send(client, message.c_str(), message.size()+1, 0);
        if(sendMessage == -1){
            std::cout << "No se ha podido enviar el mensage";
        }



        char buf[128];
        memset(buf, 0, 128);
        int bytesReceived = recv(client, buf, 4096, 0);
        std::cout << "Server " << std::string(buf, bytesReceived) << "\n";
        return  QString::fromStdString(std::string(buf, bytesReceived));



    }


private:
    int client;


    void connectClient(){
        int port = 54000;
        std::string ipAddress=  "127.0.0.1";

        sockaddr_in hint;
        hint.sin_family = AF_INET;
        hint.sin_port = htons(port);
        inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);


        int connetServer = connect(client, (sockaddr*)&hint, sizeof(hint));

        if(connetServer == -1){
            std::cout << "No se pudo conectar al server";
        }



       }



    void sendMessage(){
        std::cout << "LLEGA HASTA AQUI";
        char buf[4096];
        std::string userInput;
        userInput = "HOLA MUNDO";
        int sendRes = send(client, userInput.c_str(), userInput.size() +1, 0);

        if(sendRes == -1){
            std::cout << "No se pudo enviar el mensje" << "\n";
        }

        memset(buf,0, 4096);
        int bytesReceived = recv(client, buf, 4096, 0);
        std::cout << "Server " << std::string(buf, bytesReceived) << "\n";
        close(client);

    }

};

