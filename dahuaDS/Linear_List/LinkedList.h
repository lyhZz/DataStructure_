#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;


template<typename ElemType>
class LinkedList
{
private:
    Node* head;
    int length;
public:
    typename struct linkedNode{
        ElemType data;
        Node* next;
    }Node;
public:
    LinkedList();
    ~LinkedList();

    bool isEmpty();
    void clear();
    int getLength();
    void getElem(int pos, ElemType& e);
    int locateElem(ElemType e);
    void insertList(int pos, ElemType e); // head in
    void deleteList(int pos, ElemType& e);
    
    void createListHead(int n);
    void visit();
};

