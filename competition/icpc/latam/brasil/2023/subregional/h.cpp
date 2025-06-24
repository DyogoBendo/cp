    #include <bits/stdc++.h>
    using namespace std;

    #define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
    #define endl '\n'
    #define ll long long
    #define int long long


    signed main(){
        darvem;
        int n, s;
        cin >> n >> s;        

        vector<tuple<int, int, int>> v;  
        vector<tuple<int, int, int>> original;
        for (int i=1; i<=n; i++){
            int a, b, c;
            cin >> a >> b >> c;
            
            v.push_back({a, -i, c});
            v.push_back({b, i, c});
            original.push_back({a, b, c});
        }    

        sort(v.begin(), v.end());

        set<pair<int, int>> open;
        vector<int> st(n+1);
        int ans = 0;

        for (auto [pos, idx, c] : v)
        {        
            if(idx < 0){
                idx = -idx;
                int bst = ans;
                if(open.size()){
                    bst =max(ans, open.rbegin()->first + (pos - 1) * s);
                }
                int base = bst - c - (pos - 1) * s;
                st[idx] = base;
                open.insert({base, idx});
                st[idx];
            } else{            
                int bst = open.rbegin()->first + (pos) * s;
                ans = max(ans, bst);

                open.erase({st[idx], idx});
            }   
        }

        cout << ans << endl;
    }