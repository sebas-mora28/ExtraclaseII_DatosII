/**
 * Technological Institute of Costa Ric
 * Computer Engineering
 * Algoritmos y Estructuras de Datos II
 * @author Sebastian Mora Godínez
 * Description: Linked List implementation, includes Nodo class and add, remove, get methods
 *
 */

#ifndef SERVERAPPLICATION_LINKEDLIST_H
#define SERVERAPPLICATION_LINKEDLIST_H
#include <iostream>

/*
 * Nodo class
 * Description: Nodo class implementation, holds the data and the pointer to the next nodo
 */
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




/*
 * Linked List
 * Description: This class contains all the necessary methods for linked List's implementation
 */
template<class T>
class LinkedList{
public:

    /**
     * Constructor, initialize  the head pointer and the size
     */
    LinkedList(){
        this->head = nullptr;
        this->size = 0;
    }


    /**
     * Destructor
     */
    ~LinkedList() = default;


    /**
     * Verify if the linked list is empty
     * @return true if it's empty, otherwise it's false
     */

    bool isEmpty(){
        return head == nullptr;
    }


    /**
     * Add a new nodo to the tail of the linked list
     * @param data
     */


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

    /**
     * Remove a nodo from a especific position
     * @param index
     */
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

    /**
     * Returns the value of the size
     * @return
     */
    int getSize(){
        return this->size;
    }

    /**
     * Returns the nodo from the especified position
     * @param index
     * @return nodo encoutered in the index position
     */

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
