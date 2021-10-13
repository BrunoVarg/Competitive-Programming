#include <bits/stdc++.h>
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main (){ sws;
    int n, a, count=0,numb;
    vector<int> v;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a;
        v.push_back(a);    
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (v[i]%v[j]==0) {
                count++;
                numb = v[j];
                }
            }
        if(count == n){
        cout <<numb<<endl;
        return 0;
    }
          count=0;  
    }
    
    
    cout << -1<<endl;
}