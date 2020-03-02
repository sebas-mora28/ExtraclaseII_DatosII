
//#include "../Headers/GraphEdge.h"
#include "../Graph/GraphEdge.cpp"
#include "../List/LinkedList.h"
#include <vector>
#include <queue>
#include <iostream>

#define INF 99999

typedef std::pair<int,int> pairs;

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

    void addEdge(int indexStartNode, int indexEndNode, int weight){
        GraphNodo<int>* startNode = getNodes()->get(indexStartNode)->data;
        startNode->setOutDegree(startNode->getOutDegree() + 1);

        GraphNodo<int>* endNode = getNodes()->get(indexEndNode)->data;
        endNode->setInDegree(endNode->getInDegree() +1);

        //int weight(startNode->getOutDegree() + endNode->getOutDegree());

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

    void shortestPath(int startNode, int endNode){
        initShortestPath(startNode, endNode);
    }

private:

    void DijkstraAlgorithm(std::vector<pairs> adj[], int source, int end){

        std::priority_queue < pairs, std::vector<pairs>, std::greater<pairs> > pqueue;

        std::vector<int> dist(getNodes()->getSize(), INF);

        pqueue.push(std::make_pair(0, source));
        dist[source] = 0;


        while( !pqueue.empty()) {

            int current = pqueue.top().second;
            pqueue.pop();

            for (auto temp : adj[current]) {
                int v = temp.first;
                int weight = temp.second;
                if (dist[v] > dist[current] + weight) {
                    dist[v] = dist[current] + weight;
                    pqueue.push(std::make_pair(dist[v], v));
                }
            }

        }

        for(int i=0; i < dist.size(); i++){
            std::cout << i << "  " << dist[i] <<"\n";
        }

    }




    void initShortestPath(int startNode, int endNode){
        std::cout << "NODOS:   "  << startNode << "   " << endNode << "\n";
        std::vector<pairs> adj[getNodes()->getSize()];
        std::cout << "Pasa" << "\n";
        for(int i=0; i < getEdges()->getSize(); i++){
            auto* current  = edges->get(i)->data;
            std::cout << current->getWeight() << "\n";
            addEdgeShortestPath(adj, current->getStartNode()->getEntity(), current->getEndNode()->getEntity(), current->getWeight());
        }
        DijkstraAlgorithm(adj, startNode, endNode);

    }


    void addEdgeShortestPath(std::vector <pairs> adj[], int startNode, int endNode, int weight){
        adj[startNode].push_back(std::make_pair(endNode, weight));
    }









};