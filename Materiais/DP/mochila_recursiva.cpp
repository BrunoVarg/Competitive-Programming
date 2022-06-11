#include <bits/stdc++.h>
using namespace std;

const int maxn = 110, maxp = 1e5+10;

int v[maxn], p[maxn], n;
long long dp[maxn][maxp];
bool vis[maxn][maxp];

long long solve(int i, int P) {
	if(i == n+1) return 0; // caso base, nao ha mais itens para se considerar
	if(vis[i][P]) return dp[i][P];
	vis[i][P] = 1;
	
	// primeira possibilidade, nao adicionar o elemento
	dp[i][P] = solve(i+1, P);
	
	// segunda possibilidade, adicionar o elemento.
	// Lembrar de tirar o maximo com o valor ja calculado da primeira possibilidade
	if(P >= p[i])
		dp[i][P] = max(dp[i][P], solve(i+1, P - p[i]) + v[i]);
	
	return dp[i][P];
}

int main() {
	int C; scanf("%d %d", &n, &C);
	for(int i = 1; i <= n; i++)
		scanf("%d %d", &p[i], &v[i]);
	printf("%lld\n", solve(1, C));
}