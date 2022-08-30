#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define sws ios::sync_with_stdio(false);cin.tie( NULL);cout.tie(NULL);
#define pb(x) push_back(x);
#define pii pair<int,int>
const int N = 1e3+5;

int n, t;
int tab[N][N];
bool pegou[N][N];
vector<pair<int,int>> v;

vector<int> resposta;

int dp(int idx, int dias){
    if(idx >= n) return 0;
    if(tab[idx][dias] != -1) return tab[idx][dias];

    int pega=0;
    if(dias+v[idx].first <= t){
        pega = dp(idx+1, dias+v[idx].first)+v[idx].second;
    }

    int npega = dp(idx+1, dias);
    
    if(pega>npega) pegou[idx][dias] = true;

    return tab[idx][dias] = max(pega, npega);
}

int32_t main(){
    memset(tab, -1, sizeof(tab));
    cin>>n>>t;
    for(int i=0; i<n; i++){
        int ti, di;
        cin>>ti>>di;

        v.push_back({ti, di});
    }
    dp(0, 0);
    int i = 0, j =0;
    vector<int> ans;
    // retornar os valores
    while(i < n){
        if(pegou[i][j]){
            j += v[i].first;
            ans.push_back(i+1);
        }
        i++;
    }
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

}
