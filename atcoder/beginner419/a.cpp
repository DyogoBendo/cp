#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
map<string, string> m = {{"red", "SSS"}, {"blue", "FFF"}, {"green", "MMM"}};

signed main(){
    darvem;

    string s;
    cin >> s;
    string ans = m[s];
    if(ans == "") ans = "Unknown";
    cout << ans << endl;
}