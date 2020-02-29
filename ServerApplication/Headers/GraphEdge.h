//
// Created by sebasmora on 29/2/20.
//

#ifndef SERVERAPPLICATION_GRAPHEDGE_H
#define SERVERAPPLICATION_GRAPHEDGE_H

template<class T>
class GraphEdge{

private:
    T statNode;
    T endNode;
    double weigth;


public:

    GraphEdge(T startNode, T endNode, int weight);
    ~GraphEdge();

    T getStartNode();


    void setStartNode(GraphNodo<T>* startNode);

    T getEndNode();

    void setEndNode(GraphNodo<T>* endNode);

    double getWeight();

    void setWeight();


};


#endif //SERVERAPPLICATION_GRAPHEDGE_H
