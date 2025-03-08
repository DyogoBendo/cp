#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void solve(){
    int n;
    string s;
    cin >> n;
    cin >> s;    

    char curr = '0';
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        if(s[i] != curr){
            if(curr != '0') cout << total << " " << curr << " ";
            curr = s[i];
            total = 1;
        } else total ++;
    }
    cout << total << " " << curr << endl;
}

signed main(){
    flash;
    solve();
}