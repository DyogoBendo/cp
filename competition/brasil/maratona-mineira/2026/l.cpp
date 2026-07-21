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

long long total_cost = 0;
vector<int> seq;

void build(int start, int length) {
    if (length == 0) {
        return;
    }
    if (length == 1) {
        seq.push_back(start);
        return;
    }
    
    int left_len = length / 2;
    int right_len = length - 1 - left_len;
    
    int root_pos = start + left_len;
    
    build(start, left_len);
    build(root_pos + 1, right_len);
    
    total_cost += (length - 1);
    seq.push_back(root_pos);
}

int main() {
    darvem;
    
    int n, c;
    cin >> n >> c;
    int k = n - c;
    int p = k + 1;
    
    int div = c / p;
    int q = c % p;
    
    seq.reserve(c);
    
    int curr_start = 1;
    for (int i = 0; i < p; ++i) {        
        int sz = (i < q) ? (div + 1) : div;
        
        if (sz > 0) {
            build(curr_start, sz);
            curr_start += sz + 1;  
        } else {
            curr_start += 1;     
        }
    }
        
    cout << total_cost << "\n";
    for (int i = 0; i < c; ++i) {
        cout << seq[i] << (i == c - 1 ? "" : " ");
    }
    cout << "\n";
    
    return 0;
}