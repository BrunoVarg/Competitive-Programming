#include <bits/stdc++.h>
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main (){ sws;
    int n;
    char c;
    cin>> n;
    vector<int>v(10,0);
    for(int i=0; i< n; i++){
        cin>> c;
        if (c=='L'){
            for(int j=0; j<10; j++){
                if(v[j] == 0){
                    v[j] = 1;
                    break;
                }
            }
        }else if(c == 'R'){
            for(int j=9; j>=0; j--){
                if(v[j] == 0){
                    v[j] = 1;
                    break;
                }
            }
        }else {  
            int a = c- '0' ;    
            v[a]=0;      
        }
    }
    for(int i=0; i<10; i++){
        printf("%d", v[i]);
    }
}