#include <iostream>



template<class T>
class Nodo{
public:

    T data;
    Nodo* next;

    Nodo(int data){
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
        if(head== nullptr){
            return true;
        }else{
            return false;
        }
    }

    void addNodo(T data){
        if(head== nullptr){
            Nodo<T> *newNodo = new Nodo<T>(data);
            head = newNodo;
            size++;
        }else{
            Nodo<T> *current = head;
            std::cout<< "current "  << current << " head " << head << "\n";
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



