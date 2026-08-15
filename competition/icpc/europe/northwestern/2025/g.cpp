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

signed main(){
    darvem;
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vector<tuple<int, int, int, int, int>> entries;    

    for(int i = 0; i < n; i++){
        // we can interpret moving down as adding an element to the left and moving right as adding an element to the right
        // there are v[i] - 1 previous element that were considered to be put on the left or on the right
        // if we want to put on the left and be in the correct position, it must exist i elements put in the left and v[i] - i elements put in the right
        // and after that, it will lead it to the state (i+1, v[i]-i)
        pair<int, int> l_st =  make_pair(i, v[i] - i-1);
        pair<int, int> l_en = make_pair(i+1, v[i] - i-1);

        // as to the right, it is similar: 
        // if it must be placed correctly, there must be n - i - 1 elements in the right and consequently v[i] - (n - i - 1) in the left
        // leading to the state (v[i] - (n - i - 1), n - i)
        pair<int, int> r_st = make_pair(v[i] -1 - (n - i -1), n - i - 1);
        pair<int, int> r_en = make_pair(v[i] -1 - (n - i -1), n - i);
        if (l_st.first >= 0 && l_st.second >= 0 && l_en.first >= 0 && l_en.second >= 0) {
            entries.emplace_back(l_st.first, l_st.second, 1, i, 0);
            entries.emplace_back(l_en.first, l_en.second, 0, i, 0);
        }
        if (r_st.first >= 0 && r_st.second >= 0 && r_en.first >= 0 && r_en.second >= 0) {
            entries.emplace_back(r_st.first, r_st.second, 1, i, 1);
            entries.emplace_back(r_en.first, r_en.second, 0, i, 1);
        }
    }


    sort(entries.begin(), entries.end());
    vector<int> bst_l(n), bst_r(n), ly(n), ry(n);
    vector<int> lis;

    for (auto[x, y, op, idx, t] : entries){
        if(op == 1){
            auto it = upper_bound(lis.begin(), lis.end(), y);
            if(t == 0) bst_l[idx] = it - lis.begin(), ly[idx] = y;
            else bst_r[idx] = it - lis.begin(), ry[idx] = y;            
        } else{
            if(t == 0){
                if(bst_l[idx] == sz(lis)) lis.push_back(y);
                else lis[bst_l[idx]] = min(y, lis[bst_l[idx]]);
            } else{
                if(bst_r[idx] == sz(lis)) lis.push_back(y);
                else lis[bst_r[idx]] = min(y, lis[bst_r[idx]]);
            }
        }
    }

    cout << n - sz(lis) << endl;
}