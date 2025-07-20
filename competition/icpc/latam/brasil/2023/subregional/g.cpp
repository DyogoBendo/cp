    #include <bits/stdc++.h>
    using namespace std;

    #define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
    #define endl '\n'
    #define ll long long

    #define sq(x) ((x)*(ll)(x))

    struct pt { // ponto
        int x, y;
        pt(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
        bool operator < (const pt p) const {
            if (x != p.x) return x < p.x;
            return y < p.y;
        }
        bool operator == (const pt p) const {
            return x == p.x and y == p.y;
        }
        pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
        pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
        pt operator * (const int c) const { return pt(x*c, y*c); }
        ll operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y; }
        ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }
        friend istream& operator >> (istream& in, pt& p) {
            return in >> p.x >> p.y;
        }
    };

    ll sarea2(pt p, pt q, pt r) { // 2 * area com sinal
        return (q-p)^(r-q);
    }

    bool col(pt p, pt q, pt r) { // se p, q e r sao colin.
        return sarea2(p, q, r) == 0;
    }

    bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
        return sarea2(p, q, r) >= 0;
    }

    vector<int> convex_hull(vector<pair<pt, int>> v) { // convex hull - O(n log(n))
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        if (v.size() <= 1) return vector<int>(1, 1);
        vector<pair<pt, int>> l, u;
        for (int i = 0; i < v.size(); i++) {
            while (l.size() > 1 and !ccw(l.end()[-2].first, l.end()[-1].first, v[i].first))
                l.pop_back();
            l.push_back(v[i]);
        }
        for (int i = v.size() - 1; i >= 0; i--) {
            while (u.size() > 1 and !ccw(u.end()[-2].first, u.end()[-1].first, v[i].first))
                u.pop_back();
            u.push_back(v[i]);
        }	
        for (auto i : u) l.push_back(i);

        vector<int> ans;
        for(auto e : l) ans.push_back(e.second);

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }

    signed main(){
        darvem;

        int n;
        cin >> n;

        vector<pair<pt, int>> pts(n);
        for(int i = 0; i < n; i++){
            cin >> pts[i].first;
            pts[i].second = i+1;
        } 
        sort(pts.begin(), pts.end(), [](pair<pt, int> p, pair<pt, int> q){
            return p.first < q.first;
        });

        for (auto e : convex_hull(pts))
        {
            cout << e << " ";
        }
        cout << endl;    
    }