#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall l.cpp -o l

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
const int MAX = 1e9+7;
const ll MOD = 1e9+7;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
//----------------------------------//
//         Fé que o AC vem          //
//----------------------------------//
vector<ll> thabit;
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

int main(){ sws; 

    for(int i=0; i<30; i++){
        int calc = 3*pow(2, i)-1;
        thabit.pb(calc);
    }
    int n;
    cin>>n;
    bool prim = false;
    bool thab = false;
    for(int i=0; i<30; i++){
        if(n==thabit[i]){
            thab=true; 
            break;
        }
    }
    vector<ll> ans = get_divisors(n);
    if(ans.size()==2){
        prim = true;
    }

    if(prim and thab){
        cout<<"TP"<<endl;
    }else if(prim==true and thab==false){
        cout<<"P"<<endl;
    }else if(thab == true and prim==false){
        cout<<"T"<<endl;
    }else{
        cout<<"C"<<endl;
    }



    // thabit = 2, 5, 11, 23, 47, 191, 383, 6143, 786431, 51539607551, 824633720831

    return 0;
}