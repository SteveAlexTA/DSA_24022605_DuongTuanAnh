#include<bits/stdc++.h>
using namespace std;

class LinkedList {
private:
    Node* head;
    struct Node {
        int val;
        Node* next;
        Node(int v): val(v), next(nullptr) {}
    }
public:
    LinkedList() { head == nullptr; }
    
}