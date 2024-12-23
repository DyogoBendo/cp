#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = (1e9 + 7);

using matrix = array<array<int, 4>, 4>;

matrix mult(matrix a, matrix b){
    matrix ans = {{{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                ans[i][j] += (a[i][k] *b[k][j]);
                ans[i][j] %= MOD;
            }            
        }
        
    }

    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;

    matrix base = {
        {
            {1, 0, 0, 1},
            {0, 0, 0, 1},
            {0, 1, 0, 2},
            {0, 0, 1, 3}
        }
    };

    matrix result = {
        {
            {1, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 1}
        }
    };

    while(k){
        if(k & 1){
            result = mult(result, base);
        }

        base = mult(base, base);

        k /= 2;

    }
    
    int ans = 0;

    int v[] = {3, 1, 2, 3};    

    for (int i = 0; i < 4; i++)
    {
        ans += (v[i] * result[i][1]) % MOD;
    }
    
    cout << ans << endl;
    
}