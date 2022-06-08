// DIVISORES

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MAX = 1e5+7;
const ll MOD = 1e9+7;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;

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
