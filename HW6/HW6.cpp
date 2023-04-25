#include <bits/stdc++.h>
using namespace std;
struct node
{
    int x;
    struct node* next;
};


void freeList(node* n);
node* insert(node* n, int x);
node* createList(int* a, int b);
void printList(node* n);

signed main()
{
    node*  first;
    int arr[] = {14,27,32,46};
    first = createList(arr,4);
    printList(first);

    int data = 38;
    first = insert(first,data);
    printList(first);
    freeList(first);

}

node* createList(int* a, int b)
{
    node* current, *begin, *previous;
    for(int i = 0; i < b; i++){
        current = new node;
        current->x = a[i];
        if(i == 0) begin = current;
        else previous->next = current;
        current->next = NULL;
        previous = current;
    }

    return begin;
}

void freeList(node* n)
{
    node* curr;
    while(n)
    {
        curr = n;
        n = n->next;
        delete curr;
    }
}
node* insert(node* n,int data)
{
    node* curr = n, *pre = NULL, *tmp = new node;
    tmp->x = data;
    tmp->next = NULL;
    if(!n || data < n->x){
        tmp->next = n;
        return tmp;
    }
    while(curr && curr->x < data){
        pre = curr;
        curr = curr->next;
    }
    pre->next = tmp;
    tmp->next = curr;
    return n;
}

void printList(node* n)
{
    while(n){
        cout << n->x << " ";
        n = n->next;
    }
    cout << "\n";
}
