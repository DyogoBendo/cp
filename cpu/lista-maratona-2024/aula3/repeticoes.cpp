#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;

    int t = 0, ans = 0;
    char prev = '\0';
    for (auto c: s)
    {
        if(c == prev) t ++;
        else prev = c, t = 0;
        ans = max(ans, t);
    }

    cout << ans + 1 << endl;
}