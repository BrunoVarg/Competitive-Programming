#include <bits/stdc++.h>
using namespace std;

const int MAX = (2e5+5)*30;


class Trie{
    int trie[MAX][2], pref[MAX];

    int node = 1;

    public:
    void add(int num){
        int cur = 1;
        for(int i=30; i>=0; i--){
            int bit = ((num &(1<<i)) >= 1);
            if(!pref[trie[cur][bit]]) trie[cur][bit] = ++node;
            cur = trie[cur][bit];
            pref[cur]++;
        }
    }
        
    void erase(int num){
        int cur = 1;
        for(int i=30; i>=0; i--){
            int bit = ((num &(1<<i)) >= 1);
            cur = trie[cur][bit];
            pref[cur]--;
        }
    }

    int find(int num){
        int cur = 1;
        int ans = 0;
        for(int i=30; i>=0; i--){
            int bit = ((num &(1<<i)) >= 1);
            if(pref[trie[cur][bit^1]]){
                cur = trie[cur][bit^1];
                ans += 1<<i;
            }else
                cur = trie[cur][bit];
        }
        return ans;
    }
};