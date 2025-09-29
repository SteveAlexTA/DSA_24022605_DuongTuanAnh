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

class Stack {
private:
    LinkedList llist;
public:
    bool isEmpty() {
        return llist.isEmpty();
    }
    //Them head + xoa head: O(1)
    void push(int item) {
        llist.addHead(item);
    }

    int pop() {
        if(isEmpty()) {
            return -1;
        }
        int val=llist.getNode(0);
        llist.deleteHead();
        return val;
    }

    int top() {
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
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    int val0 = s.size();
    cout<<"Kich thuoc stack ban dau la: "<<val0<<endl;
    int val1 = s.pop();
    int val2 = s.top();
    int val3 = s.size();
    cout<<"Phan tu dau (last in) bi xoa la: "<<val1<<endl;
    cout<<"Phan tu dau stack sau khi xoa la: "<<val2<<endl;
    cout<<"Kich thuoc stack sau khi xoa la: "<<val3<<endl;
}


