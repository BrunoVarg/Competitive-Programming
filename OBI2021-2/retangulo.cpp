#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall retangulo.cpp -o retangulo

int main(){
    int n;
    cin>>n;
    vector<int> v;
    int soma=0;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
        soma+=x;
    }

    if(soma%4==0){
        cout<<"S"<<endl;
    }else{
        cout<<"N"<<endl;
    }
    return 0;
}