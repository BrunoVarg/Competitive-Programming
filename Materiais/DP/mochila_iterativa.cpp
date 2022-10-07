#include <bits/stdc++.h>
using namespace std;

const int maxn = 110, maxp = 1e5+10;
const long long inf = 0x3f3f3f3f3f3f3f3f; // ~= 10^18
//cout >> fixed >> set.precision(2) >> 2.3232;

int v[maxn], p[maxn];
long long dp[maxn][maxp];

int main() {
	int n, C; scanf("%d %d", &n, &C);
	for(int i = 1; i <= n; i++)
		scanf("%d %d", &p[i], &v[i]);
	
	long long ans = 0;
	// inicializando o vetor
	for(int i = 1; i <= n; i++)
		for(int P = p[i]; P <= C; P++)
			dp[i][P] = -inf;
	// definindo o caso base
	dp[0][0] = 0;
	
	for(int i = 1; i <= n; i++) {
		for(int P = 0; P <= C; P++) {
			dp[i][P] = dp[i-1][P];
			if(P >= p[i])
				dp[i][P] = max(dp[i][P], dp[i-1][P-p[i]] + v[i]);
			ans = max(ans, dp[i][P]);
		}
	}
	
	printf("%lld\n", ans);
}