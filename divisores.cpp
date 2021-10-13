#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall run.cpp -o run

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) begin(x), end(x)
#define input(x) for (auto &it : x) cin >> it
#define print(x) for (auto &it : x) cout << it << ' '
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MAX = 1e5+7;
const ll MOD = 1e9+7;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
//----------------------------------//
//         Fé que o AC vem          //
//----------------------------------//
ll gcd(ll a, ll b){
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b){
    return (a/gcd(a,b)*b);
}

vector<ll> get_divisors(ll n){
    vector<ll> divs;
    for(ll i = 1; i*i <=n; i++){
        if(n%i == 0){
            divs.pb(i);
            ll j = n/i;
            if(j != i)
                divs.pb(j);
        }
    }
    return divs;
}
