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
    void pop();
    void shift();

    void show();
};

template<typename T>
void DoubleLinkedList<T>::shift() {
    if(!head){
        return;
    }
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->previous.reset();
    }
    --size;
}

template<typename T>
void DoubleLinkedList<T>::pop() {
    if(!tail){
        return;
    }
    if(head == tail){
        head = tail = nullptr;
    }else{
        tail = tail->previous.lock();
        tail->next = nullptr;
    }
    --size;
}

template<typename T>
void DoubleLinkedList<T>::show() {
    shared_ptr<Node<T>> current = head;
    while (current){
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl;
}

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
