// PRIMALIDADE

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5+7;

void crivo(){
    vector<int> crivo(MAX, 1);
    for(int i=2; i*i<=MAX; i++){
        if(crivo[i]==1){
            for(int j=i+i; j<MAX; j+=i){
                crivo[j]=0;
            }
        }
    }
}

bool is_prime(int num){
    for(int i = 2; i*i<= num; i++) {
       if(num % i == 0) {
          return false;
       }
    }
    return true;
}
