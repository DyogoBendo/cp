#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;

    int n = s.size();

    vector<int> z(n, 0);
    z[0] = n;

    for (int i = 1, l =0, r=0; i < n; i++)
    {
        z[i] = max(0, min(z[i - l], r - i + 1));

        while(z[i] + i < n && s[z[i]] == s[z[i] + i]){
            l = i;
            r = z[i] + i;
            z[i] ++;
        }

    }

    for(auto a: z) cout << a << " ";
    cout << endl;   
    
}