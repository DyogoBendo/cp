#include <bits/stdc++.h>
using namespace std;

signed main(){
    
    int n;
    cin >> n;
    vector<vector<string>> names;
    names.resize(n);
    for (int i=0; i<n; i++){
        int c;
        cin >> c;
        for (int j=0; j<c; j++){
            string s;
            cin >> s;
            names[i].push_back(s);
        }
        sort(names[i].begin(), names[i].end());
    }

    string last="A";
    vector<string> ans;
    bool can=true;
    for (int i=0; i<n; i++){
        if (last > names[i].back()){
            can = false;
            break;
        }
        for (int j=0; j<names[i].size(); j++) if (last <= names[i][j]){
            last = names[i][j];
            ans.push_back(names[i][j]);
            break;
        }
    }

    if (can){
        for (auto a: ans) cout << a << '\n';
    }
    else cout << "impossible\n";
}