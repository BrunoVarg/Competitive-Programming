/*
Lowest Common ancestor (LCA) - dado uma Arvore cuja raiz eh um vertice arbitrario e dois vertices u,v que a pertencem, diga qual eh o no mais baixo(relativo a raiz) que eh ancestral de u,v.
*/
// Complexidades:
// build - O(n log(n))
// lca - O(log(n))

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int SIZE = 2e5+5;
const int LOG = 30; // log2(SIZE)+1;
int depth[SIZE];
vector<pair<int,int>> adj[SIZE];
int up[SIZE][LOG];

void dfs(int u, int p) {
    for(auto edge : adj[u]) {
        int v, w;
        tie(v, w) = edge;
        if(v != p){
            up[v][0] = u;
            //weight[v] = weight[u] + w;
            depth[v] = depth[u] + 1;
            for(int i=1; i<LOG; i++){
                up[v][i] = up[ up[v][i-1] ][i-1];
            }
            dfs(v, u);
        }
    }
}

int lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a,b);
    int k = depth[a] - depth[b];
    for(int i=0; i<LOG; i++){
        if(k & (1 << i)){
            a = up[a][i];
        }
    }
    if(a == b) return a;
    for (int i = LOG-1; i >= 0; i--) {
        if(up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

ll dist(int u, int v){
    return depth[u] + depth[v] - 2*depth[lca(u,v)];
    // return weight[u] + weight[v] -2*weight[lca(u,v)];
}

int main() {
    int n; cin>>n;

    for(int i=0; i<n-1; i++){
        int x, y, z;
        cin>>x>>y>>z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    // raiz
    dfs(1, 0);
	
    int q; cin>>q;
    while(q--){
        int a, b, c;
        cin>>a>>b>>c;
        long long x = dist(a, b) + dist(b, c);
        cout<<x<<endl;
    }
}