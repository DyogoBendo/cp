#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void solve(){
    int n, t1 = 0, t2 = 0;
    cin >> n;

    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);        

        if(s[5] == '1') t1 += s.back() - '0';
        else t2 += s.back() - '0'; 
    }
    
    cout << t1 << " x " << t2 << endl;

}

signed main(){    
    solve();
}