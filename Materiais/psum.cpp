// PSUM

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(), x.end()
#define input(x) for (auto &it : x) cin >> it
#define print(x) for (auto &it : x) cout << it << ' '; cout<<endl;
#define dbg(msg, x) cout << msg << " = " << x << endl
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define TETO(a, b) ((a) + (b-1))/(b)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const ll MOD = 1e9+7;
const ll MAX = 1e18;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
//----------------------------------//
//         Fé que o AC vem          //
//----------------------------------//

int psum(int l, int r){
    if(l==0) return psum[r];
    else return psum[r] - psum[l-1];
}

int main(){ sws;
    
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
