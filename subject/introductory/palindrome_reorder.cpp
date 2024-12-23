#include <bits/stdc++.h>
 
using namespace std;

 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
 
    int n = s.size();
 
    map<char, int> ms;
    for (int i = 0; i < n; i++)
    {        
        ms[s[i]] ++;
    }
 
    bool allow_impar = n % 2;
    int impar = 0;
    char impar_key;
    for (auto m : ms)
    {
        if(m.second % 2){
            impar ++;
            impar_key = m.first;
        }
    }
 
    if(impar > allow_impar){
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    
    vector<char> ans(n);
    int current = 0;
 
    for (auto m : ms)
    {            
        for (int i = 0; i < m.second / 2; i++)
        {
            ans[current + i] = m.first;
            ans[n - 1 - i - current] = m.first;
        }
        current += m.second/2;        
    }
    if(n % 2) ans[n/2] = impar_key;
 
    for (int i = 0; i < n; i++)
    {
        cout << ans[i];
    }
    cout << endl;
    
    
    
}
