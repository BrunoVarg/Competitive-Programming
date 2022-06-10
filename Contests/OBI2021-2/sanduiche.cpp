#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall sanduiche.cpp -o sanduiche

int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
    }
    int comb=1;
    for(int i=1; i<=n; i++){
        comb*=i;
    }
    int soma =0;
    int comb2=1;
    for(int i=1; i<=n; i++){
        for(int j=i; j<=1; j--){
            comb2*=j;
        }

        soma+=comb/(comb2*(n-i));
    }

    cout<<soma<<endl;
    

    return 0;
}