#include<iostream>
#include<vector>
#include<string>
using namespace std;

class HashTable {
private:
    class Node {
    public:
        string data;
        Node* next;
        Node(string s): data(s), next(nullptr) {}
    };
    int size;
    Node** htable;
    /*
    void deepCopyTable(const HashTable& other) {
        size = other.size;
        htable = new Node*[size];
        if (other.htable != nullptr) {
            htable = new HashTable[size];
            for (int i = 0; i < size; i++) {
                htable[i] = other.htable[i];
            }
        }
    }
    */

    void deleteTable() {
        for (int i = 0; i < size; i++) {
            Node* q = htable[i];
            while (q != nullptr) {
                Node*tmp = q;
                q = q->next;
                delete tmp;
            }
            htable[i] = nullptr;
        }
        delete[] htable;
    }

public:
    HashTable(int s) { // Constructor
        size = s;
        htable = new Node*[size];
        for (int i = 0; i < size; i++) {
            htable[i] = nullptr;
        }
    }

    ~HashTable() { // Destructor 
        deleteTable();
    }

    /*
    HashTable& operator=(const HashTable& htable) {
        if (this != &htable) {
            deleteTable();
            deepCopyTable(htable);
        }
        return *this;
    }
    */
    int hashFunc(const string& key) const {
        int num = 0;
        for (char c: key) {
            num += c;
        }
        return num % size;
    }

    bool search(const string& s) const {
        int index = hashFunc(s);
        Node* temp = htable[index];
        while (temp != nullptr) {
            if (temp->data == s) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    bool insert(const string& s) { // O(1)
        if (search(s)) {
            return false;
        } 
        int index = hashFunc(s);
        Node* new_node = new Node(s);
        if (htable[index] == nullptr) {
            htable[index] = new_node;
        } else {
            new_node->next = htable[index];
            htable[index] = new_node;
        }
        return true;
    }

    bool remove(const string& s) { // O(n)
        int index = hashFunc(s);
        Node* curr = htable[index];
        Node* prev = nullptr;
        while (curr && curr->data != s) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr) {
            return false;
        }
        if (prev == nullptr) {
            htable[index] = curr->next;
        } else {
            prev->next = curr->next;
        }
        delete curr;
        return true;
    }

    void print() const { // O(n)
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            Node* curr = htable[i];
            while (curr) {
                cout << curr->data << " -> ";
                curr = curr->next;
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht(5); 
    ht.insert("1");
    ht.insert("8");
    ht.insert("13");
    ht.insert("29");
    ht.insert("abcd");

    cout << "Initialize Hash Table:" << endl;
    ht.print();

    cout << "\nRemove 8:" << endl;
    ht.remove("8");
    ht.print();

    cout << "\nRemove 100:" << endl;
    ht.remove("100");
    ht.print();

    cout << "\nRemove 1:" << endl;
    ht.remove("1");
    ht.print();

    return 0;
}
