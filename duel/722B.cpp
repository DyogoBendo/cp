#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'

using namespace std;

int isvowel(char c){
    return (c == 'a' || c == 'e' || c == 'i'|| c == 'o'|| c == 'u' || c == 'y');
}

void solve(){
    int n;
    cin >> n;

    vector<int> ps(n);
    vector<string> words(n);

    bool possible = true;
    for (int i = 0; i < n; i++)
    {
        cin >> ps[i];
    }
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        getline(cin, words[i]);
        int total = 0;
        for (auto c : words[i])
        {
            total += isvowel(c);
        }                
        if(total != ps[i]) possible = false;
    }

    cout << (possible ? "YES" : "NO") << endl;
}

signed main(){
    flash;
    int t = 1;

    while(t--) solve();
}