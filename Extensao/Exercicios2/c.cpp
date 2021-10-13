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
    cin>> t;
    stack<int> s;
    stack<int> s1;
    while(t--){
        ll x;
        char c;
        cin>> c>> x;
        if (c == 'A'){
            s.push(x);
            if(s1.empty())s1.push(x);
            else{
                if(x>s1.top())s1.push(x);
                else(s1.push(s1.top()));
            }
        }
        else if(c == 'R'){
            s.pop();
            s1.pop();
        }
        else{
            if(s.empty()){
                cout <<0<<endl;
            } else {
                cout << s1.top() << endl;
            }
        }
    }

    return 0;
}