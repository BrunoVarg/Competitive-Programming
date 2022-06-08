// OPERAÇÕES BITWISE

#include <bits/stdc++.h>
using namespace std;


// Verificar se o bit esta ligado
bool isSet(int bitPosition, int number) {
  	bool ret = ((number & (1 << bitPosition)) != 0);
  	return ret;
}

// Ligar o bit
bool setBit(int bitPosition, int number) {
  	return (number | (1 << bitPosition) );
}

// Gerando todos os subconjuntos de um conjunto em binario
void possibleSubsets(char S[], int N) {
    for(int i = 0;i < (1 << N); ++i) {  // i = [0, 2^N - 1]
        for(int j = 0;j < N;++j)
            if(i & (1 << j))  // se o j-ésimo bit de i está setado, printamos S[j]
                cout << S[j] << ‘ ‘;
        cout << endl;
    }
}

