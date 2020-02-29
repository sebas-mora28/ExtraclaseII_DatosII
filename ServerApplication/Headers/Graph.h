//
// Created by sebasmora on 29/2/20.
//

#ifndef SERVERAPPLICATION_GRAPH_H
#define SERVERAPPLICATION_GRAPH_H

#include "GraphEdge.cpp"
#include "GraphNodo.cpp"
#include "../List/LinkedList.h"


class Graph {
private:
    LinkedList<GraphNodo<int> *> *nodes;
    LinkedList<GraphEdge<GraphNodo<int> *> *> *edges;


    LinkedList<GraphNodo<int> *> *getNodes();

    LinkedList<GraphEdge<GraphNodo<int> *> *> *getEdges();

public:
    Graph();

    ~Graph();

    void addNode(int index);

    void addEdge(int indexStartNode, int indexEndNode);

    void printEdges();

    void printNodes();


}



#endif //SERVERAPPLICATION_GRAPH_H
