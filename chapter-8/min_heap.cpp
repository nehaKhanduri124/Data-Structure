#include<bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;

void display(vector<int> &mihH){
    for(int i=0;i<mihH.size();++i){
        cout<<mihH[i]<<" " ;
    }
    cout<<endl;
    return;
}
void heapify(vector<int> &mihH,int i){
    int n = mihH.size();
    int small = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && mihH[l]<mihH[small]){
        small = l;
    }
     if(r<n && mihH[r]<mihH[small]){
        small = r;
    }
    if(small != i){
        int temp = mihH[i];
        mihH[i] = mihH[small];
        mihH[small] = temp;
        heapify(mihH,small);
    }
}

void Insert_MinHeap(vector<int> &mihH,int key){
    int n = mihH.size();
    if(n == 0){
        mihH.push_back(key);
    }
    else{
        mihH.push_back(key);
        for(int i=n-1;i>=0;i--){
            heapify(mihH,i);
        }
    }
}

void Delete_MinHeap(vector <int> &mihH,int value){
    int n = mihH.size();
    int i;
    int flag = 0;
    for(i=0;i<n;i++){
        if(value == mihH[i]){
            flag++;
            break;
        }
    }
    if(flag==0){
        cout<<value<<" is not present in heap!"<<endl;
        return;
    }
    int temp = mihH[i];
    mihH[i] = mihH[n-1];
    mihH[n-1] = temp;
    mihH.pop_back();
    for(int i=n-1;i>=0;i--){
        heapify(mihH,i);
    }
}

int main(){
    vector <int> mihH;

    int option;
    do{
        cout<<"1. insert in Min heap"<<endl;
        cout<<"2. delete from the Min heap"<<endl;
        cout<<"3. Display the Min heap"<<endl;
        cout<<"0. for Exit"<<endl;
        cout<<"enter a option: ";
        cin>>option;
        switch(option){
        case 0:
            break;
        case 1:
            int data;
            cout<<"Enter the data: ";
            cin>>data;
            Insert_MinHeap(mihH,data);
            cout<<endl;
            break;

        case 2:
            int value;
            cout<<"enter the value: ";
            cin>>value;
            Delete_MinHeap(mihH,value);
            cout<<endl;
            break;

        case 3:
            display(mihH);
            cout<<endl;
            break;

        default:
            cout<<"please enter correct option"<<endl;
            cout<<endl;
            break;
        }
    }while(option!=0);
    return 0;
}
