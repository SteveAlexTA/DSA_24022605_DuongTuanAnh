#include<bits/stdc++.h>
using namespace std;

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val): data(val), next(nullptr){}
    };
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }
    //Truy cap phan tu: O(n)
    int getNode(int index) {
        Node* q = head;
        for(int i=0; i<index; i++) {
            q=q->next;
        }
        if(q==nullptr) return -1;
        return q->data;
    }
    //Chen phan tu vao dau: O(1)
    void addHead(int val) {
        Node* new_node = new Node(val);
        new_node->next = head;
        head = new_node;
    }
    //Chen phan tu vao cuoi: O(n)
    void addTail(int val) {
        Node* new_node = new Node(val);
        if(head==nullptr) {
            head = new_node;
            return;
        }
        Node* q = head;
        while(q->next) {
            q=q->next;
        }
        q->next = new_node;
    }
    //Chen vao vi tri i: O(n)
    void addAtIndex(int index, int val) {
        if(index<0) return;
        if(index==0) {
            addHead(val);
            return;
        }
        Node*new_node = new Node(val);
        Node*q = head;
        for(int i=0; i<index-1; i++) {
            q=q->next;
        }
        if(q==nullptr) return;
        new_node->next = q->next;
        q->next = new_node;
    } 
    //Xoa dau: O(1)
    void deleteHead() {
        Node*temp = head;
        head = head->next;
        delete temp;
    }
    //Xoa vi tri i: O(n)
    void deleteAtIndex(int index) {
        if(index<0) return;
        if(index==0) {
            deleteHead();
            return;
        } 
        Node*q = head;
        for(int i=0; i<index-1; i++) {
            q=q->next;
        }
        if(q==nullptr) return;
        Node*temp = q->next;
        q->next = temp->next;
        delete temp;
    }
    //Duyet xuoi + nguoc: O(n)
    void printForward() {
        Node* q = head;
        while(q) {
            cout<<q->data<<" ";
            q=q->next;
        }
        cout<<endl;
    }
    void reverseList(Node* q) {
        if(q==nullptr) return;
        reverseList(q->next);
        cout<<q->data<<" ";
    }
    void printBackward() {
        reverseList(head);
        cout<<endl;
    }
};

int main() {
    LinkedList l;
    l.addHead(7);       
    l.addHead(6);       
    l.addTail(10);      
    l.addTail(15);      
    l.addAtIndex(2,12);
    cout << "Danh sach xuoi: ";
    l.printForward();
    cout << "Danh sach nguoc: ";
    l.printBackward();
    cout << "2th node: " << l.getNode(2) << endl;
    l.deleteAtIndex(2); 
    l.deleteHead();     
    cout << "Danh sach sau khi xoa: ";
    l.printForward();   
}
