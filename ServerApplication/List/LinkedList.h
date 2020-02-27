    //
// Created by sebasmora on 25/2/20.
//

#ifndef SERVERAPPLICATION_LINKEDLIST_H
#define SERVERAPPLICATION_LINKEDLIST_H

#include <iostream>


template<class T>
class Nodo{
public:

    T data;
    Nodo* next;

    Nodo(T data){
        this->data = data;
        this->next = nullptr;
    }
};


template<class T>
class LinkedList{
public:
    LinkedList(){
        this->head = nullptr;
        this->size =0;
    }

    ~LinkedList()= default;

    bool isEmpty(){
        return head == nullptr;
    }

    void addNodo(T data){
        //std::cout << data << "\n";
        if(head== nullptr){
            head =  new Nodo<T>(data);
            size++;
        }else{
            Nodo<T> *current = head;
            //std::cout<< "current "  << current << " head " << head << "\n";
            while(current->next != nullptr){
                current = current->next;
            }
            current->next = new Nodo<T>(data);
            size++;
        }
    }
    void remove(int index){
        if(size == 1){
            std::cout << head << " data : " << head->next;
            head = nullptr;
            size = 0;
        }else if(index == 0){
            head = head->next;
            size--;
        }else{
            int i = 0;
            Nodo<T> *current = head;
            while(i < index -1){
                current = current->next;
                i++;
            }
            current->next = current->next->next;
            size--;
        }
    }
    void printElements(){
        Nodo<T> *current = head;
        while(current != nullptr){
            std::cout << "Direccion en memoria " << current << "\n";
            std::cout << "El valor de la lista es " << current->data << "\n";
            std::cout << "Next :" << current->next << "\n";
            current = current->next;
        }

    }

    int getSize(){
        return this->size;
    }

    Nodo<T>* get(int index){
        if(index>=size){
            return nullptr;
        }else{
            int current{0};
            Nodo<T>* temp = head;
            for(current; current < index;current++){
                temp = temp->next;
            }
            return temp;
        }
    }

    T getLast(){
        Nodo<T> *current = head;
        while(current->next != nullptr){
            current = current->next;

        }
        return current;
    }

    void removeAll(){
        head = nullptr;
        size = 0;
    }
private:
    Nodo<T>* head;
    int size{};

};

#endif //SERVERAPPLICATION_LINKEDLIST_H
