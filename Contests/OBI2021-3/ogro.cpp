#include <bits/stdc++.h>
using namespace std;
//g++ -std=c++17 -O2 -Wall ogro.cpp -o ogro


int main(){

    int n;
    cin>>n;
    if(n<=5 and n>0){
        for(int i=0; i<n; i++){
            cout<<"I";
        }
        cout<<endl;
        cout<<"*"<<endl;
    }else if(n>5){
        cout<<"IIIII"<<endl;
        for(int i=0; i< (n-5); i++){
            cout<<"I";
        }
        cout<<endl;
    }else if(n==0){
        cout<<"*"<<endl;
        cout<<"*"<<endl;
    }

    return 0;
}