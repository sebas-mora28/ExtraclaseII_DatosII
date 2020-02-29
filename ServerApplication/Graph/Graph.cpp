
//#include "../Headers/GraphEdge.h"
#include "../Graph/GraphEdge.cpp"
#include "../List/LinkedList.h"


class Graph{
private:
    LinkedList<GraphNodo<int>*>* nodes;
    LinkedList<GraphEdge<GraphNodo<int>*>*>* edges;


    LinkedList<GraphNodo<int>*>* getNodes(){
        return this->nodes;

    }

    LinkedList<GraphEdge<GraphNodo<int>*>*>* getEdges(){
        return this->edges;
    }


public:
    Graph(){
        this->nodes = new  LinkedList<GraphNodo<int>*>();
        this->edges = new LinkedList<GraphEdge<GraphNodo<int>*>*>();
    }

    ~Graph() {
        delete nodes;
        delete edges;
    };



    void addNode(int index){
        getNodes()->addNodo(new GraphNodo<int>(index));

    }

    void addEdge(int indexStartNode, int indexEndNode){
        GraphNodo<int>* startNode = getNodes()->get(indexStartNode)->data;
        startNode->setOutDegree(startNode->getOutDegree() + 1);

        GraphNodo<int>* endNode = getNodes()->get(indexEndNode)->data;
        endNode->setInDegree(endNode->getInDegree() +1);

        int weight(startNode->getOutDegree() + endNode->getOutDegree());

        getEdges()->addNodo(new GraphEdge<GraphNodo<int>*>(startNode, endNode, weight));
    }


    void printEdges(){
        for(int i=0; i<= getEdges()->getSize()-1; i++){
            std::cout << getEdges()->get(i)->data->getStartNode() << "   " <<  getEdges()->get(i)->data->getEndNode() << "\n";
            std::cout << getEdges()->get(i)->data->getStartNode()->getEntity() << "   " <<  getEdges()->get(i)->data->getEndNode()->getEntity() << "\n";
            std::cout << "--------------------------------------------------------------" << "\n";
        }
    }

    void printNodes(){
        for(int i=0; i<= getNodes()->getSize()-1; i++){
            std::cout << getNodes()->get(i)->data->getEntity() << "\n";
        }
    }






};