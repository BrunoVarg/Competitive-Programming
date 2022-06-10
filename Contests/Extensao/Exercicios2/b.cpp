#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>

int main(){ sws;  

    int n, q, t;    
    cin>> n>> q;
    vi v(n);
    for(int i=0; i<n; i++){
        cin>> v[i];
    }
    for(int i=0; i<q; i++){
        cin>> t;
        auto pos = find(v.begin(),v.end(), t) - v.begin();

        cout<< pos +1 << " ";
        // rotate = firstelement, middleelement, lastelement.
        // [2,1,1,4,3,3,1] -> x =3; pos = 4; [3,2,1,1,4,3,1]
        rotate(v.begin(), v.begin()+ pos, v.begin()+ pos + 1);
    }

    return 0;
}