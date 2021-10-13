#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall gregor.cpp -o gregor

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
const int MAX = 2*1e5+7;
const ll MOD = 1e9+7;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
//----------------------------------//
//         Fé que o AC vem          //
//----------------------------------//
int tab[2][MAX];
int conta;
int n;
void dfs(int i, int j){
    if(tab[i][j]==0)return;

    if(j!=0){
        if(tab[i-1][j-1] == 1){
            tab[i-1][j-1] = 2;
            conta++;
            return;
        }
    }
    if(tab[i-1][j] == 0){
        tab[i-1][j] = 2;
        conta++;
        return;
    }
    if(j!=n-1){
        if(tab[i-1][j+1] == 1){
            tab[i-1][j+1] = 2;
            conta++;
            return;
        }
    }

    return;
}

int main(){ sws; 
    int q;
    cin>>q;

    while(q--){
        cin>>n;
        conta = 0;
        for(int i=0; i<2; i++){
            string s;
            cin>>s;
            for(int j=0; j<n;j++){
                char c = s[j];
                int x = c-'0';
                tab[i][j] = x;
            }
        }
        for(int i=0; i<n; i++){
            dfs(1, i);
        }
        cout<<conta<<endl;
    }

    return 0;
}