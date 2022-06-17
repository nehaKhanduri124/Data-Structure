#include<bits/stdc++.h>

using namespace std;

#define N 5
int Que[N];
int rear = -1;
int front = -1;

void EnQueue(){
    int item;
    if(rear == N-1){
        cout<<" Overflow! "<<endl;
    }
    else if(rear == -1 && front ==-1){
        cout<<"enter the data: ";
        cin>>item;
        rear = front = 0;
        Que[rear] = item;
    }
    else{
        cout<<"enter the data: ";
        cin>>item;
        rear++;
        Que[rear] = item;
    }
}

void DeQueue(){
    if(rear==-1 && front==-1){
        cout<<"Underflow!"<<endl;
    }
    else if(rear==front){
        rear = front = -1;
    }
    else{
        cout<<"Dequeue element is: "<<Que[front]<<endl;
        front++;
    }
}

void Peek(){
    if(rear==-1 && front==-1){
        cout<<"Underflow!"<<endl;
    }
    cout<<"Peek element is: "<<Que[front]<<endl;
}


void Display(){
    int temp = front;
    if(rear==-1 && front==-1){
        cout<<"Underflow!"<<endl;
    }
    else{
        while(temp<=rear){
            cout<<Que[temp]<<" ";
            temp++;
        }
        cout<<endl;
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
        cout<<" enter an option : ";
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
            Peek();
            cout<<endl;
            break;

        case 4:
            Display();
            cout<<endl;
            break;

        default:
            cout<<"please enter a correct choice"<<endl;
            cout<<endl;
            break;
        }
    }while(task!=0);

    return 0;
}
