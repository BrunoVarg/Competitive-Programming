#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall k.cpp -o k

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

    string s;
    cin>>s;
    int count=0;
    for(int i=0; i<(int)s.size(); i++){
        int x = s[i]-'0';
        count+=x;
    }
    if(count%3==0){
        cout<<"Sim"<<endl;
    }else{
        cout<<"Nao"<<endl;
    }

    return 0;
}