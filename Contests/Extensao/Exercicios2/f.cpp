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
    int ans=0;
    int aux=0;
    stack<char> st;
    cin >> s;
    for(int i=0; i<s.size(); i++){
        if(st.empty()) st.push(s[i]);
        else{
            if(st.top() == 'r'){
                if(s[i] == '.') aux++;
                else if(s[i] == 's') aux = 0,st.pop(), st.push(s[i]);
                if ((s[i] == 'r') || ((i == s.size()-1) && (s[i]!='s')))ans+=aux, aux=0;
            }
            else st.pop(), st.push(s[i]);
        }
    }

    cout << ans <<endl;

    return 0;
}