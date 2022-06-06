#include<bits/stdc++.h>

using namespace std;

struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};

struct Node * Create_Tree(int temp){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = temp;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
};

struct Node * Insert_Tree(struct Node* root,int temp){
    if(root==NULL){
        return Create_Tree(temp);
    }
    else if(root->value > temp){
        root->left = Insert_Tree(root->left,temp);
    }
    else{
        root->right = Insert_Tree(root->right,temp);
    }
    return root;
};

struct Node *inOrderPredecessor(struct Node* root){
    root = root->left;
    while (root->right!=NULL){
        root = root->right;
    }
    return root;
}
struct Node *inOrderSuccessor(struct Node* root){
    root = root->right;
    while (root->left!=NULL){
        root = root->left;
    }
    return root;
}

struct Node *delete_Node(struct Node *root, int value){
    struct Node* iPre;
    if (root == NULL){
        cout<<"Element is not Present in Tree"<<endl;
        return root;
    }
    if (value < root->value){
        root-> left = delete_Node(root->left,value);
    }
    else if (value > root->value){
        root-> right = delete_Node(root->right,value);
    }
    else{
        if (root->left==NULL&&root->right==NULL){
        free(root);
        return NULL;
        }
        else if(root->right != NULL){
            iPre = inOrderSuccessor(root);
            root->value = iPre->value;
            root->right = delete_Node(root->right,root->value);
        }
        else{
            iPre = inOrderPredecessor(root);
            root->value = iPre->value;
            root->left = delete_Node(root->left,root->value);
        }
    }
    return root;
}

struct Node *searching(struct Node *root,int temp){
    if(root==NULL){
        return NULL;
    }
    if(root->value == temp){
        return root;
    }
    else if(root->value>temp){
        return searching(root->left,temp);
    }
    else{
        return searching(root->right,temp);
    }
};


void in_order(struct Node *root){
    if(root==NULL){
        return;
    }
    in_order(root->left);
    cout<<root->value<<" ";
    in_order(root->right);
}

int main(){
    struct Node *root = NULL;
    struct Node *n;

  int task;
    do{
        cout<<"1. insertion in Tree"<<endl;
        cout<<"2. searching in a Tree"<<endl;
        cout<<"3. deletion in Tree"<<endl;
        cout<<"4. display The Tree"<<endl;
        cout<<"0. for Exit"<<endl;
        cout<<"enter a tsk to be performed : ";
        cin>>task;
        switch(task){
        case 0:
            break;
        case 1:
            int value;
            cout<<"enter the value: ";
            cin>>value;
            root = Insert_Tree(root,value);
            cout<<endl;
            break;

        case 2:
            int temp;
            cout<<"enter the value for Searching : ";
            cin>>temp;
            n = searching(root,temp);
            if(n!=NULL){
                cout<<"Found: "<<n->value<<endl;
            }
            else{
                cout<<temp<<" not present in the tree"<<endl;
            }
            cout<<endl;
            break;

        case 3:

            cout<<"enter the value for deletion : ";
            cin>>value;
            root = delete_Node(root,value);
            cout<<endl;
            break;

        case 4:
            in_order(root);
            cout<<endl;
            break;

        default:
            cout<<"please enter correct choice"<<endl;
            cout<<endl;
            break;
        }
    }while(task!=0);

    return 0;
}
