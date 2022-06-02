#include <bits/stdc++.h>
using namespace std;
//g++ -std=c++17 -O2 -Wall run.cpp -o run

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

int main(){ sws;
    
    int n, q;
    cin>>n>>q;

    vector<ll> psum(n+1), v(n);
    input(v);
    psum[0]=0;
    for(int i=1; i<=n; i++){
        psum[i] = psum[i-1]+v[i-1];
    }
    while(q--){
        int l, r;
        cin>>l>>r;

        cout<<(psum[r] - psum[l-1])<<endl;
    }

    return 0;
}