#include <bits/stdc++.h>
using namespace std;
//g++ -std=c++17 -O2 -Wall x.cpp -o x

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(msg, x) cout << msg << " = " << x << endl
#define pb push_back
#define ff first
#define ss second
const int oo 100000000;
typedef long long ll;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;


int main(){ sws; 

   int n, m;
   cin>>n>>m;

   vector<vector<int>> dist(n+1, vector<int> (n+1));

   for(int i=0; i<n+1; i++){
       for(int j=0; j<n+1; j++){
           dist[i][j] = oo;
       }
   }

   for(int i=0; i<n +1; i++){
       dist[i][i]=0;
   }

   for(int i=0; i<m; i++){
       int comeca, termina, custo;
       cin>>comeca>>termina>>custo;

        // grafo direcionado
       dist[comeca][termina] = custo;
   }

   for(int k=1; k<=n; k++){ // intermediario
       for(int i=1; i<=n; i++){
           for(int j=1; j<=n; j++){
               //(i,k,j) = ir de i pra j passando por k;

               // relaxar distancia de i pra j
               dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
           }
       }
   }





    return 0;
}