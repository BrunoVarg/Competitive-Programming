#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>

int main(){ sws;   

    int t;
    cin >> t;
    while(t--){
        int size,inicio=0;
        cin >> size;
        stack<pii> sp;
        vi v(size);
        vi ans;
        for(int i=0; i< size; i++){
            cin >> v[i];
            if(i==0) sp.push(mp(v[i], v[i]));
            else if(v[i]>sp.top().second)sp.push(mp(v[i], v[i]));
            else if(v[i]<sp.top().second)sp.push(mp(v[i],sp.top().second));
        }
        for(int i=size-1; i>=0; i--){
            if(i==size-1)inicio=size;
            if(v[i]==sp.top().second){  
                for(int j=i; j<inicio; j++){
                    ans.pb(v[j]);
                }
                inicio=i;
            }
            sp.pop();
        }

        for(int i=0; i<ans.size(); i++){
            if (i!=ans.size()-1)cout<< ans[i]<<" ";
            else cout<< ans[i]<<endl;
            
        }
    }
    
    return 0;
}