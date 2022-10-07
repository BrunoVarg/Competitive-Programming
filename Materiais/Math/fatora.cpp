#include <bits/stdc++.h>
using namespace std;
#define N 100000
vector<int> lp(N, -1);

void last_prime(){
    for(int x = 2; x < N; x++){
        if(lp[x] == -1){  // se x nao foi marcado antes, é primo
            for(int m = x; m < N; m += x){ // todos os multiplos de i
                lp[m] = x;
            }
        }
    }
}

map<int,int> fatora(int n){
    map<int,int> exp;
    int count=0;
    while(n>1){
        exp[lp[n]]++;
        n/=lp[n];
    }
    return exp;
}
