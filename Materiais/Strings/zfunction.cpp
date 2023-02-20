// complexidades
// z - O(|s|)
// match: O(|s|+|p|)
vector<int> z_func(string s){
    int n = s.size();
    vector<int> z(n);
    int l=0, r=0;
    for (int i = 1, i < n; i++) {
        if (i <= r)
            z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
// string matching
// quantas vezes B aparece em A
int32_t main(){ sws; 
    string a, b;
	cin>>a>>b;

	string s = b + '$' + a;
	vector<int> z = z_func(s);
	int ans = 0;
	for(int i=0; i<z.size(); i++){
		if(z[i] == b.size())ans++;
	}
	cout<<ans<<endl;

    return 0;
}

 