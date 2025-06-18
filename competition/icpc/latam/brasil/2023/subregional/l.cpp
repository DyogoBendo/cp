#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    string s;
    cin >> s;   

    int k, n = s.size();
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        vector<int> cnt(26);
        for (int j = i; j < n; j+=k)
        {
            cnt[s[j] - 'a']++;
        }
        int pos = i;
        for (int i = 0; i < 26; i++)
        {
            while(cnt[i]){
                s[pos] = 'a' + i;
                pos += k;
                cnt[i] --;
            }
        }                
    }

    cout << s << endl;
}