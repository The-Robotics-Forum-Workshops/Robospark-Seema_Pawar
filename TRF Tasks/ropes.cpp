#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

class Queue {
    public :
        int front = -1,back=-1,arr[MAX];
        bool isEmpty();
        void enQueue(int x);
        void deQueue();
        int peek();
        int sizeQ();
};

bool Queue::isEmpty() {
    if (front==back) {
        return true;
    }
    else return false;
}

void Queue::enQueue(int x) {
    if (back==MAX) cout<<"Queue is full\n";
    else arr[++back] = x;
}

void Queue::deQueue() {
    if (this->isEmpty()) {
        cout<<"Queue is empty\n";
    }
    else front++;
}

int Queue::peek() {
    return arr[front+1];
}

int Queue::sizeQ() {
    return back-front;
}

int main() {
    Queue q;
    int n,i,res=0;
    cin>>n;
    int a[n];
    for (i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    for (i=0;i<n;i++) {
        q.enQueue(a[i]);
    }
    for (i=0;i<n;i++) {
        res+=q.peek();
        q.deQueue();
    }
    cout<<res;
}