#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall a.cpp -o a

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
    while(n--){
        int size, conta=0, num;
        cin >> size;
        string s;
        cin>> s;
        bool passa = false;
        int contou=0;
        vector<char> v(size);
        for(int i=0; i<size; i++){
            v[i] = s[i];        
            if ((v[i] == '8') && (contou==0)){
                num=conta;
                contou++;
                passa = true;
            }           
            conta++;
        }    

        if(passa == false || size<11){
            cout<<"NO"<<endl;
        }else {
            int calc = size-num;
            if (calc>=11){
                cout<< "YES"<<endl;
            }else{
                cout<< "NO"<<endl;
            }
            
        }
    }

    return 0;
}