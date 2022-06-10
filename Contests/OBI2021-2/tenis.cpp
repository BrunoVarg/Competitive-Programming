#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall tenis.cpp -o tenis

int main(){

    int a,b,c,d;
    cin>>a>>b>>c>>d;

    vector<int> v;
    v = {a,b,c,d};
    sort(v.begin(),v.end());

    int soma = abs((v[3]+v[0]) - (v[2]+v[1]));
    cout<<soma<<endl;
    
    
    return 0;
}