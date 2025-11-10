#include<bits/stdc++.h>
using namespace std;

class HashTable {
private:
    struct Node {
        int key;
        Node* next;
        Node(int k): key(k), next(nullptr) {}
    };
    int size;
    Node** htable;
public:
    HashTable(int s) { // Constructor
        size = s;
        htable = new Node*[size];
        for (int i = 0; i < size; i++) {
            htable[i] = nullptr;
        }
    }

    ~HashTable() { // Destructor to free up memory
        for (int i = 0; i < size; i++) {
            Node* q = htable[i];
            while (q != nullptr) {
                Node* temp = q;
                q = q->next;
                delete temp;
            }
        }
        delete[] htable;
    }

    int hashFunc(int key) {
        return key % size;
    }

    void insert(int key) { // O(1)
        int index = hashFunc(key);
        Node* new_node = new Node(key);
        if (htable[index] == nullptr) {
            htable[index] = new_node;
        } else {
            new_node->next = htable[index];
            htable[index] = new_node;
        }
    }

    void remove(int key) { // O(n)
        int index = hashFunc(key);
        Node* cur = htable[index];
        Node* prev = nullptr;
        while (cur != nullptr) {
            if (cur->key == key) {
                if (prev == nullptr) {
                    htable[index] = cur->next;
                } else {
                    prev->next = cur->next;
                }
                delete cur;
                return;
            }
        }
        prev = cur;
        cur = cur->next;
    }
}