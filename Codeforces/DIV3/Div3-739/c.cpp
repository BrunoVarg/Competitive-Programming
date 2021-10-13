#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall c.cpp -o c

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
const int MAX = 2e9;
const ll MOD = 1e9+7;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
//----------------------------------//
//         Fé que o AC vem          //
//----------------------------------//


int main(){ sws; 

    int t;
    cin>>t;
    vi raiz;
    vi col;

    for(int i=0; i*i<MAX; i++){
        raiz.pb(i*i);
    }
    int i=1;
    int j=2;
    col.pb(0);
    while(true){
        if(i>=MAX) break;
        if(i!=1){
            col.pb(i);
            j+=2;
            i+=j;
        }else{
            col.pb(i);
            i+=j;
        }
    }



    while(t--){

        int k;
        cin>>k;

        auto menorlin = lower_bound(raiz.begin(), raiz.end(), k) - raiz.begin();

        int diag = col[menorlin];
        int quadradolin = menorlin*menorlin;

        if(k==1){
            cout<<1<<" "<<1<<endl;
        }
        else if(k==diag){
            cout<<menorlin<<" "<<menorlin<<endl;
        }
        else if(k<diag){
            cout<< menorlin-abs(diag-k)<<" "<<abs(quadradolin-diag)+1<<endl;
        }else{
            cout<< menorlin<<" "<<abs(quadradolin-k)+1<<endl;
        }
        
    }


    

    return 0;
}