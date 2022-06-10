#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall chuva.cpp -o chuva

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define all(x) begin(x), end(x)
#define le(x) for (auto &it : x) cin >> it
#define print(x) for (auto &it : x) cout << it << ' '
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int,int>
const int MAX = 1e5+7;
const ll MOD = 1e9+7;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
//----------------------------------
int visited[501][501];
char matriz[501][501];

void dfs(int i, int j, int n, int m){
        if(i<0 || i>=n || j<0 || j>=m) return;
        if(matriz[i][j]=='#')return;

        if(visited[i][j]==1)return;

        visited[i][j] = 1;

        if(matriz[i][j]=='.'){
            if(matriz[i-1][j]=='o'){
                matriz[i][j] = 'o';
                
            }
            if(matriz[i][j+1] || matriz[i][j-1] == 'o'){
                matriz[i][j] = 'o';
            }
            
        }
        dfs(i,j+1, n, m);
        dfs(i,j-1, n, m);
        dfs(i+1,j,n,m);
        return;
}

int main(){ sws; 

    int n, m;
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>matriz[n][m];
        }
    }

    for(int i=1; i<=m; i++){
        if(matriz[0][i] == 'o'){
            dfs(0, i+1, n, m);
            dfs(0, i-1, n, m);
            break;
        }
    }

    for(int i=1;i<=n; i++){
        for(int j=1; j<=m; j++){
            cout<<matriz[i][j];
        }
        cout<<endl;
    }

    return 0;
}