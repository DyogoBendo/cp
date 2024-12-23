#include <bits/stdc++.h>

using namespace std;

const int infinito = 0x3f3f3f3f;
//Como não podemos representar um infinito literal, usaremos um número que é garantidamente mais alto que qualquer valor
//que possamos encontrar durante o problema
//Esse valor em hexadecimal é aproximadamente 1.6*10^9. Você pode usar outros valores de infinito, mas
//tome cuidado para não escolher um valor muito grande que pode gerar overflows, ou um muito pequeno que não será maior que
//algum valor no seu código.

int O, C;
int V[105], P[105];
int memo[105][20005];

int dp(int i, int p){
    if(p < 0 || p > C) return -infinito;
    if(i == 0) {
    	if(p == 0) return 0;
    	else return -infinito;
    }
    if(memo[i][p] != -1) return memo[i][p];
    return memo[i][p] = max(dp(i-1, p), V[i] + dp(i-1, p+P[i]));
}