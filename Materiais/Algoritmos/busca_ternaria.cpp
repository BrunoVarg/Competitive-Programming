// Uma busca em uma curva, avaliando dois pontos diferentes
// Complexidade: O(Nlog3N)

double check(vector<int> v, vector<int> t, double x){
	double ans = 0;
	for(int i=0; i<v.size(); i++){
		ans = max(ans, (double)(abs(v[i]-x) + t[i]));
	}
	return ans;
}

int32_t main(){ sws; 
 
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> v(n);
		vector<int> t(n);
		input(v);
		input(t);
 
		double ans = 0.0;
		double l=0.0, r=1e9;
		while(r-l >= EPS){
			
			double mid1 = (double) l + (r - l) / 3;
			double mid2 = (double) r - (r - l) / 3;
			
			double x1 = check(v, t, mid1);
			double x2 = check(v, t, mid2);
 
			if(x1 < x2){
				r = mid2;
			}else{
				l = mid1;
				ans = l;
			}
		}
		cout<<fixed<<setprecision(7);
		cout<<ans<<endl;
	}
    return 0;
}