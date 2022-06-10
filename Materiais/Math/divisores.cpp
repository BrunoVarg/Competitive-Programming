#include <bits/stdc++.h>
using namespace std;

vector<long long> get_divisors(long long n){
    vector<long long> divs;
    for(long long i = 1; i*i <=n; i++){
        if(n%i == 0){
            divs.push_back(i);
            long long j = n/i;
            if(j != i)
                divs.push_back(j);
        }
    }
    return divs;
}
