#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>

int main(){ sws;  

    string s;
    int aberto=0,fechado=0;
    cin >> s;
    for(int i=0; i<s.size();i++){
        if(s[i] == '('){
            aberto++;
        } else if(s[i] == ')'){
            fechado++;
            if(fechado >aberto){
                cout << "nao"<<endl;
                return 0;
            }
        }
    }
    
    if(fechado == aberto){

        cout << "sim"<<endl;
    } else {
        cout << "nao" << endl;
    }
    

    return 0;
}