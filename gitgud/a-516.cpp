#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;

    vector<int> v(26, 0);

    for (int i = 0; i < n; i++)
    {
        v[s[i] - 'a'] ++;
    }
    

    for (int i = 0; i < 26; i++)
    {
        while(v[i]--){
            char c = 'a' + i;
            cout << c;            
        }
    }
    cout << endl;
}