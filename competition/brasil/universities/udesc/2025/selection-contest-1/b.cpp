#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin >> n;
    
    string s;
    cin >> s;

    vector<int> ap(26, -1);
    for (int i = 0; i < 26; i++)
    {
        for (int j = n-1; j >= 0; j--)
        {
            if(s[j] == 'a' + i){
                ap[i] = j;
                break;
            }
        }
    }
    bool found = false;
    for (int i = 0; i < 26; i++)
    {
        if(ap[i] == -1) continue;
        for (int j = 0; j < ap[i]; j++)
        {
            if(s[j] > 'a' + i){
                found = true;
                swap(s[j], s[ap[i]]);
                break;
            }
        }
        if(found) break;
    }
    
    cout << s << endl;
}

signed main(){
    int t=1;
    for (int i=0; i<t; i++) solve();
}