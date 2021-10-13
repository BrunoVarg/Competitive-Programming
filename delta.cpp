#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> v(n,0);
    vector<int> delta(n+2, 0);

    while(q--){
        int l, r, x;
        cin >> l >> r >> x;
        delta[l] += x;
        delta[r+1] -= x;
    }

    int atual = 0;
    for(int i=0; i < n; i++){
        atual += delta[i];
        v[i] = atual;
    }

    for(int i=0; i< n; i++){
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}