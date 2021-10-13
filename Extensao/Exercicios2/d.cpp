#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>

int main(){ sws; 

    int n,t, c, linha=0, menorci=10001, menortempo=10001, ans=-1;
    cin>> n>>t>>c;
    while(n--){
        linha++;
        int ti, di,ci, tempo,calculatempo;
        cin>> ti>> di>> ci;
        if (ci<=c){
            tempo = t-ti;
            // Menor tempo possível;
            // Se chegar no mesmo tempo, ele vai no que tiver menor ci;
            // Se tiver a mesma taxa de incidência, vai na que tiver menor index;
            if(tempo <=0){
                if(linha==1)menortempo = abs(tempo), menorci = ci, ans = linha;
                else if(abs(tempo)<menortempo) menortempo = abs(tempo), menorci = ci, ans = linha;
                else if(abs(tempo) == menortempo){
                    if(ci<menorci)menortempo = abs(tempo), menorci = ci, ans = linha;
                }
            }
            else{
                if (tempo > di){
                    if((tempo%di)==0)calculatempo = tempo/di;
                    else calculatempo = floor((tempo/di)+1);
                    
                    tempo = (calculatempo*di) - tempo;
                } else{
                    tempo = di-tempo;
                }
                
                if(linha==1)menortempo = tempo, menorci = ci, ans = linha;
                else if(tempo<menortempo) menortempo = tempo, menorci = ci, ans = linha;
                else if(tempo == menortempo){
                    if(ci<menorci)menortempo = tempo, menorci = ci, ans = linha;
                }
            }

            
        }

        
    }
    cout<< ans<<endl;

    return 0;
}