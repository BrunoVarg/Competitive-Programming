#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall run.cpp -o run

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
const int MAX = 1e5+7;
const ll MOD = 1e9+7;

vi crivo(MAX, 1);
for(int i=2; i*i<=MAX; i++){
    if(crivo[i]==1){
        for(int j=i+i; j<MAX; j+=i){
            crivo[j]=0;
        }
    }
}

map<int,int> fatora(int x){
    map<int,int> exp;
    int count=0;
    while(n>1){
        exp[lp[n]]++;
        n/=lp[n];
    }
    return exp;

