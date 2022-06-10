#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall d.cpp -o d

int main(){
    int n;
    cin>>n;
    int a, b;
    cin>>a>>b;
    vector<int> v;

    for(int i=a; i<=b; i++){
        string s = to_string(i);
        int count=0;
        for(int j=0; j<(int)s.size(); j++){
            count+= s[j] - '0';
        }
        if(count==n) v.push_back(i);
    }
    cout<<v[0]<<endl;
    cout<<v[(int)v.size()-1]<<endl;
}