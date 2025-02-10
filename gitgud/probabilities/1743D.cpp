#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    
    int i = 0;

    while(i < n && s[i] == '0'){
        i++;
    }

    if(i == n){
        cout << "0" << endl;
        return 0;
    }

    s = s.substr(i);
    n = (int) s.size();

    i = 1;

    while(i < n && s[i] == '1'){
        i ++;
    }

    if(i == n){
        cout << s << endl;
        return 0;
    }

    int sz_sub = n - i;
    int k = n - sz_sub;

    vector<int> v(k, 0);

    for (int a = 0; a < sz_sub;a++)
    {
        if(s[n - sz_sub + a] == '1') continue;
        int qtd = 0;
        for (int b = 0; b < k; b++)
        {
            if(v[b]) continue;
            if(s[a + b] == '1') qtd++;
        }
        for (int b = 0; b < k; b++)
        {
            if(v[b]) continue;
            if(qtd && s[a + b] == '0')v[b] = 1;
        }

        if(qtd == 1) break;
    }
    
    int p;
    for (int j = 0; j < k; j++)
    {
        if(!v[j]) p = j;
    }
    
    string c = s.substr(p, sz_sub);

    string ans;

    for (int j = 0; j < sz_sub; j++)
    {
        int a = n - j - 1;
        int b = sz_sub - j - 1;
        if(c[b] == '1' || s[a] == '1') ans += '1';
        else ans += '0';
    }

    for (int j = 0; j < n - sz_sub; j++)
    {
        int a = n - j - 1 - sz_sub;
        ans += s[a];
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}