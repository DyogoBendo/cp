#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int cnt=  0;
    bool possible = true;    
    string sa, sb;

    for (int i = 0; i < n; i++)
    {
        cnt += s[i] == '1';
    }

    if(cnt % 2 == 1 || s[0] == '0' || s.back() == '0') possible =false;

    int k = 0;
    bool flip = false;

    for (int i = 0; i < n; i++)
    {
        if(s[i] == '1'){
            sa.push_back(2*k < cnt ? '(' : ')');
            sb.push_back(sa.back());
            k++;
        } else{
            sa.push_back(flip ? '(' : ')');
            sb.push_back(!flip ? '(' : ')');
            flip ^= 1;
        }
    }
  
    if(possible){
        cout << "YES" << endl << sa << endl << sb << endl;
    } else{
        cout << "NO" << endl;
    }
    
}

signed main(){
    int t;
    cin >> t;

    while(t--) solve();
}