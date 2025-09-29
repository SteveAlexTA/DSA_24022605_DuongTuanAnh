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

    int getSize() {
        return size;
    }
};

class Stack {
private:
    List list;
public:
    bool isEmpty() {
        return list.getSize() == 0;
    }
    //Them cuoi + xoa cuoi: O(1)
    void push(int item) {
        list.addTail(item);
    } 

    int pop() {
        if(isEmpty()) {
            return -1;
        }
        int val=list.getNode(list.getSize()-1);
        list.deleteTail();
        return val;
    }

    int top() {
        if(isEmpty()) {
            return -1;
        }
        int val=list.getNode(list.getSize()-1);
        return val;
    }

    int size() {
        return list.getSize();
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
    cout<<"Phan tu cuoi (last in) bi xoa la: "<<val1<<endl;
    cout<<"Phan tu cuoi stack sau khi xoa la: "<<val2<<endl;
    cout<<"Kich thuoc stack sau khi xoa la: "<<val3<<endl;
}


