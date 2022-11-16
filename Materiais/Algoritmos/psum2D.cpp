

int psum[MAX][MAX];
 
int32_t main(){ sws; 
    int t; cin>>t;
    while(t--){
        memset(psum, 0, sizeof(psum));
        int n, q; cin>>n>>q;
        
        for(int i=0; i<n; i++){
            int x, y;
            cin>>x>>y;
            
            psum[x][y] += x*y;
        }
        
        for(int i=1; i<MAX; i++)
            for(int j=1; j<MAX; j++)
                psum[i][j] += psum[i-1][j];
            
        
        
        for(int i=1; i<MAX; i++){
            for(int j=1; j<MAX; j++){
                psum[i][j] += psum[i][j-1];
            }
        }
        
        for(int i=0; i<q; i++){
            int x1, y1, x2, y2;
            cin>>x1>>y1>>x2>>y2;
            x2--; y2--;
            
            int soma = psum[x1][y1] + psum[x2][y2] - psum[x2][y1] - psum[x1][y2];
            cout<<soma<<endl;
        }
    }
    return 0;
}