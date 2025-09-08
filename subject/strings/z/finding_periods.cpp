#include <bits/stdc++.h>

using namespace std;

vector<int>z;

void calculate_z(string &s){
    int n = s.size();
    z.resize(n);

    z[0] = n;
    for (int i = 1, l =0, r = 0; i < n; i++)
    {
        z[i] = max(0, min(z[i - l], r - i + 1));

        while(i + z[i] < n && s[z[i]] == s[i + z[i]]){
            l = i;
            r = i + z[i];
            z[i] ++;
        }   
    }    
}


int main(){
    string s;
    cin >> s;
    calculate_z(s);

    vector<int> ans;

    for (int i = 1; i < s.size(); i++)
    {                
        if(z[i] == s.size() - i){
            ans.push_back(i);
        }
    }
    
    ans.push_back(s.size());

    for(auto a: ans) cout << a << " ";
    cout << endl;

}