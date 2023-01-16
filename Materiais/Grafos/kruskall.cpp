// Arvore geradora minima
// O(MlogN)

#include <bits/stdc++.h>
using namespace std;

int n;
class DSU{
    vector<int> parent, sz;
    public:
    void make(int v){
        parent[v] = v;
        sz[v] = 1;
    }

    int find(int v){
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }

    void union_(int a, int b){
        a = find(a), b = find(b);

        if(sz[b]>sz[a]) swap(a,b);
        if (a != b){
            sz[a] += sz[b];
            parent[b] = a;
        }
    }
    
    bool same(int a, int b){
        a = find(a), b = find(b);
        return a == b;
    }
    
    DSU(int n): parent(n+1), sz(n+1){
        for(int i=1; i<=n; i++) make(i);
    }
};

// {a, b, weight}
vector<tuple<int,int,int>> MST(vector<tuple<int,int,int>> &v){
    DSU dsu(n);
    sort(v.begin(), v.end());
    vector<tuple<int,int,int>> ans;
    for(int i=0; i<v.size(); i++){
        int w, a, b;
        tie(w, a, b) = v[i];
        if(!dsu.same(a, b)){
            dsu.union_(a, b);
            ans.push_back({a, b, w});
        }
    }
    return ans;
}

int32_t main(){
    int m;
    cin>>n>>m;
    DSU dsu(n);
    vector<tuple<int,int,int>> vt;
    for(int i=0; i<m; i++){
        int a, b, w;
        cin>>a>>b>>w;
        // {weight, a, b}
        vt.push_back({w, a, b});
    }
    vector<tuple<int,int,int>> ans = MST(vt); 
    return 0;
}