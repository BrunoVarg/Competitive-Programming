#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall run.cpp -o run

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
    cin>> n;

    while(n--){
        int xa, ya, xb, yb, xf, yf, disx, disy, passos=0;
        cin>> xa >> ya;
        cin>> xb >> yb;
        cin>> xf >> yf;

        disx = abs(xa-xb);
        disy = abs(ya-yb);

        if(((((xf <xa) && (xf>xb)) || ((xf >xa) && (xf<xb))) && ((yb==ya)&&(yf==ya)))){
            passos = disx+disy+2;
            cout<< passos<<endl;
        }else if(((((yf <ya) && (yf>yb)) || ((yf >ya) && (yf<yb))) && ((xb==xa)&&(xf==xa)))){
            passos = disx+disy+2;
            cout<< passos<<endl;
        }else{
            passos = disx+disy;
            cout<< passos<<endl;
        }

    }

    return 0;
}