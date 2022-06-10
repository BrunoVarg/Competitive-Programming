#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall a.cpp -o a

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define all(x) begin(x), end(x)
#define le(x) for (auto &it : x) cin >> it
#define print(x) for (auto &it : x) cout << it << ' '
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
const int MAX = 1e5+7;
const ll MOD = 1e9+7;

int main(){ sws; 

    int n, q;
    cin>> n >> q;
    map<string,int> m;

    for(int i=0; i<n; i++){
        string nome;
        int x;
        cin>> nome >> x;
        m.insert(mp(nome,x));
    }

    for(int i=0; i<q; i++){
        int count=0;
        string pok;
        cin>> pok;
        auto lvl = m[pok]; 
        for(auto j=m.begin(); j!=m.end(); j++){
            if(lvl > (j->second)){
                count++;
            }
        }

        cout<< count <<endl;
    }

    return 0;
}