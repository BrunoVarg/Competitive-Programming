#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall caminhoponte.cpp -o caminhoponte

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
const int MAX = 200;
const ll MOD = 1e9+7;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
//----------------------------------//
//         Fé que o AC vem          //
//----------------------------------//


vector<pair<int, int>> lista[MAX];
vector<ll> ans(MAX,-1);



ll dfs(int x){
	if(ans[x]==-1)return ans[x];

	for(auto i : lista[x])

	return ans[x];
}


int main(){ sws; 

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int s, t, b;
        cin>>s>>t>>b;

        lista[s].pb({t,b});
        lista[t].pb({s,b});

    }


    return 0;
}