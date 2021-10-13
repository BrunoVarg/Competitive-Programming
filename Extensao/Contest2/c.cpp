#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall c.cpp -o c

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

    int n;
    cin >> n;
    while(n--){
        int num;
        cin >> num;
        
        if(num%2020 ==0 || num%2021 ==0) {
            cout<< "YES"<<endl;
        } else{
            if(num%2020<= num/2020){
                cout<< "YES"<<endl;
            }
            else{
                cout<< "NO"<<endl;
            }
        }        
        
    }

    return 0;
}