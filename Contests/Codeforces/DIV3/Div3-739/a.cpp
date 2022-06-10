#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall a.cpp -o a

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
    vi ans;
    vi num;
    vi ans1;


    while(t--){
        int n;
        cin>>n;
        num.pb(n);
        ans1.pb(n);
    }
    sort(all(ans1));
    reverse(all(ans1));

    int i=1;
    while(true){
        if((int)ans.size()==ans1[0])break;
        if((i%3!=0 or i%10!=3) and (i%3!=0 and i%10!=3)) ans.pb(i);
        i+=1;
    }

    for(int i=0; i<(int)num.size(); i++){
        int atual = num[i];
        cout<<ans[atual-1]<<endl;
    }

    return 0;
}