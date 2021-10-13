#include <bits/stdc++.h>
using namespace std;
//g++ -std=c++17 -O2 -Wall minhoca.cpp -o minhoca
const int MAX = 5e4+5;
int used[MAX];
int acumulado[200000001];
vector<int> lista[MAX];
#define print(x) for (auto &it : x) cout << it << ' '

int dfs(int v, int acum){
    acumulado[acum]++;
    int ans = 0;
    used[v]=1;
    for(auto u : lista[v]){
        if(used[u]==-1){
            ans = max(ans, dfs(u, acum+1)+1);
        }
    }
    return ans;  
}

int main(){

    int n;
    cin>>n;
    memset(used, -1, sizeof(used));
    vector<int> caminhos(n+1);
    vector<int> folhas(n+1);
    for(int i=0; i<n-1; i++){
        int x, y;
        cin>>x>>y;
        lista[x].push_back(y);
        lista[y].push_back(x);
        // achar as folhas / raizes
        folhas[x]++;
        folhas[y]++;
    }
    
    
    int ans=0;
    for(int i=1;i<=n; i++){
        if(folhas[i]==1){
            memset(used, -1, sizeof(used));
            int x = dfs(i, 0);
            caminhos[i] = x;
            ans = max(ans, x);
        }
    }

    cout<<ans+1<<endl;
    cout<<acumulado[ans]/2<<endl;

    return 0;
}
