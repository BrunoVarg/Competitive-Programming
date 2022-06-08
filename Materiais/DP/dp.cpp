// DP - PROGRAMAÇÃO DINÂMICA

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 110;

int n;
int tab[MAX];
vi v;

ll dp(int i){
    if(i>=n) return 0;
    if(tab[i] != -1) return tab[i];

    int pega = v[i] + dp(i+2);
    int npega = dp(i+1);

    tab[i] = max(pega, npega);
    return tab[i];
}

int main(){ sws; 
    memset(tab, -1, sizeof(tab));
    cin>>n;

    v.assign(n, 0);

    cout<<dp(0)<<endl;


    return 0;
}
