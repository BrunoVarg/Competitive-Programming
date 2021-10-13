#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall d.cpp -o d

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

    int n;
    cin>>n;
    vector<string> v((int)n/3);
    for(int i=0; i<3; i++){
        string s;
        getline(cin, s);
        cin.get();
    }

    // v[i][0]== ' ' and v[i][1]== ' ' and v[i][2]== ' ' and v[i][3]== ' ' and v[i][4]== ' ' and v[i][5]== ' ' and v[i][6]== ' ' and v[i][7]== ' ' and v[i][8]== ' '
    for(int i=0; i<(int)n/3; i++){
        if(v[i][0]== ' ' and v[i][1]== ' ' and v[i][2]== ' ' and v[i][3]== ' ' and v[i][4]== ' ' and v[i][5]== '|' and v[i][6]== ' ' and v[i][7]== ' ' and v[i][8]== '|'){
            cout<<1;
        }
        else if(v[i][0]== ' ' and v[i][1]== '-' and v[i][2]== ' ' and v[i][3]== ' ' and v[i][4]== '-' and v[i][5]== '|' and v[i][6]== '|' and v[i][7]== '-' and v[i][8]== ' '){
            cout<<2;
        }
        else if(v[i][0]== ' ' and v[i][1]== '_' and v[i][2]== ' ' and v[i][3]== ' ' and v[i][4]== '_' and v[i][5]== '|' and v[i][6]== ' ' and v[i][7]== '_' and v[i][8]== '|'){
            cout<<3;
        }
        else if(v[i][0]== ' ' and v[i][1]== ' ' and v[i][2]== ' ' and v[i][3]== '|' and v[i][4]== '_' and v[i][5]== '|' and v[i][6]== ' ' and v[i][7]== ' ' and v[i][8]== '|'){
            cout<<4;
        }
        else if(v[i][0]== ' ' and v[i][1]== '_' and v[i][2]== ' ' and v[i][3]== '|' and v[i][4]== '_' and v[i][5]== ' ' and v[i][6]== ' ' and v[i][7]== '_' and v[i][8]== '|'){
            cout<<5;
        }else if(v[i][0]== ' ' and v[i][1]== '_' and v[i][2]== ' ' and v[i][3]== '|' and v[i][4]== '_' and v[i][5]== ' ' and v[i][6]== '|' and v[i][7]== '_' and v[i][8]== '|'){
            cout<<6;
        }
        else if(v[i][0]== ' ' and v[i][1]== '_' and v[i][2]== ' ' and v[i][3]== ' ' and v[i][4]== ' ' and v[i][5]== '|' and v[i][6]== ' ' and v[i][7]== ' ' and v[i][8]== '|'){
            cout<<7;
        }
        else if(v[i][0]== ' ' and v[i][1]== '_' and v[i][2]== ' ' and v[i][3]== '|' and v[i][4]== '_' and v[i][5]== '|' and v[i][6]== '|' and v[i][7]== '_' and v[i][8]== '|'){
            cout<<8;
        }
        else if(v[i][0]== ' ' and v[i][1]== '_' and v[i][2]== ' ' and v[i][3]== '|' and v[i][4]== '_' and v[i][5]== '|' and v[i][6]== ' ' and v[i][7]== '_' and v[i][8]== '|'){
            cout<<9;
        }
        else if(v[i][0]== ' ' and v[i][1]== '_' and v[i][2]== ' ' and v[i][3]== '|' and v[i][4]== ' ' and v[i][5]== '|' and v[i][6]== '|' and v[i][7]== '_' and v[i][8]== '|'){
            cout<<0;
        }
    }

    return 0;
}