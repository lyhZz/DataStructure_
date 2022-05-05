#include "LinkedList.h"


template<typename ElemType>
LinkedList<ElemType>::LinkedList()
: length(0){
    this->head = (Node*)malloc(sizeof(Node));
    if(!head){
        cout << "init linked list failed..." << endl;
    }
    cout << "init succeed..." << endl;
    this->head->next = nullptr;
}

template<typename ElemType>
LinkedList<ElemType>::~LinkedList(){
    Node* current = this->head;
    while(current != nullptr){
        Node* nodeTmp = current;
        current = current -> next;
        delete nodeTmp;
    }
}

template<typename ElemType>
bool LinkedList<ElemType>::isEmpty(){
    return this->length == 0;
}

template<typename ElemType>
void LinkedList<ElemType>::clear(){
    if(head -> next == nullptr){
        cout << "the list is already empty..." << endl;
        return;
    }
    Node* pCurrent = this -> head -> next;
    while (pCurrent != nullptr)
    {
        Node* pTmp = pCurrent;
        pCurrent = pCurrent -> next;
        free(pTmp);
    }
    this -> head -> next= nullptr;
    this -> length = 0;
}

template<typename ElemType>
int LinkedList<ElemType>::getLength(){
    return this -> length;
}

template<typename ElemType>
void LinkedList<ElemType>::getElem(int pos, ElemType& e){// start from 0
    if(isEmpty()){
        cout << "the list is empty..." << endl;
        return;
    }
    Node* pCurrent = this -> head -> next;
    for(int i = 0; i < pos && pCurrent != nullptr; i++){
        pCurrent = pCurrent -> next;
    }
    if(pCurrent != nullptr)
        e = pCurrent -> data;
    else
        cout << "the pos is wrong..." << endl;
}

template<typename ElemType>
int LinkedList<ElemType>::locateElem(ElemType e){
    if(!this -> head){
        cout << "the list is empty..." << endl;
        return -1;
    }
    Node* pCurrent = this -> head -> next;
    int index = 0;
    while(pCurrent){
        if(pCurrent -> data == e) break;
        pCurrent = pCurrent -> next;
        index++;
    }
    if(!pCurrent){
        cout << "mo " << e << " in the list..." << endl;
        index = -1;
    }
    return index;
}

template<typename ElemType>
void LinkedList<ElemType>::insertList(int pos, ElemType e){
    if(pos < 0 || pos > this -> length){
        cout << "the pos is wrong...[0," << length << "]" << endl;
        return;
    }
    Node* pNew = (Node*)malloc(sizeof(Node));
    pNew -> data = e;
    pNew -> next = nullptr;
    if(this->isEmpty()){
        this->head->next = pNew;
        this -> length++;
        return;
    }
    if(pos == this -> length){// tail in
        Node* pCurrent = this -> head;
        for(int i = 0; i < this->length; i++){
            pCurrent = pCurrent -> next;
        }
        pCurrent -> next = pNew;
        this -> length++;
        return;
    }
    else{
        Node* slow = this -> head;
        Node* fast = this -> head -> next;
        for(int i = 0; i < pos; i++){
            slow = slow -> next;
            fast = fast -> next;
        }
        pNew -> next = slow -> next;
        slow -> next = pNew;
        this -> length++;
    } 
    
} // insert before pos

template<typename ElemType>
void LinkedList<ElemType>::deleteList(int pos, ElemType& e){
    if(isEmpty()){
        cout << "the list is empty..." << endl;
        return;
    }
    if(pos < 0 || pos >= this -> length){
        cout << "the pos is wrong...[0," << length << ")" << endl;
        return;
    }
    Node* slow = this -> head;
    Node* fast = this -> head -> next;
    for(int i = 0; i < pos; i++){
        slow = slow -> next;
        fast = fast -> next;
    }
    // if(fast -> next == nullptr){//tail
    //     slow -> next = nullptr;
    //     free(fast);
    //     this->length--;
    // }
    // else{
    //     slow -> next = fast -> next;
    //     free(fast);
    // }
    slow -> next = fast -> next;
    free(fast);
    this -> length--;
}


template<typename ElemType>
void LinkedList<ElemType>::createListHead(int n){// reverse order
    srand(time(0));
    for(int i = 0; i < n; i++){
        // insertList(0, (ElemType)(rand()%100 + 1));
        Node* pNew = (Node*)malloc(sizeof(Node));
        pNew -> data = (ElemType)(rand()%100 + 1);
        pNew -> next = this->head->next;
        this->head->next = pNew;
        this -> length++;
    }
}

template<typename ElemType>
void LinkedList<ElemType>::visit(){
    if(isEmpty()){
        cout << "the list is empty..." << endl;
        return;
    }
    Node* pCurrent = this->head->next;
    cout << "the data of linked list is: " ;
    while(pCurrent != nullptr){
        cout << pCurrent->data << " ";
        pCurrent = pCurrent -> next;
    }
    cout << "\n";
}

int main(int argc, char** aargv){
    LinkedList<int> list1;
    cout << "after initing the L, the length of L is: " <<  list1.getLength() << endl;
    for(int i = 0; i <= 5; i++){
        /* head in 6 elements*/
        list1.insertList(0, i);
    }
    cout << "after inserting,  L's length is: " << list1.getLength()<< "  the data is: ";
    list1.visit();

    cout << "after inserting, the L is empty? " << list1.isEmpty() << endl;
    list1.clear();
    cout << "after clearing, the L is empty? " << list1.isEmpty() << endl;

    for(int i = 0; i < 7; i++){
        /*tail in 8 elements*/
        list1.insertList(list1.getLength(), i);
    }
    cout << "after inserting,  L's length is: " << list1.getLength()<< "  the data is: ";
    list1.visit();

    list1.insertList(0, 7);
    cout << "after inserting,  L's length is: " << list1.getLength()<< "  the data is: ";
    list1.visit();
    
    int num = 5;
    int getEleTest;
    list1.getElem(num, getEleTest);
    cout << "the " << num << "th element is: " <<  getEleTest << endl;

    int findEleTest = list1.locateElem(getEleTest);
    cout << "the location of " << getEleTest << " is: " << findEleTest << endl;

    int deleteElemTest = -1;
    list1.deleteList(num, deleteElemTest);
    if(deleteElemTest != -1){
        cout << "has deleted " << num << "th element that is " << deleteElemTest << endl;
    }
    cout << "after deleting,  L's length is: " << list1.getLength()<< "  the data is: ";
    list1.visit();
    int findEleTest_2 = list1.locateElem(getEleTest);
    cout << "the location of " << getEleTest << " is: " << findEleTest_2 << endl;

    cout << "----------------head in linked list----------------------" << endl;
    LinkedList<int> list2;
    list2.createListHead(10);
    cout << "after random init,  L's length is: " << list2.getLength()<< "  the data is: ";
    list2.visit();

    system("PAUSE");
    return 0;
}

