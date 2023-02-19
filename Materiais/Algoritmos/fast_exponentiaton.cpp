// recursivo
int fast_exp(int base, int e, int m){
    if(!e) return 1;
    int ans = fast_exp(base * base % m, e/2, m);
    if(e % 2) return base * ans % m;
    else return ans;
}
//iterativo
int fast_exp(int base, int e, int m) {
	int ret = 1;
	while (e) {
		if (e & 1) ret = (ret * base) % m;
		e >>= 1;
		base = (base * base) % m;
	}
	return ret;
}