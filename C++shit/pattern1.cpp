/*
********
*      *
*      *
*      *
*      *
*      *
*      *
******** 
*/
#include<iostream>
using namespace std;

int main(){
    int r, c;
    cout<<"Enter rows and colums";
    cin>>r>>c;

    for(int i=1;i<=c;i++){
        for (int j=1;j<=r;j++){
            if(i==1 || i==c || j==1 || j==r){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    /*for(int i=0;i<c;i++){

         if(i>0 && i<c-1){
            for(int j=0;j<r;j++){
                if(j>0 && j<r-1){
                    cout<<" ";
                }else{
                    cout<<"*";
                }
            }
        }else{
            for(int j=0;j<r;j++){
                cout<<"*";
            }
        }
       
        cout<<endl;
    }*/
}
