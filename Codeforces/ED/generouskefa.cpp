#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall generouskefa.cpp -o generouskefa

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

    int n, k;
    cin>> n>> k;
    vi let(26,0);
    for(int i=0; i<n; i++){
        char cha;
        cin >> cha;
        let[cha-'a']+=1;
    }
    for(int i=0; i<26; i++){
        if(let[i]>k){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;


    return 0;
}