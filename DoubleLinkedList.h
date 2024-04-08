//
// Created by eduard on 08.04.24.
//

#ifndef DOUBLELINKEDLIST_DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_DOUBLELINKEDLIST_H

#include "DoubleNode.h"
#include <iostream>
using namespace std;
using namespace double_node;

template <typename T>
class DoubleLinkedList {
private:
    shared_ptr<Node<T>> head;
    shared_ptr<Node<T>> tail;
    int size;
public:
    DoubleLinkedList() : head{nullptr},tail{nullptr}, size{0} {};

    void unshift(T data);
    void push(T data);
};

template<typename T>
void DoubleLinkedList<T>::push(T data) {
    shared_ptr<Node<T>> newNode = make_shared<Node<T>>(data);
    if(!tail){
        head=tail=newNode;
    } else{
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
    size++;
}

template<typename T>
void DoubleLinkedList<T>::unshift(T data) {
    shared_ptr<Node<T>> newNode = make_shared<Node<T>>(data);
    if(!head){
        head=tail=newNode;
    }else{
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
    }
    size++;
}



#endif //DOUBLELINKEDLIST_DOUBLELINKEDLIST_H
