#include <bits/stdc++.h>
using namespace std;
//g++ -std=c++17 -O2 -Wall teste.cpp -o teste

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) begin(x), end(x)
#define input(x) for (auto &it : x) cin >> it
#define print(x) for (auto &it : x) cout << it << ' '
#define dbg(msg, x) cerr << msg << " = " << x << endl
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MAX = 1e5+7;
const ll MOD = 1e9+5;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
//----------------------------------//
//         Fé que o AC vem          //
//----------------------------------//
bool equals(vector<int> v){
    int elem = v[0];
    for(auto x : v){
        if(x!=elem)return false;
    }
    return true;
}
int main(){ sws;

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<int> v(n);
        input(v);

        if(equals(v)){
            cout<<0<<endl;
        }else{
            int final = v[n-1];
            reverse(all(v));
            int ans=0;
            bool x = false;
            for(int i=0; i<n;i++){
                if(v[i]!=final){
                    for(int j=i; j<n; j++){
                        if(j<2*i){
                            if(v[j]!=final){
                                x=true;
                                v[j] = final;
                            }
                        }
                    }
                    if(x)ans++;
                }
            }

            cout<<ans<<endl;
            
        }

    }

    return 0;
}