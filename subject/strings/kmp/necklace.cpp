#include <bits/stdc++.h>

using namespace std;

#define tint tuple<int, int, int>

int p1[6002], p2[6002];

void calculate_pi(string s, int* p){
    p[0] = 0;

    for (int i = 1; i < s.size(); i++)
    {
        for (int j = p[i - 1];; j = p[i - 1])
        {
            if(s[j] == s[i - 1]){
                s[i] = s[j] + 1;
                break;
            }
            if(j == 0){
                s[i] = 0;
                break;
            }
        }
        
    }
    
}

tint solve(string s, string t, bool rev){
    int n = s.size();
    int m = t.size();
    string t1 = t;
    string t2 = t;
    reverse(t2.begin(), t2.end());

    tint ans = {0, 0, 0};
    for (int i = 0; i < n; i++)
    {
        string s1 = s.substr(0, i);
        string s2 = s.substr(i, n - i);
        reverse(s1.begin(), s1.end());

        calculate_pi(s1 + "#" + t1, p1);
        calculate_pi(s2 + "#" + t2, p2);

        cout << s1 + "#" + t1 << endl;
        cout << s2 + "#" + t2 << endl;

        for (int j = 1; j <= m; j++)
        {
            ans = max(ans, {
                p1[i + j] + p2[n + m - i - j],
                i - p1[i + j],
                rev ? m - j - p2[n +m -i -j] :  j - p1[i + j]
                }
                );
        }
        
    }

    return ans;
    
}

int main(){
    string s, t;
    cin >> s >> t;

    tint ans = solve(s, t, false);
    reverse(t.begin(), t.end());
    ans = max(ans, solve(s, t, true));

    cout << get<0>(ans) << '\n' << get<1>(ans) << ' ' << get<2>(ans);
	return 0;
}