#include <fstream>
#include <iostream>
#include <string.h>
//#include "../Headers/Graph.h"
#include "Graph.cpp"



/**
 * This class loads the graph from a txt file, creates the nodes and edges specifies in the txt file and  send it to the client server
 */

class GraphLoader{

public:


    /**
     * Constructor
     */

    GraphLoader(){
        this->graph = new Graph();

    }

    /**
     * Destructor
     */

    void loadGraph(){
        loadGraphFromFile();
    }


    /**
     * Returns the body of the txt file
     * @return
     */

    std::string getBody(){
        return bodyTxt;
    }


    Graph* getGraph(){
        return this->graph;
    }


private:
    Graph* graph;
    const int LINE_AMOUNT_OF_NODES{1};
    const int MAX_NUMBER_OF_NODES_CONNECTED_IN_A_EDGE{2};
    std::string bodyTxt;


    /**
     * This method opens the txt file and parses it line by line to get the number of nodes and the edges
     */
    void loadGraphFromFile(){
        char line[256];
        std::ifstream fin("/home/sebasmora/Desktop/test.txt");
        int counterLine(1);
        while(!fin.eof()){
            fin >> line;
            char* linePointer = strtok(line, ",");
            if(counterLine == LINE_AMOUNT_OF_NODES){
                createGraphNodes(linePointer);
                counterLine++;
            }else{
                createGraphEdges(linePointer);
            }

        }
        concanetateMessage();


    }

    /**
     * This method receives the number of nodes and creates them
     * @param linePointer
     */
    void createGraphNodes(char* linePointer){
        int amount_of_nodes = atoi(linePointer);
        for(int index =0; index < amount_of_nodes; index++){
            graph->addNode(index);
        }
    }


    /**
     * This method receives the line with the information to create the edge
     * @param linePointer
     */

    void createGraphEdges(char* linePointer){
        int index[3];
        int count{0};
        while(linePointer != NULL){
            index[count] = atoi(linePointer);
            linePointer = strtok(NULL, ",");
            count++;
            if(count == MAX_NUMBER_OF_NODES_CONNECTED_IN_A_EDGE+1){
                //std::cout << index[0] << "    " << index[1] << "   " <<  index[2] << "\n";
                graph->addEdge(index[0]-1, index[1]-1, index[2]);
            }
        }

    }





    /**
     * This method cocanetate the body of the txt to store it int a single variable
     */
    void concanetateMessage(){
        std::ifstream archivo("/home/sebasmora/Desktop/test.txt");
        char linea[128];
        while(!archivo.eof()){
            archivo.getline(linea, sizeof(linea));
            bodyTxt += linea;
            bodyTxt += "|";
        }
    }

};
