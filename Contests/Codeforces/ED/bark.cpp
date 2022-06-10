#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall bark.cpp -o bark

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

    string s;
    bool pass = false, first= false, second=false;
    cin>> s;
    int n;
    cin>> n;
    while(n--){
        string x;
        cin>> x;
        if(x == s) pass = true;
        if(x[0] == s[1] && x[1] == s[0])pass=true;
        else if(x[0] == s[1])first=true;
        else if(x[1] == s[0])second=true;
    }

    if(pass || (first && second)){
        cout<< "YES" <<endl;
    }else{
        cout<< "NO" <<endl;
    }

    return 0;
}