#include <bits/stdc++.h>
using namespace std;
//g++ -std=c++17 -O2 -Wall festa.cpp -o festa
#define print(x) for (auto &it : x) cout << it << ' '

int main(){

    int n;
    cin>>n;

    vector<int> v(n+1);
    for(int i=1; i<=n; i++)v[i]=i;

    int q;
    cin>>q;
    for(int i=0; i<q; i++){
        int x;
        cin>>x;
        int geral=0;
        int count=0;
        for(int k=x; k<=n; k+=x){
            if(v[k]!=0){
                v[k]=0;
                count++;
            }
        }
        int aux=1;
        for(int j=1; j<=n; j++){
            if(v[j]>0){
                v[aux]=v[j];
                if(j>aux)v[j]=0;
                aux++;
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(v[i]>0){
            cout<<v[i]<<endl;
        }
    }

    return 0;
}