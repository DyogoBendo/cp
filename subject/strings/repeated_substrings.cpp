#include <bits/stdc++.h>

using namespace std;

struct suffix_array {
    struct entry {
        pair<int, int> nr;
        int p;

        bool operator <(const entry &other) const {
            return nr < other.nr;
        }
    };

    string s;
    int n;
    vector<vector<int> > P;
    vector<entry> L;
    vector<int> idx;

    suffix_array(string _s) : s(_s), n(s.size()) {
        L = vector<entry>(n);
        P.push_back(vector<int>(n));
        idx = vector<int>(n);

        for (int i = 0; i < n; i++) {
            P[0][i] = s[i];
        }

        for (int stp = 1, cnt = 1; (cnt >> 1) < n; stp++, cnt <<= 1) {
            P.push_back(vector<int>(n));
            for (int i = 0; i < n; i++) {
                L[i].p = i;
                L[i].nr = make_pair(P[stp - 1][i],
                        i + cnt < n ? P[stp - 1][i + cnt] : -1);
            }

            sort(L.begin(), L.end());
            for (int i = 0; i < n; i++) {                
                if (i > 0 && L[i].nr == L[i - 1].nr) {                                        
                    P[stp][L[i].p] = P[stp][L[i - 1].p];
                } else {
                    P[stp][L[i].p] = i;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            idx[P[P.size() - 1][i]] = i;
        }
    }

    int lcp(int x, int y) {
        int res = 0;
        if (x == y) return n - x;
        for (int k = P.size() - 1; k >= 0 && x < n && y < n; k--) {
            if (P[k][x] == P[k][y]) {
                x += 1 << k;
                y += 1 << k;
                res += 1 << k;
            }
        }
        return res;
    }
};

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        suffix_array sa = suffix_array(s);

        int current = 0;
        int ans = 0;
        for (int k = 1; k < s.size(); k++)
        {
            int a = sa.idx[k- 1];
            int b = sa.idx[k];

            int l = sa.lcp(a, b);            

            ans += max(0, l - current);
            current = l;                            
        }
        cout << ans << endl;
        
    }
    
}