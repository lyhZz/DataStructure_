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
    this -> head = nullptr;
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
    int index = 1;
    while(!pCurrent){
        if(pCurrent -> data == e) break;
        pCurrent = pCurrent -> next;
        index++;
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
    if(pos == this -> length){// tail in
        Node* pCurrent = this -> head -> next;
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
    }
    cout << "\n";
}

int main(int argc, char** aargv){
    
    return 0;
}

