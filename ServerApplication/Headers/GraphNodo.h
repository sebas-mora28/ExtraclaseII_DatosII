//
// Created by sebasmora on 29/2/20.
//

#ifndef SERVERAPPLICATION_GRAPHNODO_H
#define SERVERAPPLICATION_GRAPHNODO_H



template<class T>
class GraphNodo{
private:
    int inDegree;
    int outDegree;
    T entity;
    bool visited;


public:

    GraphNodo(T entity);

    void setInDegree(int inDegree);


    int getInDegree();


    int getOutDegree();

    void setOutDegree(int outDegree);


    T getEntity();

    void setEntity();

    bool isVisited();

    void setVisited(bool visited);

};



#endif //SERVERAPPLICATION_GRAPHNODO_H
