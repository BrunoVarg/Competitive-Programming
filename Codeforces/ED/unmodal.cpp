#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall unmodal.cpp -o unmodal

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
    cin>>n;
    vi arr(n);
    int inc=0, dec=n;
    bool pass = true;
    for(int i=0; i<n ; i++){
        cin >> arr[i];
    }

    for(int i=0;i<n-1; i++){
        if(arr[i+1]<=arr[i]){
            break;
        }
        inc++;
    }
    
    for(int i=n-1; i>=1; i--){
        if(arr[i-1]<=arr[i]){
            break;
        }
        dec--;
    }
    for(int i=inc; i<dec-2; i++){
        if(arr[i]!= arr[i+1]){
            pass=false;
        }
    }
    if(pass){
        cout<< "YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    return 0;
}