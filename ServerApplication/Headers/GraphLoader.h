//
// Created by sebasmora on 29/2/20.
//

#ifndef SERVERAPPLICATION_GRAPHLOADER_H
#define SERVERAPPLICATION_GRAPHLOADER_H

#include "../Headers/Graph.h"

class GraphLoader {

public:

    GraphLoader();

    void loadGraph();


private:
    Graph *graph;
    const int LINE_AMOUNT_OF_NODES{1};
    const int MAX_NUMBER_OF_NODES_CONNECTED_IN_A_EDGE{2};

    void loadGraphFromFile();

    void createGraphNodes(char *linePointer);

    void createGraphEdges(char *linePointer);
};


#endif //SERVERAPPLICATION_GRAPHLOADER_H
