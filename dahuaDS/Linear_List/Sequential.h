/*
 * @Description: 
 * @Version: 1.0
 * @Autor: lyh
 * @Date: 2022-04-25 19:39:46
 * @LastEditors: lyh
 * @LastEditTime: 2022-05-03 23:32:55
 */
#pragma once
#include <iostream>

#define OK 1
#define ERROR 0


typedef int Status; /* return type of function, OK 1  or ERROR*/

using namespace std;

template<typename ElemType>
class Sequential
{
private:
    /* data */
    ElemType* data;
    int capacity;/*initial allocation of storage space*/
    int size; /* current length*/

public:
    Sequential(int capa);
    ~Sequential();

    bool isEmpty();
    int getSize();
    int getCapacity();
    

    void insert(ElemType e, int pos);
    void listDelete(int pos);
    void getElem(ElemType&e, int num);/* require an element at the fixed index*/
    int findElem(ElemType e);/* if finded, return index*/

    Status clear();
    Status listVisit();
    
};


