#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node *link;
};

struct Node *head=0;

void push_stack(){
    int value;
    cout<<"enter the data: ";
    cin>>value;
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->link = head;
    head = new_node;
}

void pop_stack(){
    struct Node *temp = head;
    if(head == 0){
        cout<<"Underflow!"<<endl;
    }
    else{
        cout<<"popped element is: "<<head->data;
        head = head->link;
        free(temp);
    }
    cout<<endl;
}

void peek_stack(){
    if(head == 0){
        cout<<"Underflow!"<<endl;
    }
    else{
        cout<<"Peek element is : "<<head->data<<endl;
    }
}
void display(){
    struct Node *temp = head;
    if(head == 0){
        cout<<"Underflow!"<<endl;
    }
    else{
        while(temp!=0){
            cout<<temp->data<<" ";
            temp = temp->link;
        }
        cout<<endl;
    }
}

int main(){
    int task;
    do{
        cout<<"1. Push in stack"<<endl;
        cout<<"2. Pop in a stack"<<endl;
        cout<<"3. peak in stack"<<endl;
        cout<<"4. Display The stack"<<endl;
        cout<<"0. For Exit"<<endl;
        cout<<" enter the option : ";
        cin>>task;
        switch(task){
        case 0:
            break;
        case 1:
            push_stack();
            cout<<endl;
            break;

        case 2:
            pop_stack();
            cout<<endl;
            break;

        case 3:
            peek_stack();
            cout<<endl;
            break;

        case 4:
            display();
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
