#include <bits/stdc++.h>

using namespace std;

vector<int> z_function(string s, int n){
    vector<int> z(n);

    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if(i > r){
            l = r = i;
            while(r < n && s[r - l] == s[r]) r++;
            z[i] = r - l;
            r --;
        } else{
            int k = i - l;

            if(z[k] < r - i){
                z[i] = z[k];
            } else{
                l = i;
                while(r < n && s[r - l] == s[r]) r++;
                z[i] = r - l;
                r --;
            }
        }
    }
    return z;
}

int check(vector<int> &z, int n, int v){
    int count = 1;    

    int i = v;
    while(i < n){
        if(z[i] >= v){            
            count ++;
            i += v;
        } else{
            i ++;
        }
    }

    return count;
}

void solve(){
    int n, l, r;
    string s;
    cin >> n >> l >> r >> s;    
    auto z = z_function(s, n);

    vector<int> ans(n + 1);
    const int E=ceil(sqrt(n));


    for (int k = 1; k <= E; k++)
    {
        int low = 0;
        int high = n;

        while(low < high){
            int mid = low + (high - low + 1) / 2;

            if(check(z, n, mid) >= k){
                low = mid;
            } else{
                high = mid - 1;
            }
        }
        ans[k] = low;
    }
    
    for (int len = 1; len <= E; len++)
    {
        int k = 1;

        for (int i = len; i < n;)
        {
            if(z[i] >= len){
                k ++;
                i += len;
            } else{
                i ++;
            }
        }
        ans[k]=max(ans[k], len);        
    }
    
    for (int i = n - 1; i >= 1; i--)
    {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    for (int i = l; i <= r; i++)
    {
        cout << ans[i] << " ";
    }

    cout <<  endl;
}

int main(){
    int t;
    cin >> t;

    while(t--) solve();
}