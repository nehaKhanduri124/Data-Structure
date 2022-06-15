#include<bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;


void display(vector<int> &mheap){
    for(int i=0;i<mheap.size();++i){
        cout<<mheap[i]<<" " ;
    }
    cout<<endl;
    return;
}
void max_Heapify(vector<int> &mheap,int i){
    int num = mheap.size();
    int lar = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<num && mheap[l]>mheap[lar]){
        lar = l;
    }
     if(r<num && mheap[r]>mheap[lar]){
        lar = r;
    }
    if(lar != i){
        int temp = mheap[i];
        mheap[i] = mheap[lar];
        mheap[lar] = temp;
        max_Heapify(mheap,lar);
    }
}

void Insert_Max(vector<int> &mheap,int key){
    int num = mheap.size();
    if(num == 0){
        mheap.push_back(key);
    }
    else{
        mheap.push_back(key);
        for(int i=num-1;i>=0;i--){
            max_Heapify(mheap,i);
        }
    }
}

void Delete_Max(vector <int> &mheap,int value){
    int num = mheap.size();
    int i;
    for(i=0;i<num;i++){
        if(value == mheap[i]){
            break;
        }
    }
    int temp = mheap[i];
    mheap[i] = mheap[num-1];
    mheap[num-1] = temp;
    mheap.pop_back();
    for(int i=num-1;i>=0;i--){
        max_Heapify(mheap,i);
    }
}

int main(){
    vector <int> mheap;
    int option;
    do{
        cout<<"1. insert in Max Heap"<<endl;
        cout<<"2. delete from the Max Heap"<<endl;
        cout<<"3. Display The Max Heap"<<endl;
        cout<<"0. For Exit"<<endl;
        cout<<"ENTER THE OPTION : ";
        cin>>option;
        switch(option){
        case 0:
            break;
        case 1:
            int value;
            cout<<"Enter the value: ";
            cin>>value;
            Insert_Max(mheap,value);
            cout<<endl;
            break;

        case 2:
            int data;
            cout<<"enter the data: ";
            cin>>data;
            Delete_Max(mheap,data);
            cout<<endl;
            break;

        case 3:
            display(mheap);
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
