#include <cmath>
#include "GraphNodo.cpp"


template<class T>
class GraphEdge{

private:
    GraphNodo<T> *statNode;
    GraphNodo<T> *endNode;
    double weigth;


public:

    GraphEdge() = default;

    GraphEdge(GraphNodo<T>* startNode, GraphNodo<T>* endNode, int weight){
        this->statNode = startNode;
        this->endNode = endNode;
        this->weigth = weight;
    }

    GraphNodo<T>* getStartNode(){
        return this->statNode;
    }
    void setStartNode(GraphNodo<T>* startNode){
        this->statNode = startNode;
    }

    GraphNodo<T>* getEndNode(){
        return this->endNode;
    }

    void setEndNode(GraphNodo<T>* endNode){
        this->endNode = endNode;
    }

    double getWeight(){
        return this->weigth;
    }

    void setWeight(){
        this->weigth = weigth;
    }


};
