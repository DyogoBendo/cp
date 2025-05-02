#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

string transform(const vector<string> &token) {
    unordered_map<string, int> last;
    string s;
    for (int i = 0; i < token.size(); i++) {
        string tok = token[i];
        if (tok.size() == 1 && isalpha(tok[0])) {
            if (last.count(tok)) s += to_string(i - last[tok]) + " ";
            else s += "0 ";
            
            last[tok] = i;
        } else s += tok + " ";
    }
    return s;
}

bool check(const string s, const string prefix) {
    if (prefix.size() > s.size()) return false;
    return s.substr(0, prefix.size()) == prefix;
}

signed main() {
    bieo;

    int n, q;
    cin >> n;

    vector<string> reference(n);
    for (auto &x : reference) cin >> x;

    vector<string> sufix;
    for (int i = 0; i < n; i++) {
        vector<string> token(reference.begin() + i, reference.end());
        sufix.push_back(transform(token));
    }

    // for (auto x : sufix) cout << x << endl;
    sort(sufix.begin(), sufix.end());

    cin >> q;
    while (q--) {
        int m;
        cin >> m;
        vector<string> query(m);
        for (auto &x : query) cin >> x;
        string tokq = transform(query);
        // cout << tokq << endl;

        auto it = lower_bound(sufix.begin(), sufix.end(), tokq);
        // cout << "pos " << sufix.end() - it << " string " << *it << endl;
        bool valid = false;
        if (it != sufix.end() && check(*it, tokq)) valid = true;
        
        cout << (valid ? "yes" : "no") << endl;
    }

    return 0;
}