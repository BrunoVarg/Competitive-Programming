#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;

    vector<int> v(n), psum(n);
    for(int i=0; i<n; i++) cin >> v[i];

    psum[0] = v[0];

    for(int i=1; i<n; i++){
        psum[i] = psum[i-1] + v[i];
    }

    for(int i=0; i<q; i++){
        int l, r;
        cin>> l >> r;
        if(l==0)cout << psum[r] << endl;
        else cout << psum[r] - psum[l-1] << endl;
    }

    return 0;
}