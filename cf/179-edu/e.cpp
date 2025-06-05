#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;    
    
    set<int> s1, s2, s3, s4;
    
    for (int i = 0; i < q; i++)
    {
        string x, y;
        cin >> x >> y;
        string curr= x+y;        

        if(curr == "ba") s1.insert(i);
        if(curr == "bc") s2.insert(i);
        if(curr == "ca") s3.insert(i);
        if(curr == "cb") s4.insert(i);
    }

    for (int i = 0; i < n; i++)
    {
        if(s[i] == 'a') continue;

        if(s[i] == 'b'){
            if(s1.size()){                
                s1.erase(s1.begin());
                s[i] = 'a';
            } else if(s2.size() && s3.size()){
                int idx = *s2.begin();
                auto pos = s3.lower_bound(idx);
                if(pos != s3.end()){
                    s[i] = 'a';
                    s3.erase(pos);
                    s2.erase(s2.begin());
                }
            }
        } else{
            if(s3.size()){                
                s3.erase(s3.begin());
                s[i] = 'a';
            } else if(s4.size()){
                bool found = false;
                if(s1.size()){
                    int idx = *s4.begin();
                    auto pos = s1.lower_bound(idx);
                    if(pos != s1.end()){
                        found = true;
                        s[i] = 'a';
                        s1.erase(pos);
                        s4.erase(s4.begin());
                    }
                }
                if(!found){
                    s[i] = 'b';
                    s4.erase(s4.begin());
                }
            }
        }
    }
    
        
    cout << s << endl;
    
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}