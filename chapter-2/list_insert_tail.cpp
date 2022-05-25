#include<bits/stdc++.h>

using namespace std;

struct Node{
    int value;
    struct Node *link;
};

struct Node * insert_element(struct Node *head){
struct Node *newNode,*ptr;
int value;
cout<<"enter the value:";
cin>>value;
newNode = (struct Node *)malloc(sizeof(struct Node));
newNode->value = value;
if(head==NULL){
        newNode->link=NULL;
        head = newNode;
        cout<<"linked List Created"<<endl;
    }
    else{
        ptr = head;
        while(ptr->link!=NULL){
            ptr= ptr->link;
        }
        ptr->link = newNode;
        newNode->link = NULL;
    }
    return head;
};

void display(struct Node *head){
    struct Node *p=head;
    if(p==NULL){
        cout<<"empty list"<<endl;
    }
    else{
         cout<<"elements are:";
        while(p!=NULL){
            cout<<p->value<<" ";
            p = p->link;
        }
    }
    cout<<endl;
}

int main()
{

    struct Node *head = NULL;
    int task;
    do{
        cout<<"1.Insert New Element"<<endl;
        cout<<"2.Display The List"<<endl;
        cout<<"0.For Exit"<<endl;
        cout<<"ENTER THE CHOICE : ";
        cin>>task;
        switch(task) {
        case 0:
            break;
        case 1:
            head = insert_element(head);
            cout<<endl;
            break;

        case 2:
            display(head);
            cout<<endl;
            break;

        default:
            cout<<"Please enter correct task to be performed"<<endl;
            cout<<endl;
            break;
        }
    }while(task!=0);
    return 0;
}
