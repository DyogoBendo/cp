#include <bits/stdc++.h>

using namespace std;

int n, k;
pair<int, string> check1(vector<pair<int, int>> blocks){
    vector<int> oc(26, 0);
    int n = blocks.size();

    int l = 0, r = 0, ans = 0, total = 0;
    int st = -1, en = -1;
    while(r < n){
        oc[blocks[r].second] += blocks[r].first;
        int curr = oc[blocks[r].second];
        while(curr > k){
            total -= blocks[l].first;
            oc[blocks[l].second] -= blocks[l].first;

            if(blocks[l].second == blocks[r].second) curr -= blocks[l].first;
            l++;
        }
        if(total > ans){
            ans = total;
            st = l;
            en = r;
        }        
        r ++;        
    }

    string s = "";
    for (int i = st; i <= en; i++)
    {
        for (int j = blocks[i].first; j; j--)
        {
            char c = blocks[i].second + 'a';
            s += c;
        }
        
    }
    
    return {ans, s};
}

tuple<int, string> check2(vector<pair<int, int>> blocks){
    vector<int> oc(26, 0);
    int ans = 0;
    int n = blocks.size();

    int total = 0;
    int prefix_end = 0;
    while(prefix_end < n){
        oc[blocks[prefix_end].second] += blocks[prefix_end].first;
        int curr = oc[blocks[prefix_end].second];
        total += blocks[prefix_end].first;
        if(curr > k) break;
        ans = total;

        prefix_end++;
    }
    if(prefix_end == n) return {ans, 0, prefix_end - 1};

    oc[blocks[prefix_end].second] -= blocks[prefix_end].first;
    prefix_end --;
    int suffix_begin = n - 1;    
    int st = -1, en = -1;
    while(suffix_begin >= 0){
        oc[blocks[suffix_begin].second] += blocks[suffix_begin].first;                
        while(oc[blocks[suffix_begin].second] > k && prefix_end >= 0){
            oc[blocks[prefix_end].second] -= blocks[prefix_end].first;
            total -= blocks[prefix_end].first;
            prefix_end --;
        }        
        if(oc[blocks[suffix_begin].second] > k) break;
        if(total > ans){
            ans = total;
            st= prefix_end;
            en = suffix_begin;
        }
        ans = max(ans, total);
        
        suffix_begin--;
    }

    string s = "";
    for

    return ans + 1;
}

void solve(){
    cin >> n >> k;

    string s;
    cin >> s;

    bool all_equal = true;

    for (int i = 0; i < n - 1; i++)
    {
        if(s[i] != s[i + 1]) all_equal = false;
    }
    
    if(all_equal){
        cout << -1 << endl;
        return;
    }

    int i = 0;
    for (; s[i] == s[n - 1]; i++)
    {
        s.push_back(s[i]);
    }
    
    s = s.substr(i);
    vector<pair<int, int>> blocks;
    for (int i = 0; i < n; i++)
    {        
        int j;
        for(j = i; j < n && s[j] == s[i]; j++);
        blocks.push_back({j - i, s[i] - 'a'});
    }
    
    cout << max(check1(blocks), check2(blocks)) << endl;
}

signed main(){
    int t;
    t = 1;

    while(t--) solve();
}