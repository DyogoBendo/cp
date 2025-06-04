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

    set<int> st[3];

    for (int i = 0; i < n; i++)
    {
        st[s[i] - 'a'].insert(i);
    }
    

    map<string, int> cnt;

    while(q--){
        string x, y;
        cin >> x >> y;
        cnt[x+y]++;
    }


    for (int i = 0; i < n; i++)
    {
        if(s[i] == 'a') continue;

        if(s[i] == 'b'){
            if(cnt["ba"]){
                cnt["ba"]--;
                s[i] = 'a';
            }else if(cnt["bc"] && cnt["ca"]){
                cnt["bc"]--;
                cnt["ca"]--;
                s[i] = 'a';
            }
        } else if(s[i] == 'c'){
            if(cnt["ca"]){
                cnt["ca"]--;
                s[i] = 'a';
            } else if(cnt["cb"]){
                cnt["cb"]--;
                if(cnt["ba"]){
                    cnt["ba"]--;
                    s[i] = 'a';
                } else{
                    s[i] = 'b';
                }
            }
        }
    }
    cout <<s << endl;
    
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}