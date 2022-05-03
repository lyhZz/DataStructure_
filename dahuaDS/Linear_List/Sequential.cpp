/*
 * @Description: 
 * @Version: 1.0
 * @Autor: lyh
 * @Date: 2022-05-03 20:41:37
 * @LastEditors: lyh
 * @LastEditTime: 2022-05-03 23:41:34
 */

#include "Sequential.h"

template<typename ElemType>
Sequential<ElemType>::Sequential(int capa)
:capacity(capa), size(0){
    this->data = new ElemType[capa];
}

template<typename ElemType>
Sequential<ElemType>::~Sequential(){
    if(this->data != nullptr){
        delete[] this->data;
        this->data = nullptr;
    }
    this->capacity = 0;
    this->size = 0;
}

template<typename ElemType>
bool Sequential<ElemType>::isEmpty(){
    return this->size == 0;
}

template<typename ElemType>
int Sequential<ElemType>::getSize(){
    return this->size;
}

template<typename ElemType>
int Sequential<ElemType>::getCapacity(){
    return this->capacity;
}

template<typename ElemType>
void Sequential<ElemType>::insert(ElemType e, int pos){ // pos start from 0
    /*judege isfull, true return error, else insert, size+1*/
    if(this->size == this->capacity){
        cout << "the list is full now..." << endl;
    }
    if(pos < 0 || pos > this->size){
        cout << "the pos is wrong..." << endl;
    }
    int i;
    if(pos >= 0 && pos < this -> size){ /* no in list tail*/
        for(i = this->size - 1; i >= pos; i--){
            this->data[i + 1] = this->data[i];
        }
    }
    this->data[pos] = e;
    this->size++;
}

template<typename ElemType>
void Sequential<ElemType>::listDelete(int pos){
    if(this->size == 0){
        cout << "the list is empty, nothing to be deleted..." << endl;
    }
    if(pos < 0 || pos >= this->size){
        cout << "the pos is wrong..." << endl;
    }
    if(pos == this->size - 1){
        
    }
    else{
        for(int i = pos; i < this->size - 1; i++){
            data[i] = data[i + 1];
        }
    }
    this->size--;
}

template<typename ElemType>
void  Sequential<ElemType>::getElem(ElemType& e, int num){/* require an element at the fixed index*/
    if(this->size == 0){
        cout << "this is a empty list" << endl;
    }
    if(num < 0 || num >= this->size){
        cout << "the index is wrong, please check again..." << endl;
    }
    e = data[num];
}

template<typename ElemType>
int Sequential<ElemType>::findElem(ElemType e){/* if finded, return index*/
    if(this->size == 0) return -1;
    int i;
    int ans = -1;
    for(i = 0; i < this->size; i++){
        if(data[i] == e){//basic type, if elemtype is class, need override ==*/
            ans = i;
            break;
        }
    }
    return ans;
}
template<typename ElemType>
Status Sequential<ElemType>::clear(){
    this->size =0;
    return OK;
}

template<typename ElemType>
Status Sequential<ElemType>::listVisit(){
    for(int i = 0; i < this->size; i++){
        cout << this->data[i] << " ";
    }
    cout << endl;
    return OK;
}


int main(int argc, char** argv){
    Sequential<int> list1(10);
    cout << "after initing the L, the capacity of L is: " <<  list1.getCapacity() << endl;
    for(int i = 0; i < 5; i++){
        list1.insert(i + 1, i);
    }
    cout << "after inserting,  L(capacity, size)) is: (" << list1.getCapacity() << ", "<< list1.getSize() << "):  ";
    list1.listVisit();

    cout << "after inserting, the L is empty? " << list1.isEmpty() << endl;
    list1.clear();
    cout << "after clearing, the L is empty? " << list1.isEmpty() << endl;

    for(int i = 0; i < 7; i++){
        list1.insert(i, i);
    }
    cout << "after inserting,  L(capacity, size)) is: (" << list1.getCapacity() << ", "<< list1.getSize() << "):  ";
    list1.listVisit();

    list1.insert(10, 0);
    cout << "after inserting,  L(capacity, size)) is: (" << list1.getCapacity() << ", "<< list1.getSize() << "):  ";
    list1.listVisit();
    
    int num = 5;
    int getEleTest;
    list1.getElem(getEleTest, num);
    cout << "the " << num << "th element is: " <<  getEleTest << endl;

    int findEleTest = list1.findElem(getEleTest);
    cout << "the location of " << getEleTest << "is: " << findEleTest << endl;

    list1.listDelete(num);
    cout << "after deleting,  L(capacity, size)) is: (" << list1.getCapacity() << ", "<< list1.getSize() << "):  ";
    list1.listVisit();
    int findEleTest_2 = list1.findElem(getEleTest);
    cout << "the location of " << getEleTest << " is: " << findEleTest_2 << endl;

    return 0;
}

