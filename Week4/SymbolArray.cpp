#include<bits/stdc++.h>
using namespace std;

class SymbolTable {
private:
    struct Map {
        string key;
        int value;
    };
    Map table[100];
    int n;
public:
    SymbolTable() {n = 0;}

    void put(string key, int value) { // Them & cap nhat cap key-value O(n)
        if (n >= 100) {
            return;
        }
        for (int i = 0; i < n; i++) {
            if (table[i].key == key) {
                table[i].value = value;
                return;
            }
        }
        table[n].key = key;
        table[n].value = value;
        n++;
    }

    int get(string key) { // Lay gia tri theo key O(n)
        for (int i = 0; i < n; i++) {
            if (table[i].key == key) {
                return table[i].value;
            } 
        }
        return -1;
    }

    void remove(string key) {
        for (int i = 0; i < n; i++) {
            if (table[i].key == key) {
                table[i] = table[n-1];
                n--;
                return;
            }
        }
    }

    void printTable() {
        for (int i = 0; i < n; i++) {
            cout << "Key: " << table[i].key << " - Value: " << table[i].value << endl;
        }
    }

    int getSize() {
        return n;
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
