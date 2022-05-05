#pragma once
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

template<typename ElemType>
struct linkedNode{
    ElemType data;
    linkedNode<ElemType>* next;
};


template<typename ElemType>
class LinkedList
{
private:
    typedef linkedNode<ElemType> Node; //after tempalte , typedef is no permitted 
    Node* head;
    int length;
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

