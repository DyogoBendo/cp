    #include <bits/stdc++.h>
    using namespace std;

    #define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
    #define endl '\n'
    #define ll long long
    #define int long long

    int calc_digits(ll x){
        int ans = 1;
        while(x > 10){
            x /= 10;
            ans ++;
        }
        return ans;
    }

    ll pow(int x, int k){    
        int ans = 1;
        while(k){
            ans *= x;
            k--;
        }
        return ans;
    }

    void solve(){
        int n;
        cin >> n;

        vector<int> v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        vector<ll> psum(n+1, 0);    

        for (int i = 0; i < n; i++)
        {
            psum[i+1] = (ll) psum[i] + v[i];
        }
        
        vector<vector<int>> psum7(n+1, vector<int>(10, 0));
        psum7[0][0] = 1;
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                psum7[i][j] = psum7[i-1][j];
            }           
            psum7[i][psum[i]%10]++;
        }    

        int ans= 0;
        for (int i = 1; i <= n; i++)
        {        
            // verificar quantidade que terminam com 7
            int d = psum[i] % 10;
            int search_d = (10 + d - 7) % 10;
            int en = psum7[i-1][search_d]; // quantos prefixos anteriores que terminam no digito que procuramos.         

            // verificar quantidade que começam com 7
            int st = 0, intersection = 0;
            int qtd_digits = calc_digits(psum[i]);
            while(qtd_digits){            
                int upper = 8 * pow(10, qtd_digits-1) - 1;
                int lower = 7 * pow(10, qtd_digits-1);

                int max_subtract = psum[i] - lower + 1;
                int min_sub = psum[i] - upper;            

                if(lower <= psum[i]){
                    int lower_idx = upper_bound(psum.begin(), psum.end(), min_sub) - psum.begin();
                    int upper_idx = upper_bound(psum.begin(), psum.end(), max_subtract) - psum.begin();                
                    st += max(0ll, upper_idx - lower_idx);

                    if(upper_idx > lower_idx){
                        int sub = lower_idx == 0 ? 0 : psum7[lower_idx-1][search_d]; 
                        intersection += psum7[upper_idx+1][search_d] - sub;
                    }                 
                }
                qtd_digits --;
            }        

            ans += en + st - intersection;
        }
        
        cout << ans << endl;
    }


    signed main(){
        darvem;
        int t = 1;
        //cin >> t;

        while(t--) solve();
    }