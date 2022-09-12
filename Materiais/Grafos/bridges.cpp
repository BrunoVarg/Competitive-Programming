#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
const int MAX = 1e5+5;

vector<int> adj[MAX];
int timer=0;
int low[MAX], tin[MAX];
bool bridge=false;
bool visited[MAX];

void dfs(int v, int p=-1){
    visited[v] = true;
    low[v] = tin[v] = timer++;
    for(auto u: adj[v]){
        if(u!=p){
            if(!visited[u]){
                dfs(u, v);
                if(low[u] > tin[v]) bridge=true; // bridge between v and u
            }
            low[v] = min(low[u], low[v]);
        }
    }
}


int32_t main(){ sws; 
	int n, m;
	cin>>n>>m;
	
	for(int i=0; i<m; i++){
	    int a, b;
	    cin>>a>>b;
	    
	    adj[a].pb(b);
	    adj[b].pb(a);
	}
	for(int i=1; i<=n; i++){
	    if(!visited[i]) dfs(i);
	}
	if(bridge)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

    return 0;
}
