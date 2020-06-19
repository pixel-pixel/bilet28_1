#include <iostream>

using namespace std;

/*Білет 9 завд 1
 * 2 відсортовані зв'зні списки
 * злити і повернути один відсортований
 * */

struct Node{
    int number = 0;
    Node* next = nullptr;

    Node(int n){
        number = n;
    }
};

struct List{
    Node* head = nullptr;
    int size = 0;

    void add(int n){
        if(head == nullptr){
            head = new Node(n);
        }else{
           Node* ptr = head;

           while (ptr->next != nullptr) ptr = ptr->next;

           ptr->next = new Node(n);
        }

        size++;
    }

//    void print(){
//        Node* ptr = head;
//        for(int i = 0; i < size; i++){
//            cout << ptr->number << endl;
//            ptr = ptr->next;
//        }
//    }
};


List* twoToOne(List* n, List* m){
    List* result = new List;
    Node* nPtr = n->head;
    Node* mPtr = m->head;

    while (nPtr != nullptr && mPtr != nullptr){
        if(nPtr->number < mPtr->number){
            result->add(nPtr->number);
            nPtr = nPtr->next;
        }else{
            result->add(mPtr->number);
            mPtr = mPtr->next;
        }
    }
    while (nPtr != nullptr){
        result->add(nPtr->number);
        nPtr = nPtr->next;
    }
    while (mPtr != nullptr){
        result->add(mPtr->number);
        mPtr = mPtr->next;
    }
    return result;
}


//int main() {
//    List f;
//    f.add(1);
//    f.add(2);
//    f.add(4);
//    List s;
//    s.add(2);
//    s.add(3);
//    s.add(5);
//
//    List* r = twoToOne(&f, &s);
//    r->print();
//
//    return 0;
//}
