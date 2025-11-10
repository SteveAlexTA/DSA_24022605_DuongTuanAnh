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
        Node* curr = htable[index];
        Node* prev = nullptr;
        while (curr && curr->key != key) { 
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr) {
            return;
        }
        if (prev == nullptr) { 
            htable[index] = curr->next;
        } else {
            prev->next = curr->next;
        }
        delete curr;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            Node* curr = htable[i];
            while (curr) {
                cout << curr->key << " -> ";
                curr = curr->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    HashTable ht(5); 
    ht.insert(1);
    ht.insert(8);
    ht.insert(13);
    ht.insert(29);

    cout << "Initial Hash Table:" << endl;
    ht.print();

    cout << "\nRemove 8:" << endl;
    ht.remove(8);
    ht.print();

    cout << "\nRemove 100:" << endl;
    ht.remove(100);
    ht.print();

    cout << "\nRemove 1:" << endl;
    ht.remove(1);
    ht.print();

    return 0;
}