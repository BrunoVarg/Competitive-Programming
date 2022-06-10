#include <bits/stdc++.h>
using namespace std;
//g++ -std=c++17 -O2 -Wall falha.cpp -o falha


int main(){

    int n;
    cin>>n;
    vector<string> vs;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        vs.push_back(s);
    }
    int count=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i!=j){
                int tami = vs[i].size();
                int tamj = vs[j].size();
                int menor, maior, menoridx;
                if(tami>tamj) {
                    maior=i;
                    menor=tamj;
                    menoridx=j;
                }
                else if (tami<tamj){
                    maior=j;
                    menor=tami;
                    menoridx=i;
                }

                int minim = min(tami, tamj);
                for(int k=0; k<minim; k++){
                    if(vs[maior].substr(k, --menor) == vs[menoridx]){
                        count++;
                    }
                }

            }
        }
    }
    cout<<count<<endl;

    return 0;
}