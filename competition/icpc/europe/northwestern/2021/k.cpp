#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;
    int n;
    cin >> n;

    int tot = 0;

    map<string, int> cntl, cntr, cnta;
    set<string> all;

    for (int i = 0; i < n; i++)
    {
        string a, b;
        int c;
        cin >> a >> b;
        cin >> c;

        if(b == "right") cntr[a] +=c;
        else if(b == "left") cntl[a] += c;
        else cnta[a] += c;
        tot += c;
        all.insert(a);
    }

    int ans = 1, found = 0;
    for(auto s : all){
        int l = cntl[s], r = cntr[s], a = cnta[s];        
        if((a > 1) or l+r+a - max({l, r, a})) found = true;

        ans += max({l, r, min(a, 1)});
    }
    
    cout << (found ?  to_string(ans): "impossible") << endl;

}