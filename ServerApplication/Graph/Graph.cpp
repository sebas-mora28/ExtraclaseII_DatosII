#include "GraphEdge.cpp"
#include "../List/LinkedList.h"


class Graph{
private:
    LinkedList<GraphNodo<int>*>* nodes;
    LinkedList<GraphEdge<GraphNodo<int>*>*>* edges;


public:
    Graph(){
        this->nodes = new  LinkedList<GraphNodo<int>*>();
        this->edges = new LinkedList<GraphEdge<GraphNodo<int>*>*>();
    }

    ~Graph() = default;



    LinkedList<GraphNodo<int>*>* getNodes(){
        return this->nodes;

    }


    LinkedList<GraphEdge<GraphNodo<int>*>*>* getEdges(){
        return this->edges;
    }

    void print(){
        for(int i=0; i<= getEdges()->getSize()-1; i++){
            std::cout << getEdges()->get(i)->data->getStartNode() << "\n";
            std::cout << getEdges()->get(i)->data->getEndNode() << "\n";
        }
    }






};