#include <bits/stdc++.h>

using namespace std;

int * compute_pi(const string &t){
    int m = t.size();

    int *pi = new int[m + 1];
    if(0 <= m) pi[0] = 0;
    if(1 <= m) pi[1] = 0;

    for (int i = 2; i <= m; i++)
    {
        for (int j = pi[i - 1]; ; j = pi[j])
        {
            if(t[j] == t[i - 1]){
                pi[i] = j + 1;
                break;
            }
            if(j == 0){
                pi[i] = 0;
                break;
            }
        }
        
    }

    return pi;
    
}

int main(){
    string s;
    cin >> s;
    while(s != "."){
        int *pi = compute_pi(s);
        int ans = s.length() / (s.length() - pi[s.length()]);
        cout << ans << endl;
        cin >> s;
    }
}