    #include <bits/stdc++.h>
    using namespace std;

    #define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
    #define endl '\n'
    #define ll long long
    #define int long long
    const int MOD = 1e9 + 7;
    const int MAX = 1e5 + 10;

    int fat[MAX], inv_fat[MAX];

    int fast_expo(int k, int x){
        int result = 1;

        while(x){        

            if(x % 2){
                result *= k;
                result %= MOD;
            }

            k*= k;
            k %= MOD;        
            x/=2;
        }
        return result;
    }

    int dividir(int a, int b){
        return a * fast_expo(b, MOD - 2) % MOD;
    }

    int comb(int a, int b){
        return fat[a] * inv_fat[b] * inv_fat[a - b];
    }

    void solve(){
        int a, b, k;
        cin >> a >> b >> k;

        int rows = (k * (a - 1) + 1) % MOD;
        int columns_tot = fast_expo(k, a);    

        int columns = (columns_tot * (b - 1))% MOD;
        
        
        cout << rows % MOD << " " << columns + rows << endl;
    }


    signed main(){
        fat[0] = 1;

        for (int i = 1; i < MAX; i++)
        {
            fat[i] = fat[i - 1] * i;
        }

        inv_fat[MAX-1] = dividir(1LL, fat[MAX-1]);
        for (int i = MAX-2; i >= 0; i--)
        {
            inv_fat[i] = inv_fat[i + 1] * i;
        }

        
        darvem;
        int t = 1;
        cin >> t;


        while(t--) solve();
    }