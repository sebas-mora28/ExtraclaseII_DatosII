#include <fstream>
#include <string.h>
#include "Graph.cpp"

using namespace std;


class GraphLoader{

public:

    GraphLoader(){
        this->graph = new Graph();

    }

    void loadGraph(){
        loadGraphFromFile();

    }


private:
    Graph* graph;
    const int LINE_AMOUNT_OF_NODES{1};
    const int MAX_NUMBER_OF_NODES_CONNECTED_IN_A_EDGE{2};

    void loadGraphFromFile(){
        char line[256];
        ifstream fin("/home/sebasmora/Desktop/test.txt");
        int counterLine(1);
        while(!fin.eof()){
            fin >> line;
            char* linePointer = strtok(line, ",");
            if(counterLine == LINE_AMOUNT_OF_NODES){
                createGraphNodes(linePointer);
                //graph->printNodes();
                counterLine++;
            }else{
                createGraphEdges(linePointer);
            }

        }
        //graph->printEdges();



    }
    void createGraphNodes(char* linePointer){
        int amount_of_nodes = atoi(linePointer);
        for(int index =0; index < amount_of_nodes; index++){
            //std::cout << "SE HA CREADO UN NODO" << "\n";
            graph->addNode(index);
        }
    }


    void createGraphEdges(char* linePointer){
        int index[2];
        int count{0};
        while(linePointer != NULL && count < MAX_NUMBER_OF_NODES_CONNECTED_IN_A_EDGE){
            index[count] = atoi(linePointer);
            linePointer = strtok(NULL, ",");
            count++;
            if(count == MAX_NUMBER_OF_NODES_CONNECTED_IN_A_EDGE){
                //std::cout << index[0] << "    " << index[1] << "\n";
                graph->addEdge(index[0], index[1]);
            }
        }


    }


};