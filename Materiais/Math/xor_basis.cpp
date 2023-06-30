// Xor Basis: encontra a base geradora mínima necessária 
// pra formar todos os subsets necessários

// Problema: ache o numero de maneiras de escolher subsets, 
// tal que o produto deles é igual ao quadrado de algum inteiro
struct Basis {
  vector<int> B;
  int reduce(int x) {
    for (auto b : B) x = min(x, x^b);
    return x;
  }
  void insert(int x) {
    int r = reduce(x);
    if (r) B.push_back(r);
  }
};

bool isPrime[75];
 
vector<int> generate_primes() {
    vector<int> primes;
    isPrime[1]=isPrime[0]=1;
    for(int i=2; i<=70; i++){
        if(!isPrime[i]){
            primes.pb(i);
            for(int j=i+i; j<=70; j+=i){
                isPrime[j]=1;
            }
        }
    }
    return primes;
}
 
int fast_exp(int base, int e, int m){
    if(!e) return 1;
    int ans = fast_exp(base * base % m, e/2, m);
    if(e % 2) return base * ans % m;
    else return ans;
}
 
int32_t main(){sws;
    int n; cin>>n;
    vector<int> v(n);
    input(v);
 
    vector<int> primes = generate_primes();

    Basis b;
    for(int i=0; i<n; i++){
        int x = v[i];
        int mask = 0;
        for(int j=0; j<(int)primes.size() and x>1; j++){
            int count=1;
            while(x%primes[j] == 0){
                count++;
                x/=primes[j];
            }
            if(count%2==0) mask |= (1<<j);
        }
        b.insert(mask);
    }
    int sz = b.B.size();
    cout<<fast_exp(2, n-sz, MOD)-1<<endl;
 
    return 0;
}