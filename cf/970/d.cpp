#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> p(n);
    vector<int> c(n, 0);
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];

        p[i]--;
    }

    string s;
    cin >> s;

    int k = 1;
    int j;
    for (int i = 0; i < n; i++)
    {
        j = i;
        if(c[j] == 0){
            int b = 0;
            while(c[j] == 0){
                c[j] = k;
                if(s[j] == '0') b++;
                j = p[j];
            }        
            ans.push_back(b);
            k ++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[c[i] - 1] << " ";
    }
    cout << endl;
    
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
}