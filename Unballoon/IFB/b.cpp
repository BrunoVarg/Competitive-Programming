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

    int n,m;
    cin>>n>>m;
    stack<int> s;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(s.empty()) s.push(x);
        else{
            if((int)s.size()<m){
                if(s.top()>=x)s.push(x);

            }
        } 
    }
    int count=0;
    while(!s.empty()){
        count += s.top();
        s.pop();
    }
    cout<<count<<endl;

    return 0;
}