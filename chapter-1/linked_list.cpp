#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Node{
    int value;
    struct Node *link;
};
int flag;

struct Node * insrt_Element(struct Node *head){
    struct Node *newNode,*ptr;
    int value;
    cout<<"enter the value: ";
    cin>>value;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = value;
    if(head==NULL){
        newNode->link=NULL;
        head = newNode;
        cout<<"Linked List Created"<<endl;
    }
    else{
        ptr = head;
        while(ptr->link!=NULL){
            ptr= ptr->link;
        }
        ptr->link = newNode;
        newNode->link = NULL;
    }
    flag++;
    return head;
};

struct Node * dlt_Element(struct Node * head,int position){
    struct Node *p = head;
    struct Node *temp;

    if(p==NULL){
        cout<<"list is empty!! "<<endl;
    }
    else if(position==1){
        head = p->link;
        flag--;
    }
    else if(position>flag){
        cout<<"enough elements are not present"<<endl;
    }
    else{
        for(int i=1;i<position;i++){
            if(p!=NULL){
                temp = p;
                p = p->link;
            }
        }
        temp->link= temp->link->link;
        free(p);
        flag--;
    }
    return head;
};


void display(struct Node *head){
    struct Node *p=head;
    if(p==NULL){
        cout<<"empty list!"<<endl;
    }
    else{
         cout<<"Element are : ";
        while(p!=NULL){
            cout<<p->value<<" ";
            p = p->link;
        }
    }
    cout<<endl;
}


int main(){
    struct Node *head = NULL;
    int task;
    do{
        cout<<"1. Insert New Element"<<endl;
        cout<<"2. Display The List"<<endl;
        cout<<"3. Delete The element"<<endl;
        cout<<"0. For Exit"<<endl;
        cout<<"enter the task you want to perform : ";
        cin>>task;
        switch(task){
        case 0:
            break;
        case 1:
            head = insrt_Element(head);
            cout<<endl;
            break;

        case 2:
            display(head);
            cout<<endl;
            break;

        case 3:
            int num;

            cout<<"Enter the position where you delete the element:"<<endl;
            cin>>num;
            head = dlt_Element(head,num);
            cout<<endl;
            break;

        default:
            cout<<"enter correct choice :"<<endl;
            cout<<endl;
            break;
        }
    }while(task!=0);
    return 0;
}
