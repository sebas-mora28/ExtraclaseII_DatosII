
//#include "../Headers/GraphEdge.h"
#include "../Graph/GraphEdge.cpp"
#include "../List/LinkedList.h"
#include <vector>
#include <queue>
#include <iostream>

#define INF 99999

typedef std::pair<int,int> pairs;

/**
 * This class contains the graph implementation
 */

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

    /**
     * Constructor
     */
    Graph(){
        this->nodes = new  LinkedList<GraphNodo<int>*>();
        this->edges = new LinkedList<GraphEdge<GraphNodo<int>*>*>();
    }


    /**
     * Destructor
     */

    ~Graph() {
        delete nodes;
        delete edges;
    };



    /**
     * Adds a new GraphNodo
     * @param index
     */

    void addNode(int index){
        getNodes()->addNodo(new GraphNodo<int>(index));

    }


    /**
     * Adds a new GraphEnde
     * @param indexStartNode
     * @param indexEndNode
     * @param weight
     */

    void addEdge(int indexStartNode, int indexEndNode, int weight){
        GraphNodo<int>* startNode = getNodes()->get(indexStartNode)->data;
        startNode->setOutDegree(startNode->getOutDegree() + 1);

        GraphNodo<int>* endNode = getNodes()->get(indexEndNode)->data;
        endNode->setInDegree(endNode->getInDegree() +1);

        //int weight(startNode->getOutDegree() + endNode->getOutDegree());

        getEdges()->addNodo(new GraphEdge<GraphNodo<int>*>(startNode, endNode, weight));
    }


    /**
     * Prints all the edges of the graph
     */
    void printEdges(){
        for(int i=0; i<= getEdges()->getSize()-1; i++){
            std::cout << getEdges()->get(i)->data->getStartNode() << "   " <<  getEdges()->get(i)->data->getEndNode() << "\n";
            std::cout << getEdges()->get(i)->data->getStartNode()->getEntity() << "   " <<  getEdges()->get(i)->data->getEndNode()->getEntity() << "\n";
            std::cout << "--------------------------------------------------------------" << "\n";
        }
    }


    /**
     * Print all the nodes of the graph
     */

    void printNodes(){
        for(int i=0; i<= getNodes()->getSize()-1; i++){
            std::cout << getNodes()->get(i)->data->getEntity() << "\n";
        }
    }


    /**
     * This methods calls initShortestPath to start executing dijkstra algorithm
     * @param startNode
     * @param endNode
     * @return the value of the shortest path
     */

    std::string shortestPath(int startNode){
        return initShortestPath(startNode);
    }

private:


    /**
     * This methods implements and executes dijkstra algorithm
     * @param adj
     * @param source
     * @param end
     * @return
     */

    std::string DijkstraAlgorithm(std::vector<pairs> adj[], int source){

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


        std::string message = "";
        for(int current : dist){
            message += std::to_string(current)  + ",";
        }

        return message;

    }




    /**
     * This method creates the adjacency list and call DijkstraAlgorithm
     * @param startNode
     * @param endNode
     * @return
     */
    std::string initShortestPath(int startNode){
        std::vector<pairs> adj[getNodes()->getSize()];
        for(int i=0; i < getEdges()->getSize(); i++){
            auto* current  = edges->get(i)->data;
            addEdgeShortestPath(adj, current->getStartNode()->getEntity(), current->getEndNode()->getEntity(), current->getWeight());
        }
        return DijkstraAlgorithm(adj, startNode);

    }



    /**
     * This method push a new pair into the adyacency list
     * @param adj
     * @param startNode
     * @param endNode
     * @param weight
     */
    void addEdgeShortestPath(std::vector <pairs> adj[], int startNode, int endNode, int weight){
        adj[startNode].push_back(std::make_pair(endNode, weight));
    }









};