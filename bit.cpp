#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+7;

int arvore[MAX];
int N;

int rsq(int x){
	
	int s = 0;
	
	while(x > 0){ // vamos reduzindo x até acabarmos (quando chegamos a zero)
		s += arvore[x]; // adicionamos o pedaço de árvore atual à soma
		x -= (x & -x);  // removemos o bit menos significante
	}
}

void update(int x, int v){ // adicionar v frutas a caixa x
	
	while(x <= N){ // nosso teto, que é quando vamos parar de rodar o algoritmo
		arvore[x] += v; // adicionamos v frutas a arvore[x], como devemos
		x += (x & -x);  // atualizamos o valor de x adicionado ele ao seu bit menos significante
	}
}