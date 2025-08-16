#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n;
    cin >> n;
    string s;
    cin >> s;    

    ll ans = 0;
    ll zero = 0, one = 0;

    for(int i = n-1; i>=0; i--){
        if(s[i] == '0'){
            swap(zero, one);
            zero++;
        } else{
            one++;
        }
        ans += one;
    }
    cout << ans << endl;
}