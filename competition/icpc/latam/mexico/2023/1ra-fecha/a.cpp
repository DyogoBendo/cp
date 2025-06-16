#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void solve(){
    int n;
    cin >> n;
    set<string> ss1, ss2;    
    
    while(n--){
        int x;
        string s1, s2 = "";
        cin >> x;
        while(x--){
            cin >> s1;
            s2 += s1[0];
        }
        if(ss1.count(s2) && !ss2.count(s2))ss2.insert(s2);
        ss1.insert(s2);
    }
    
    cout << ss1.size() - ss2.size() << endl;
}

signed main(){
    flash;
    solve();
}