#include <fstream>
#include "Graph/GraphLoader.cpp"
#include "Server_/ServerSocket.cpp"
#include "List/LinkedList.h"

int main(){

    GraphLoader graphLoader = GraphLoader();
    graphLoader.loadGraph();


    ServerSocket initServer{ServerSocket()};
    initServer.createSocket();








}