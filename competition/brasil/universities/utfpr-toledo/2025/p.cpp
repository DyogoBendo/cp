#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<string> ans;
    for(int i = 0; i < n; i++){
        string s = "";
        for (int j = 0; j < n; j++)
        {
            if(j < i) s.push_back(' ');
            else s+= "* ";
        }
        s.pop_back();
        ans.push_back(s);
    }
    reverse(ans.begin(), ans.end());
    for(auto s : ans) cout << s << endl;
    
}