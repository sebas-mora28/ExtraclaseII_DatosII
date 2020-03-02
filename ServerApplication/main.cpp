#include <fstream>
#include "Server_/ServerSocket.cpp"


int main(){

    GraphLoader* graphLoader = new GraphLoader();
    graphLoader->loadGraph();


    ServerSocket* initServer =new  ServerSocket();
    initServer->createSocket(graphLoader);








}