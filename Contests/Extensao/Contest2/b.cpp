#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall b.cpp -o b

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define all(x) begin(x), end(x)
#define le(x) for (auto &it : x) cin >> it
#define print(x) for (auto &it : x) cout << it << ' '
#define pb push_back
#define mp make_pair
#define pii pair<int,int>

int main(){ sws; 
    int n, subs =0;
    string s;
    cin>> n;
    cin>> s;

    for(int i=0; i<n; i++){
        if((s[i]-'0') % 2 == 0){
            subs+=i+1;
        }
    }

    cout<< subs<<endl;


    return 0;
}