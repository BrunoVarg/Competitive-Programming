#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall sereja.cpp -o sereja

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

int main(){ sws; 

    int n, m, norepet=0;
    cin>> n>> m;
    int arr[MAX], visited[MAX], ans[MAX];

    for(int i=1; i<=n; i++){
        cin>> arr[i];
    }

    for(int i=n; i>=1; i--){
        if(visited[arr[i]] == 0) norepet++, visited[arr[i]] = 1;
        ans[i] = norepet;
        
    }

    for(int i=1; i<=m; i++){
        int y;
        cin>> y;
        cout<<ans[y]<<endl;
    }

    return 0;
}