#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    char  data;
    Node* next;

    Node(char d) {
        data = d;
        next = NULL;
    }
};

class CircularQueue {
private:
    Node* front;
    Node* rear;
    int length;
    int count;

public:
    CircularQueue() {
        front = NULL;
        rear = NULL;
        length = 7;
        count = 0;
    }

    bool isFull() {
        return (count == length);
    }

    bool isEmpty() {
        return (front == NULL && rear == NULL);
    }

    void enqueue(char data) {
        if (isFull()) {
            cout << "Queue is Full.\n" ;
            return;
        }
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
        rear->next = front;
        count++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is already empty\n";
            return;
        }
        cout << front->data << " is dequeued.\n";
        Node* temp = front;
        if (front == rear) {
            front = NULL;
            rear = NULL;
        }
        else {
            front = front->next;
            rear->next = front;
        }
        delete temp;
        count--;
    }

    void print() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        Node* current = front;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != front);
        cout << endl;
    }
};

signed main() {
    CircularQueue q;

    q.enqueue('A');
    q.enqueue('B');
    q.enqueue('C');
    q.print();
    q.dequeue();
    q.enqueue('D');
    q.dequeue();
    q.print();
    q.enqueue('E');
    q.enqueue('F');
    q.enqueue('G');
    q.enqueue('H');
    q.enqueue('I');
    q.enqueue('J');
    q.print();
}
