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

const int INF = 3;

template<typename T>
pair<int, vector<T>> gauss(vector<vector<T>> a, vector<T> b) {
	const double eps = 1e-6;
	int n = a.size(), m = a[0].size();
	for (int i = 0; i < n; i++) a[i].push_back(b[i]);

	vector<int> where(m, -1);
	for (int col = 0, row = 0; col < m and row < n; col++) {
		int sel = row;
		for (int i=row; i<n; ++i)
			if (abs(a[i][col]) > abs(a[sel][col])) sel = i;
		if (abs(a[sel][col]) < eps) continue;
		for (int i = col; i <= m; i++)
			swap(a[sel][i], a[row][i]);
		where[col] = row;

		for (int i = 0; i < n; i++) if (i != row) {
			T c = a[i][col] / a[row][col];
			for (int j = col; j <= m; j++)
				a[i][j] -= a[row][j] * c;
		}
		row++;
	}

	vector<T> ans(m, 0);
	for (int i = 0; i < m; i++) if (where[i] != -1)
		ans[i] = a[where[i]][m] / a[where[i]][i];
	for (int i = 0; i < n; i++) {
		T sum = 0;
		for (int j = 0; j < m; j++)
			sum += ans[j] * a[i][j];
		if (abs(sum - a[i][m]) > eps)
			return pair(0, vector<T>());
	}

	for (int i = 0; i < m; i++) if (where[i] == -1)
		return pair(INF, ans);
	return pair(1, ans);
}

signed main(){
    darvem;
    int m, n;
    cin >> m >> n;

    vector<vector<int>> a(m, vector<int>(n));
    vector<int> b(m);
    int clause_idx = 0;
    int nots = 0;    
    string s;

    while (cin >> s) {
        if (s == "and" || s == "or") continue;
        
        bool has_close = false;
        if (s.length() > 0 && s[0] == '(') {
            s = s.substr(1);
        }
        if (s.length() > 0 && s.back() == ')') {
            has_close = true;
            s.pop_back();
        }
        
        if (s == "not") {
            nots ^= 1;            
        } else if (s.length() > 0 && s[0] == 'x') {
            int var = stoi(s.substr(1)) - 1;
            a[clause_idx][var] = a[clause_idx][var] ^ 1;            
        }
        
        if (has_close) {            
            b[clause_idx] = 1^ nots;            
            clause_idx++;
            nots = 0;            
        }
    }

    auto calc = gauss(a, b);
    if(calc.first == 0){
        cout << "impossible" << endl;
        return 0;
    }
    string ans;
    for(int i = 0; i < sz(calc.second); i++) ans += calc.second[i] ? "T" : "F";
    cout << ans << "\n";
    return 0;
}
