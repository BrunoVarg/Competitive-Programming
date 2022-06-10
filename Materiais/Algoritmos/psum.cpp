#include <bits/stdc++.h>
using namespace std;

#define input(x) for (auto &it : x) cin >> it
typedef long long ll;

int psum(int l, int r){
    if(l==0) return psum[r];
    else return psum[r] - psum[l-1];
}

int main(){
    
    int n, q;
    cin>>n>>q;

    vector<ll> psum(n), v(n);
    input(v);
    for(int i=0; i<n; i++){
        if(i==0)psum[i] = v[i];
        else psum[i] = psum[i-1] + v[i];
    }
    while(q--){
        int l, r;
        cin>>l>>r;

        cout<<(psum(l,r))<<endl;
    }

    return 0;
}
