#include<bits/stdc++.h>

using namespace std;

struct Node{
    int value;
    struct Node *link;
};

struct Node *front = 0;
struct Node *rear = 0;

void EnQueue(){
    int data;
    cout<<" enter the data: ";
    cin>>data;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = data;
    newNode->link =NULL;
    if(front == 0 && rear ==0){
        rear = newNode;
        front = newNode;
    }
    else{
        rear->link = newNode;
        rear = newNode;
    }
}

void DeQueue(){
    struct Node *item;
    if(front == 0 && rear == 0){
        cout<<" Underflow "<<endl;
    }
    else if(rear == front){
        cout<<"Dequeue element is: "<<front->value<<endl;
        rear = front =0;
    }
    else{
        item = front;
        cout<<"Dequeue element is: "<<front->value<<endl;
        front = front->link;
        free(item);
    }
}

void Peek_Queue(){
    if(front == 0 && rear == 0){
        cout<<" Underflow "<<endl;
    }
    else{
        cout<<"Peek element is: "<<front->value<<endl;
    }
}

void Display_Queue(){
    struct Node *temp = front;
    if(front == 0 && rear == 0){
        cout<<" Underflow "<<endl;
    }
    while(temp!=NULL){
        cout<<temp->value<<" ";
        temp = temp->link;
    }
}


int main(){
    int task;
    do{
        cout<<"1. Enqueue in queue"<<endl;
        cout<<"2. dequeue in a queue"<<endl;
        cout<<"3. peak in queue"<<endl;
        cout<<"4. Display The queue"<<endl;
        cout<<"0. For Exit"<<endl;
        cout<<"Enter an option : ";
        cin>>task;
        switch(task){
        case 0:
            break;
        case 1:
            EnQueue();
            cout<<endl;
            break;

        case 2:
            DeQueue();
            cout<<endl;
            break;

        case 3:
            Peek_Queue();
            cout<<endl;
            break;

        case 4:
            Display_Queue();
            cout<<endl;
            break;

        default:
            cout<<"please enter the correct option"<<endl;
            cout<<endl;
            break;
        }
    }while(task!=0);

    return 0;
}
