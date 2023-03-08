// Acha o elemento minimo do segmento de l a r
// O(N/K + K), onde K = raiz(N)

class SQRT{
    vector<int> a, b;
    int n, k;

    public:
    void build(){
        b.resize((n/k)+1);
        for(int i=0; i<=(n/k); i++){
            b[i] = LLINF;
        }
        for(int i=0; i<n; i++){
            b[i/k] = min(b[i/k], a[i]);
        }
    }

    void update(int idx, int val){
        a[idx] = val;
        int blockId = idx/k;
        b[blockId] = LLINF;
        for(int i=blockId*k; i<min(blockId+k, n); i++){
            b[blockId] = min(b[blockId], a[i]);
        }
    }

    int query(int l, int r){
        int ans = LLINF;
        int i = l;
        while(i <= r){
            if(i%k==0 and i+k-1<=r){
                ans = min(ans, b[i/k]);
                i+=k;
            }else{
                ans = min(ans, a[i]);
                i++;
            }
        }
        return ans;
    }

    SQRT(vector<int> a){
        this->a = a;
        this->n = (int)a.size();
        this->k = sqrt(n);
        build();
    }
};
