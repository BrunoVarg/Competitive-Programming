vector<int> adj[MAX];
int up[MAX][30], parent[MAX];
 
void process(int n){
    for(int v=1; v<=n; v++){
        up[v][0]= parent[v];
        for(int i=1; i<30; i++){
            up[v][i] = up[ up[v][i-1] ][i-1];
        }
    }
}
 
int jump(int n, int k){
    for(int i=0; i<30; i++){
		if(k & (1 << i)){
			n = up[n][i];
		}
	}
	if(n == 0) return -1;
	return n;
}
    		
int32_t main(){
    
    int n, q; cin>>n>>q;
    
    parent[1] = 0;
    for(int i=1; i<=n-1; i++){
        int x;
        cin>>x;
        parent[i+1] = x;
        
        adj[i+1].pb(x);
        adj[x].pb(i+1);
    }
    process(n);
    for(int i=0; i<q; i++){
        int a, b;
        cin>>a>>b;
        
        cout<<(jump(a,b))<<endl;
    }
}