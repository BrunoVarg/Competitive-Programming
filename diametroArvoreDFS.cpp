#include <bits/stdc++.h>
using namespace std;
//g++ -std=c++17 -O2 -Wall x.cpp -o x

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) begin(x), end(x)
#define input(x) for (auto &it : x) cin >> it
#define print(x) for (auto &it : x) cout << it << ' '
#define dbg(msg, x) cout << msg << " = " << x << endl
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MAX = 1e5+10;
const ll MOD = 1e9+5;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
//----------------------------------//
//         Fé que o AC vem          //
//----------------------------------//
int to_leaf[MAX];
int max_length[MAX];
int dist[MAX];

vector<int> adj(MAX);
/*
void dfs(int u, int p, vector<int> &dist){
    for(auto [v, w] : adj[u]){
        if(v!=p){
            dist[v] = dist[u] + w;
            dfs(v, u, dist);
        }
    }
}

int solve(int n){
    vector<int> dist(n+1, 0);

    dfs(0, -1, dist);

    auto v = (int)(max_element(dist.begin(), dist.end()) - dist.begin());

    dist[v] = 0;
    dfs(v, -1, dist);

    return *max_element(dist.begin(), dist.end());
}*/

void dfs(int u, int p){
    vi ds;

    for(auto v: adj[u]){
        if(v==p)continue;

        dfs(v, u);
        ds.pb(to_leaf[v]);
    }
    sort(ds.begin(), ds.end());

    to_leaf[u] = ds.empty() ? 0 : ds.back() + 1;

    auto N = ds.size();

    switch(N){
        case 0:
            max_length[u]=0;
            break;
        case 1:
            max_length[u] = ds.back() + 1;
            break;
        default:
            max_length[u] = ds[N-1] + ds[N-2] + 2;
    }
}

int diameter(int root, int N){
    dfs(root, 0);

    int d=0;

    for(int u=1; u<=N; u++){
        d= max(d, max_length[u]);
    }
}

