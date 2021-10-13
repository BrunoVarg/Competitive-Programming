#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall hotelier.cpp -o hotelier

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define all(x) begin(x), end(x)
#define le(x) for (auto &it : x) cin >> it
#define print(x) for (auto &it : x) cout << it
#define pb push_back
#define mp make_pair
#define pii pair<int,int>

int main(){ sws; 

    int n;
    cin >> n;
    vi rooms(10, 0);
    for(int i=0; i<n; i++){
        char c;
        cin >> c;
        if (c == 'L'){
            for(int j=0; j<10; j++){
                if(rooms[j]==0){
                    rooms[j] = 1;
                    break;
                }
            }
        } else if(c=='R'){
            for(int j=9; j>=0; j--){
                if(rooms[j]==0){
                    rooms[j] = 1;
                    break;
                }
            }
        } else{
            c = c - '0';
            rooms[c] = 0;
        }
    }
    print(rooms);

    return 0;
}