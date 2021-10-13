#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall b.cpp -o b

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
const int MAX = 1e5+7;
const ll MOD = 1e9+7;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
//----------------------------------//
//         Fé que o AC vem          //
//----------------------------------//

int main(){ sws; 

    int t;
    cin>>t;

    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int circulo = abs(a-b)*2;
        int metade = circulo/2;

        if(circulo<=2 or c>circulo or a>circulo or b>circulo){
            cout<<-1<<endl;
        }
        else if(c>(metade) and c<=circulo){
            cout<<c-metade<<endl;
        }else if (c<=metade and c<=circulo){
            cout<<c+metade<<endl;
        }
    }

    return 0;
}