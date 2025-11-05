#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double
#define int long long

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{ cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

signed main(){
    darvem;

    int n;
    cin >> n;

    set<int> ans;
    if(n > 2)ans.insert(n-1);

    vector<int> to_check;
    for(int i = 2; i * i < n; i++){
        if(n % i == 0) to_check.push_back(n/i - 1);
        to_check.push_back(i);
    } 
    for(auto c : to_check){        
        vector<int> curr;
        int x = n;
        while(x){
            curr.push_back(x%c);
            x/=c;
        }
        bool equal = true;
        for(int j = 0; j <= sz(curr)/2; j++) if(curr[j] != curr[sz(curr) - j - 1]) equal = false;
        
        if(equal) ans.insert(c);        
    }    
    if(!sz(ans)) cout << "*";
    for(auto a  : ans) cout << a << " "; 
    cout << endl;
}

