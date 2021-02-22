/*
******
*****
****
***
**
*

#include<iostream>
using namespace std;

int main(){
    int i,j,n;
    cout<<"Enter N \n";
    cin>>n;

    for(i=n;i>0;i--){
        for(j=i;j>0;j--){
            cout<<"*";
        }
        cout<<endl;
    }
}
*/

/*

    *
   **
  ***
 ****
*****

#include<iostream>
using namespace std;
int main(){
    int i,j,n;
    cout<<"Enter n \n";
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(j>n-i){
                cout<<"*";
            }else{
                cout<<" ";

            }
        }
        cout<<endl;
    }
}
*/

/*
1
22
333
4444
55555
666666


#include<iostream>
using namespace std;
int main(){
    int i,j,n;
    cout<<"Enter N \n";
    cin>>n;

    for(i=1;i<=n;i++){
        for (j=1;j<=i;j++){
            cout<<i;
        }
        cout<<endl;
    }
}


#include<iostream>
using namespace std;
 int main(){
     int i,j,n,k=1;
     cout<<"Enter n";
     cin>>n;

     for(i=1;i<=n;i++){
         for(j=1;j<=i;j++){
             cout<<k;
             k++;
         }
         cout<<endl;
     }
 }

/*
1
23
456
78910
1112131415

#include<iostream>
using namespace std;
int main(){
    int i,j,n,k=1;
    cout<<"Enter n";
    cin>>n;

    for(i=0;i<n;i++){
        for(j=0;j<i;j++){
            cout<<k<<" ";
            k++;
            }
        }
        cout<<endl;
    }
}
*/

#include<iostream>
using namespace std;
int main(){
    int i,j,k,n;
    cout<<"Enter n "<<endl;
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=2*n;j++){
            if( j <= i || j> 2*n-i){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=2*n;j++){
            if( j >= i || j< 2*n-i){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}
