#include <bits/stdc++.h>
using namespace std;
//g++ -std=c++17 -O2 -Wall d.cpp -o d

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) begin(x), end(x)
#define input(x) for (auto &it : x) cin >> it
#define print(x) for (auto &it : x) cout << it << ' '
#define dbg(msg, x) cerr << msg << " = " << x << endl
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MAX = 110;
const ll MOD = 1e9+5;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
//----------------------------------//
//         Fé que o AC vem          //
//----------------------------------//
int n;
int tab[MAX];
vi v;

ll dp(int i){
    if(i>=n) return 0;
    if(tab[i] != -1) return tab[i];

    int pega = v[i] + dp(i+2);
    int npega = dp(i+1);

    tab[i] = max(pega, npega);
    return tab[i];
}

int main(){ sws; 
    memset(tab, -1, sizeof(tab));
    cin>>n;

    v.assign(n, 0);

    cout<<dp(0)<<endl;


    return 0;
}