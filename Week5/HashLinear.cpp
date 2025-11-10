#include<bits/stdc++.h>
using namespace std;

class HashTable {
private:
    int size;
    int *htable;
public:
    // Constructor
    HashTable(int s) {
        size = s;
        htable = new int[size];
        for (int i = 0; i < size; i++) {
            htable[i] = -1;
        }
    }

    // Destructor
    ~HashTable() {
        delete[] htable;
    }

    int hashFunc(int key) {
        return key % size;
    }

    void insert(int key) { // O(1)
        int index = hashFunc(key);
        while (htable[index] != -1) {
            index = (index + 1) % size;
        }
        htable[index] = key;
    } 

    void print() { // O(n)
        for (int i = 0; i < size; i++) {
            cout << i << ": " << htable[i] << endl;
            
        }
    }
};

int main() {
    HashTable ht(5);
    ht.insert(1);
    ht.insert(2);
    ht.insert(67);
    ht.insert(13);

    cout << "Hash Table: " << endl;
    ht.print();
}