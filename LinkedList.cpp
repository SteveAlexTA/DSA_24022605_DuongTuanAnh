#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val): data(val), next(nullptr) {}
};

Node* head = nullptr;

//Ham truy cap: O(n)
int getNode(int index) {
    Node*q = head;
    for (int i=0; i<index; i++) {
        q=q->next;
    }
    if(q == nullptr) return -1;
    return q->data;
}
//Chen phan tu vao dau: O(1)
void addHead(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}
//Chen phan tu vao cuoi: O(n)
void addTail(int data) {
    Node* newNode = new Node(data);
    if(!head) {
        head = newNode;
        return;
    }
    Node*q = head;
    while(q->next) {
        q=q->next;
    }
    q->next = newNode;
}
//Chen vao vi tri i: O(n)
void addIndex(int index, int data) {
    if(index<0) return;
    if(index==0) {
        addHead(data);
        return;
    }
    Node* newNode = new Node(data);
    Node* q = head;
    for(int i=0; i<index-1; i++) {
        q=q->next;
    }
    if(q == nullptr) return;
    newNode->next = q->next;
    q->next = newNode;
}
//Xoa vi tri i: O(n)
void deleteIndex(int index) {
    if(index<0||head==nullptr) return;
    if(index==0) {
        Node*q = head;
        head = head->next;
        delete q;
        return;
    }
    Node* q = head;
    for(int i=0; i<index-1; i++) {
        q=q->next;
    }
    if(q->next==nullptr) return;
    Node* temp = q->next;
    q->next = temp->next;
    delete temp;
}
//Duyet xuoi: O(n)
void printForward() {
    Node*q = head;
    while(q) {
        cout << q->data << " ";
        q=q->next;
    }
    cout<<endl;
}
//Duyet nguoc: O(n)
void printBackward(Node* q) {
    if (!q) return;
    printBackward(q->next);
    cout << q->data << " ";
}

int main() {
    addHead(1);
    addHead(2);
    addTail(10);
    addTail(15);
    addIndex(2,12);
    cout << "Danh sach xuoi: ";
    printForward();
    cout<<endl;
    cout << "2th node: " << getNode(2); 
    deleteIndex(2);
    cout<<endl;
    cout << "Danh sach sau khi xoa: ";
    printForward();
    cout << "Danh sach nguoc: ";
    printBackward(head);
    cout << endl;
}