#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("badmilk");
    int n, m, d, s;
    cin >> n >> m >> d >> s;

    vector<int> drinks, sicks;
    vector<tuple<int, int, int>> entries_d;
    vector<pair<int, int>> entries_s;

    for (int i = 0; i < d; i++)
    {
        int p, mi, t;
        cin >> p >> mi >> t;
        entries_d.push_back(make_tuple(p, mi, t));
    }

    for (int i = 0; i < s; i++)
    {
        int p, t;
        cin >> p >> t;
        entries_s.push_back({p, t});
    }
    
    int ans = 0;
    for (int mi = 1; mi <= m; mi++)
    {
        vector<pair<int, int>> tmp_entries;
        for (auto e : entries_d)
        {
            int p, mi_tmp, t;
            p = get<0>(e);
            mi_tmp = get<1>(e);
            t = get<2>(e);
            if(mi_tmp == mi) tmp_entries.push_back({p, t});
        }

        if(tmp_entries.size() != 0){
            bool possible1 = true;
            int count = 0;
            for (auto e : entries_s){
                int p, t;
                p = e.first;
                t = e.second;
                int possible2 = 0;

                for (auto tmp : tmp_entries){
                    int tmp_p, tmp_t;
                    tmp_p = tmp.first;
                    tmp_t = tmp.second;

                    if(tmp_p == p && tmp_t < t) possible2 = 1;
                }
                if(!possible2) possible1 = 0;
            }

            int a = 0;

            vector<int> p(n, 0);
            for (auto tmp : tmp_entries){
                int tmp_p, tmp_t;
                tmp_p = tmp.first;
                tmp_t = tmp.second;

                p[tmp_p - 1] = 1;
            }

            for(auto k : p) a += k;
            

            if(possible1) ans = max(a, ans);
            
        }
        
    }
    
    cout << ans << endl;
    
}