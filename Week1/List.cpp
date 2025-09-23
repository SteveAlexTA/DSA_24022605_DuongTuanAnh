#include<bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 1000;
class List {
private:
    int data[MAX_SIZE];
    int size;
public:
    List() {
        size = 0;
    }
    //Truy cap: O(1)
    int getNode(int index) {
        if(index<0||index>=size) return -1;
        return data[index];
    }
    //Chen phan tu vao dau: O(n)
    void addHead(int val) {
        if(size>=MAX_SIZE) return;
        for(int i=size; i>0; i--) {
            data[i]=data[i-1];
        }
        data[0]=val;
        size++;
    }
    //Chen phan tu vao cuoi: O(1)
    void addTail(int val) {
        if(size>=MAX_SIZE) return;
        data[size]=val;
        size++;
    }
    //Chen phan tu vao vi tri i: O(n)
    void addIndex(int index, int val) {
        if(index<0||index>size||size>=MAX_SIZE) return;
        for(int i=size; i>index; i--) {
            data[i]=data[i-1];
        }
        data[index]=val;
        size++;
    }
    //Xoa dau: O(n)
    void deleteHead() {
        if(size==0) return;
        for(int i=0; i<size-1; i++){
            data[i]=data[i+1];
        }
        size--;
    }
    //Xoa cuoi: O(1)
    void deleteTail() {
        if(size==0) return;
        size--;
    }
    //Xoa tai i: O(n)
    void deleteIndex(int index) {
        if(index<0||index>=size) return;
        for(int i=index; i<size-1; i++) {
            data[i]=data[i+1];
        }
        size--;
    }
    //Duyet xuoi+nguoc: O(n)
    void printForward() {
        for(int i=0; i<size; i++) {
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }

    void printBackward() {
        for(int i=size-1; i>=0; i--) {
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
};

int main() {
    List l;
    l.addHead(1);      
    l.addHead(2);      
    l.addTail(10);     
    l.addTail(15);     
    l.addIndex(2,12); 
    cout << "Danh sach xuoi: ";
    l.printForward();
    cout << "Danh sach nguoc: ";
    l.printBackward();
    cout << "Phan tu thu 2: " << l.getNode(2) << endl;
    l.deleteHead();
    cout << "Sau khi xoa dau: ";
    l.printForward();
    l.deleteTail();
    cout << "Sau khi xoa cuoi: ";
    l.printForward();
    l.deleteIndex(1);
    cout << "Sau khi xoa vi tri 1: ";
    l.printForward();
}