//
// Created by eduard on 08.04.24.
//

#ifndef DOUBLELINKEDLIST_DOUBLENODE_H
#define DOUBLELINKEDLIST_DOUBLENODE_H

#include <memory>
using namespace std;
namespace double_node{
    template <typename T>
    struct Node{
        T data;
        shared_ptr<Node> next;
        weak_ptr<Node> previous;

        Node(T value) : data(value) {};
    };
}

#endif //DOUBLELINKEDLIST_DOUBLENODE_H
