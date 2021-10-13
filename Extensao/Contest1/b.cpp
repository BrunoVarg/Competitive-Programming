#include <bits/stdc++.h>
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main (){sws;
    int n,a,b,count=0;
    cin>> n;
    for(int i=0; i<n; i++){
        cin>> a>>b;
     
        while(true){
            if(a==b){
                break;
            }
            if(a>b){
                if (a-5 >= b){
                    a-=5;
                    count++;
                }
                else if (a-2 >= b){
                    a-=2;
                    count++;
                }
                else if (a-1 >= b){
                    a-=1;
                    count++;
                }
            }else{
                if (a+5 <= b){
                    a+=5;
                    count++;
                }
                else if (a+2 <= b){
                    a+=2;
                    count++;
                }
                else if (a+1 <= b){
                    a+=1;
                    count++;
            }
        }
    }
    cout<<count<<endl;
    count=0;


}