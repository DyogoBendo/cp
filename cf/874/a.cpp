#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        string s;
        set<string> used;

        for (int i = 0; i < n; i++)
        {
            char x;
            cin >> x;
            s.push_back(x);
        }

        for (int i = 1; i < n; i++)
        {            
            string u = s.substr(i - 1, 2);            
            used.insert(u);
        }
        
        cout << used.size() << endl;      
    }
}