#include "GraphNodo.cpp"


template<class T>

        /**
         * @class Graph Edge implementation
         * @tparam T
         */
class GraphEdge{

private:
    T statNode;
    T endNode;
    double weigth;


public:


    /**
     * @brief Constructor
     * @param startNode
     * @param endNode
     * @param weight
     */

    GraphEdge(T startNode, T endNode, int weight){
        this->statNode = startNode;
        this->endNode = endNode;
        this->weigth = weight;
    }


    /**
     *@brief Destructor
     */
    ~GraphEdge()= default;

    T getStartNode(){
        return this->statNode;
    }

    void setStartNode(GraphNodo<T>* startNode){
        this->statNode = startNode;
    }

    T getEndNode(){
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
