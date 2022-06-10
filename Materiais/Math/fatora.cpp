#include <bits/stdc++.h>
using namespace std;

map<int,int> fatora(int n){
    vector<int> lp;
    map<int,int> exp;
    int count=0;
    while(n>1){
        exp[lp[n]]++;
        n/=lp[n];
    }
    return exp;
}
