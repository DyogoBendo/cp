    #include <bits/stdc++.h>

    using namespace std;

    void solve(){
        int n;
        cin >> n;
        string s;
        cin >> s;

        if(s[0] == '1' || s[n-1] == '1'){
            cout << "YES" << endl;
            return;
        }
        
        for (int i = 1; i < n; i++)
        {
            if(s[i - 1] == s[i] && s[i] == '1'){
                cout << "YES" << endl;
                return;
            }
        }
        cout << "NO" << endl;
        
    }

    int main(){
        int t;
        cin >> t;
        while(t--) solve();
    }