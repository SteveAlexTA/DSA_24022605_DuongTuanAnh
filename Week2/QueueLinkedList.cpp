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
    bool isEmpty() {
        return head==nullptr;
    }
    int getSize() {
        Node *q = head;
        int count = 0;
        while(q) {
            q=q->next;
            count++;
        } 
        return count;
    }
};

class Queue {
private:
    LinkedList llist;
public:
    bool isEmpty() {
        return llist.isEmpty();
    }

    void enqueue(int item) {
        llist.addTail(item);
    }

    int dequeue() {
        if(isEmpty()) {
            return -1;
        }
        int val=llist.getNode(0);
        llist.deleteHead();
        return val;
    }

    int front() {
        if(isEmpty()) {
            return -1;
        }
        int val=llist.getNode(0);
        return val;
    }

    int size() {
        return llist.getSize();
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    int val0 = q.size();
    cout<<"Kich thuoc queue ban dau la: "<<val0<<endl;
    int val1 = q.dequeue();
    int val2 = q.front();
    int val3 = q.size();
    cout<<"Phan tu dau bi xoa la: "<<val1<<endl;
    cout<<"Phan tu dau queue sau khi xoa la: "<<val2<<endl;
    cout<<"Kich thuoc queue sau khi xoa la: "<<val3<<endl;
}
