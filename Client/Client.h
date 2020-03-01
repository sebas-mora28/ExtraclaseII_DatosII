#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string>

class Client{

public:
    Client();

    ~Client();

    void createSocket();

    std::string sendMessage(std::string message);



private:
    int client;


    void connectClient();



    void sendMessage();


};

#endif // CLIENT_H
