#include<bits/stdc++.h>

#define N 5
int stacK[N];
int head = -1;

using namespace std;

int push(){
    int value;
    if(head==N-1){
        cout<<" stack Overflow!"<<endl;
    }
    else{
        cout<<"enter the data: ";
        cin>>value;
        head++;
        stacK[head] = value;
    }
    return 0;
}

int pop(){
    int item;
    if(head == -1){
        cout<<"stack underflow"<<endl;
    }
    else{
        item = stacK[head];
        head--;
        cout<<"popped element is: "<<item<<endl;
    }
    return 0;
}

int topElement(){
    if(head == -1){
        cout<<"underflow"<<endl;
    }
    else{
        cout<<stacK[head]<<endl;
    }
    return 0;
}

int printStack(){
    if(head == -1){
        cout<<"stack is empty"<<endl;
    }
    else{
        for(int i=0;i<=head;i++){
            cout<<stacK[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

int main(){
    int task;
    do{
        cout<<"1. Push in stack"<<endl;
        cout<<"2. Pop in a stack"<<endl;
        cout<<"3. peak in stack"<<endl;
        cout<<"4. Display The stack"<<endl;
        cout<<"0. For Exit"<<endl;
        cout<<"enter the options: ";
        cin>>task;
        switch(task){
        case 0:
            break;
        case 1:
            push();
            cout<<endl;
            break;

        case 2:
            pop();
            cout<<endl;
            break;

        case 3:
            topElement();
            cout<<endl;
            break;

        case 4:
            printStack();
            cout<<endl;
            break;

        default:
            cout<<"please enter correct option"<<endl;
            cout<<endl;
            break;
        }
    }while(task!=0);

    return 0;
}


