#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall e.cpp -o e 

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define all(x) begin(x), end(x)
#define le(x) for (auto &it : x) cin >> it
#define print(x) for (auto &it : x) cout << it << ' '
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
const int MAX = 2e3+3;
const ll MOD = 1e9+7;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;

int visited[MAX][MAX];
char matriz[MAX][MAX];

int solve(int n, int x, int y){
    if(x>=n || y>=n || y<0 || x<0) return 2;
    if(visited[x][y]==2) return 2;
    if(visited[x][y]==1) return 1;

    if(visited[x][y] == 0) visited[x][y] = 1;

    if(matriz[x][y] == 'B') return visited[x][y] = solve(n, x+1, y);
    if(matriz[x][y] == 'C') return visited[x][y] = solve(n, x-1, y);
    if(matriz[x][y] == 'D') return visited[x][y] = solve(n, x, y+1);
    if(matriz[x][y] == 'E') return visited[x][y] = solve(n, x, y-1);
}

int main(){ sws; 

    int n;
    cin>> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>> matriz[i][j];
        }
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<< (solve(n, i, j) == 2) ? 1 : 0;;
        }
        cout<<endl;
    }




    return 0;
}