#include <iostream>
#define NULL 0

template<class T>
class Nodo{
public:

    T data;
    Nodo* next;

    Nodo(int data){
        this->data = data;
        this->next = NULL;
    }
};


template<class T>
class LinkedList{
public:
    LinkedList(){
        this->head = NULL;
        this->size =0;
    }

    bool isEmpty(){
        if(head==NULL){
            return true;
        }else{
            return false;
        }
    }

    void addNodo(T data){
        if(head== NULL){
            Nodo<T> *newNodo = new Nodo<T>(data);
            head = newNodo;
            size++;
        }else{
            Nodo<T> *current = head;
            std::cout<< "current "  << current << " head " << head << "\n";
            while(current->next != NULL){
                current = current->next;
            }
            current->next = new Nodo<T>(data);
            size++;
        }
    }


    void remove(int index){
        if(size == 1){
            delete(head);
            std::cout << head << " data : " << head->next;
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
        while(current != NULL){
            std::cout << "Direccion en memoria " << current << "\n";
            std::cout << "El valor de la lista es " << current->data << "\n";
            std::cout << "Next :" << current->next << "\n";
            current = current->next;
        }


    }


private:
    Nodo<T>* head;
    int size;

};



