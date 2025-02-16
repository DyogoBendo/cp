#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e2 + 10;

int dp[MAXN][MAXN][2][2]; // temos i pares, j impares, o jogador atual é bob/alice, alice tem uma quantidade par ou impar nessa posicao. 0 se chegamos nessa posição, 1 se sim

void calc(){

    dp[0][0][0][0] = 1; // se tiverem 0 pares e 0 impares, a alice for jogar agora e ela tem uma quantidade par, ela ganha
    dp[0][0][1][1] = 1; // se tiverem 0 pares e 0 impares, bob for jogar agora e alice tem uma quantidade impar, ele ganha

    for (int e = 0; e < MAXN; e++) // even
    {
        for (int o = 0; o < MAXN; o++) // odd
        {                        
            for (int p = 0; p < 2; p++) // current player
            {
                for (int q = 0; q < 2; q++) // alice has even(0) or odd(1) qtd
                {
                    if(e > 0)dp[e][o][p][q] = !dp[e - 1][o][p^1][q];
                    if(o > 0){
                        if(p == 0){
                            dp[e][o][p][q] = max<int>(dp[e][o][p][q], !dp[e][o - 1][p^1][q^1]);
                        } else{
                            dp[e][o][p][q] = max<int>(dp[e][o][p][q], !dp[e][o - 1][p^1][q]);
                        }
                    }
                }
                
            }
            
        }
        
    }

}

void solve(){
    int n;
    cin >> n;

    int odd = 0;
    int even = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x%2) odd++;
        else even ++;        
    }    

    if(dp[even][odd][0][0]){
        cout << "Alice" << endl;
    } else{
        cout << "Bob" << endl;
    }

}

signed main(){
    calc();
    int t;
    cin >> t;

    while(t--) solve();
}