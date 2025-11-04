#include<bits/stdc++.h>
using namespace std;

class SymbolTable {
private:
    struct Node {
        string key;
        int value;
        Node* next;
        Node(string k, int v): key(k), value(v), next(nullptr) {}
    };
    Node* head;
public:
    SymbolTable() { head = nullptr; }
    
    void put(string key, int value) { // Them & cap nhat 1 cap key-value O(n)
        Node *q = head;
        while (q) {
            if (q->key == key) {
                q->value = value;
                return;
            }
            q = q->next;
        }
        Node* new_node = new Node(key, value);
        new_node->next = head;
        head = new_node;
    }

    int get(string key) { // Lay gia tri theo key O(n)
        Node*q = head;
        while (q) {
            if (q->key == key) {
                return q->value;
            }
            q = q->next;
        }
        return -1;
    }

    void remove(string key) { // Xoa key O(n)
        if (!head) return;
        if (head->key == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* q = head;
        while (q->next) {
            if (q->next->key == key) {
                Node* temp = q->next;
                q->next = temp->next;
                delete temp;
                return;
            }
            q = q->next;
        }
    }

    int getSize() { // Dem phan tu O(n)
        int count = 0;
        Node* q = head;
        while (q) {
            count++;
            q = q->next;
        }
        return count;
    }

    void printTable() {
        Node* q = head;
        cout << "Symbol Table:\n";
        while (q) {
            cout << "Key: " << q->key << " - Value: " << q->value << endl;
            q = q->next;
        }
    }

    bool isEmpty() {
        return head == nullptr;
    }
};

int main() {
    SymbolTable st; 
    st.put("A", 10);
    st.put("B", 20);
    st.put("C", 30);

    st.put("B", 25);

    cout << "Value of A: " << st.get("A") << endl;
    cout << "Value of B: " << st.get("B") << endl;
    cout << "Value of D (not exist): " << st.get("D") << endl;

    cout << "\nSymbol Table:\n";
    st.printTable();

    st.remove("B");
    cout << "\nAfter removing B:\n";
    st.printTable();

    cout << "\nSize: " << st.getSize() << endl;
}