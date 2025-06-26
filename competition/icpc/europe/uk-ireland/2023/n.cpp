#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define ld long double

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<string> all;

    string s;
    for (int i = 0; i < 26; i++)
    {
        char a = ('a' + i);
        s.push_back(a);
        for (int j = 0; j < 26; j++)
        {
            char b = ('a' + j);
            s.push_back(b);
            for (int k = 0; k < 26; k++)
            {
                char c = ('a' + k);
                s.push_back(c);
                all.push_back(s);
                s.pop_back();
            }
            s.pop_back();            
        }
        s.pop_back();
        
    }
    

    map<ld, string> mp; 

    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        ld d; char c;
        cin >> d >> c;
        
        if(!mp[d].size()){
            mp[d] = all[curr++];            
        }
        cout << mp[d] << endl;
        
    }
    
}