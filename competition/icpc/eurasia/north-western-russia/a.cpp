#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double

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

#define MAX 1000007

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<tuple<char, int, string>> instructions;
    vector<int> async_equals;
    int lst_equal = -1;

    for(int i = 0; i < n; i++){
        char op;
        int val;
        string tp;
        cin >> op >> val >> tp;

        if(op == '='){
            lst_equal = i;
            if(tp == "async") async_equals.push_back(val);
        }
        instructions.push_back({op, val, tp});
    }

    if(lst_equal == -1){
        cout << 1 << endl;
        return 0;
    }

    vector<int> ssum(n+1);
    for(int i = n-1; i > lst_equal; i--){
        ssum[i] = ssum[i+1] + get<1>(instructions[i]);
    }

    bitset<MAX> ans, dp, cnt, dp2, tmp;
    ans.reset(); dp.reset(); cnt.reset(), dp2.reset();
    dp.set(0); 

    ans.set(ssum[lst_equal+1]);

    for(int i = lst_equal + 1; i < n; i++){
        // if we position in front of this value, it will be removed, or be optional if it is async
        if(get<2>(instructions[i])== "async"){
            dp |= (dp << get<1>(instructions[i])); // so any combination we had before, can have this one (that is adding is shift and not adding is what there was before)
        }
        ans |= (dp << ssum[i+1]); // so the new final values that can be achieved are the suffix sum we are obligeated to take and all ours dp options
    }

    dp2.set(0);
    for(int i = 0; i < lst_equal; i++){
        if(get<0>(instructions[i]) == '+' and get<2>(instructions[i]) == "async"){
            ans |= (ans << get<1>(instructions[i]));
            dp2 |= (dp2 << get<1>(instructions[i])); 
        }
    }

    // all the async equals can be used at any of the combinations before
    for(auto x : async_equals){
        cnt |= (ans << x);
    }

    // if the last equal is actually a sync one, it can only combine of the suffix
    cnt |= dp2 << (get<1>(instructions[lst_equal])+ ssum[lst_equal+1]);

    cout << cnt.count() << endl;
    return 0;
}