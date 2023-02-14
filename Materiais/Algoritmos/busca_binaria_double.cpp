// 
// Complexidade : O(NlogN)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ld EPS = 1e-9;

ll check(ld x, vector<int> &v){
    ll sum = 0;
    for(int i=0; i<n; i++){
        sum += (v[i]/x);
    }
    return sum;
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];

    ld l=0.0000000, r=10000000.0000000;
    ld mid;
    while(r-l>EPS){
        mid = (ld)((l + r)/2);
        if (check(mid, v)>=k){
            l=mid;
        }
        else{
            r = mid;
        }
    }
    cout<<fixed<<setprecision(7)<<mid<<endl;
    
    return 0;
}
