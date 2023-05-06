int tab[20][2][12][2];
int dp(int idx, bool menor, int ant, bool zero, string &digits){
    if(idx >= (int)digits.size()){
        return 1;
    }
    if(tab[idx][menor][ant][zero] != -1) return tab[idx][menor][ant][zero];
    int ans = 0;
    int k = menor ? digits[idx]-'0' : 9;
 
    for(int i=0; i<=k; i++){
        bool menornow = digits[idx]-'0' == i ? menor : false;
        if(ant != i or (i==0 and zero)) ans += dp(idx+1, menornow, i, i==0 ? zero:false, digits);
    }
    return tab[idx][menor][ant][zero] = ans;
}
 
int32_t main(){ sws;
    int a, b;
    cin>>a>>b;
    memset(tab, -1, sizeof(tab));
    string b_s = to_string(b);
    int ba = dp(0, true, 11, true, b_s);
    int aa = 0;
    if(a > 0){
        memset(tab, -1, sizeof(tab));
        string a_s = to_string(a-1);
        aa = dp(0, true, 11, true, a_s);
        cout<<ba-aa<<endl;
    }else{
        cout<<ba<<endl;
    }
}