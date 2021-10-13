#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall teste.cpp -o teste

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
    int letra = 'a';
    while(n--){
        string x;
        cin>>x;
        vector<char> v(x.size());
        char esquerda = 'a';
        char direita = 'a';
        bool contem = false, yes=true;
        for(int i=0; i<x.size(); i++){
            v[i] = x[i];
            if(x[i]=='a'){
                contem = true;
            }
        }

        auto inicio = find(all(v), 'a') -v.begin();
        if (contem==false){
            cout<<"NO"<<endl;
        }else{
            esquerda = inicio;
            direita = inicio;
            for(int i=0; i<v.size()-1; i++){
                if((esquerda!=0) && (v[esquerda-1] == letra+i+1)){
                    esquerda = esquerda-1;
                } else if((direita!=v.size()-1) && (v[direita+1] == letra+i+1)){
                    direita = direita+1;
                } else{
                    yes=false;
                    break;
                }
            }
            if(yes){
                cout<< "YES"<<endl;
            }else cout<<"NO"<<endl;

        }

        
    }

    return 0;
}