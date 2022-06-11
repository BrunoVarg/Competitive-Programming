#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define loop(i,a,n) for(int i=a; i < n; i++)

ll upperbound(ll maior, ll k, vector<ll> tabuas){
    ll mid = 0, l = 0, r = maior, count = 300; 
    ll aux;
    while((l < r) && (count--)){
        aux = 0;
        mid = (l+r)/2;
        loop(i,0,tabuas.size()){
            if(mid > 0){aux += (tabuas[i]/mid);}
        }
        if(aux >= k){l = mid;}
        else{r = mid;}
    }

    ll aux_2 = 0;
    loop(i,0,tabuas.size()){
        aux_2 += (tabuas[i]/(mid+1));
    }
    if(aux_2 >= k){return mid+1;}

    if(aux < k){
        int aux_2 = 0;
        loop(i,0,tabuas.size()){
            if(mid - 1 > 0){aux_2 += (tabuas[i]/(mid-1));}
        }
        if(aux_2 >= k){return mid-1;}
    }
    
    return mid;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie( NULL);
    cout.tie(NULL);
    int n; cin >> n;
    ll k; cin >> k;
    vector<ll> tabuas(n);
    ll maior = 0;
    loop(i,0,n){
        cin >> tabuas[i];
        maior = max(maior,tabuas[i]);
    }
    cout << upperbound(maior,k,tabuas);
}