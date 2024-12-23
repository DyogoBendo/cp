#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    array< multiset<string>, 10> ms;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int l = s.size() - 1;
        ms[l].insert(s);
    }

    int ans = 0;

    for (int k = 0; k < 10; k++)
    {
        auto m = ms[k];
        for (auto s : m)
        {
            int a = 0;
            for (int i = 1; i <= s.size(); i++)
            {
                auto m2 = ms[i - 1];
                set<string> visited;        
                for (int j = 0; j <= s.size() - i; j++)
                {
                    string sub = s.substr(j, i);
                    if(visited.find(sub) == visited.end()){                                            
                        a += (int) m2.count(sub);                    
                        visited.insert(sub);                              
                    }
                }            
            }        
            a--;        
            ans += a;           
        }
    }
    
   
    
    cout << ans << endl;
}