#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall b.cpp -o b

int main(){
    
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int count=0;
    int tam = (int)v.size();
    for(int i=0; i<tam/2; i++){
        if(v[i] != v[tam-1-i]) count++;

    }
    cout<<count<<endl;
}