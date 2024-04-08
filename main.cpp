#include <iostream>
#include "DoubleLinkedList.h"
using namespace std;
int main() {
    DoubleLinkedList<int> list;
    list.push(1);
    list.show();
    list.unshift(2);
    list.show();
    list.pop();
    list.show();
    return 0;
}
