#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall senha.cpp -o senha

int main(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<char> v;
    vector<char> val;
    vector<string> st;
    vector<char> ord;
    string senha;
    cin>>senha;
    for(int i=0; i<n; i++){
        char c = senha[i];
        if(c=='#')val.push_back(i);
        v.push_back(c);
    }
    for(int i=0; i<m; i++){
        string comb;
        cin>>comb;
        st.push_back(comb);
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<k; j++){
            for(int l=i; l<m; k++){
                char x = st[i][k];
                x+= st[l][k];
                ord.push_back(st[i][k]);
            }
        }
    }
    
}