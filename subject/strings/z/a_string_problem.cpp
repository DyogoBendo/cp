#include <bits/stdc++.h>

using namespace std;

#define int long long

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> v(n);    
 
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {        
        if(i > r){
            l = r = i;            
            while(r < n && s[r - l] == s[r]) r ++;
 
            v[i] = r - l;
            r --;
        } else{
            int k = i - l;
 
            if(v[k] < r - i + 1){
                v[i] = v[k];          
            } else{
                l = i;
                while(r < n && s[r - l] == s[r]) r++;
                v[i] = r - l;
                r --;
            }
        }        
    }
    return v;
}


void solve(){
    string s;
    cin >> s;
    int n = s.size();

    vector<int> non_a(n, n);

    for (int i = n - 1; i >= 0; i--)
    {
        if(s[i] != 'a') non_a[i] = i;
        else if(i < n - 1) non_a[i] = non_a[i + 1];
    }
    

    string s2 = "";
    int first_non_a = non_a[0];

    if(first_non_a == n){
        cout <<  n - 1 << endl;
        return;
    }

    for (int i = first_non_a; i < n; i++)
    {
        s2 += s[i];
    }

    vector<int> z = z_function(s2);

    
    
    int ans = 0;
    // verificamos cada tamanho possível 
    for(int len = 1; first_non_a + len <= n; len ++){
        int curr = first_non_a + len;
        int max_a_before = first_non_a;
        int possible = 1;

        while(curr < n){
            if(non_a[curr] == n)break;
            int a_between = non_a[curr] - curr; 

            max_a_before = min(max_a_before, a_between);

            curr += a_between;

            if(z[curr - first_non_a] < len){
                possible = 0;
                break;
            }
            curr += len;
        }
        if(possible) ans += max_a_before + 1;
    }

    cout << ans << endl;

}

signed main(){
    flash;
    int t;
    cin >> t;
    while(t--) solve();
}