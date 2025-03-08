#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'

using namespace std;

int letters[52];

int get_pos(char c){
    int p;
    if(islower(c)){
        p = c - 'a';
    } else{
        p = 26 + (c - 'A');
    }
    return p;
}

void solve(){
    int n;
    string s;
    cin >> n;
    cin >> s;

    set<char> diff;    

    for (char c: s) diff.insert(c);
    set<int> curr;    

    int l = 0, r = 0;
    int ans= n;
    while(l < n){
        while(r < n && curr.size() != diff.size()){
            curr.insert(s[r]);
            letters[get_pos(s[r])]++;
            r++;            
        }
        if(curr.size() == diff.size()) ans = min(ans, r - l);
        letters[get_pos(s[l])]--;
        if(!letters[get_pos(s[l])]) curr.erase(s[l]);
        l++;
    }

    cout << ans << endl;
}

signed main(){
    flash;
    int t = 1;    

    while(t--) solve();
}