#include <fstream>
#include "Graph/GraphLoader.cpp"
#include "Server_/ServerSocket.cpp"


int main(){

    GraphLoader graphLoader = GraphLoader();
    graphLoader.loadGraph();


    ServerSocket initServer = ServerSocket();
    initServer.createSocket(graphLoader.getBody());








}