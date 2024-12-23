#include <bits/stdc++.h>

using namespace std;

string s;
vector<int> positions;
set<string> ans;

void solve(int index){
    if(index == s.size()){
        string st = "";
        for (int i = 0; i < s.size(); i++)
        {
            st += s[positions[i]];
        }
        ans.insert(st);
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if(positions[i] == -1){
            positions[i] = index;
            solve(index + 1);
            positions[i] = -1;
        }
    }
    
}
int main(){
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        positions.push_back(-1);
    }

    solve(0);

    cout << ans.size() << endl;
    for (auto a : ans)
    {
        cout << a << endl;
    }
    
}