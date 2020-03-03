

/**
 * @class Graph Nodo implementation
 * @tparam T
 */
template<class T>
class GraphNodo{
private:
    int inDegree;
    int outDegree;
    T entity;
    bool visited;


public:

    /**
     * @brief Constructor
     * @param entity
     */
    GraphNodo(T entity){
        this->inDegree = 0;
        this->outDegree = 0;
        this->entity = entity;
    }


    /**
     * @brief Destructor
     */
    ~GraphNodo() = default;

    void setInDegree(int inDegree){
        this->inDegree = inDegree;
    }
    int getInDegree(){
        return this->inDegree;
    }
    int getOutDegree(){
        return this->outDegree;
    }
    void setOutDegree(int outDegree){
        this->outDegree;
    }

    T getEntity(){
        return this->entity;
    }
    void setEntity(){
        this->entity = entity;
    }

    bool isVisited(){
        return this->visited;
    }

    void setVisited(bool visited){
        this->visited = visited;
    }

};

