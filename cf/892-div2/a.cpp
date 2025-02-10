#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);

    for(auto &x : a){
        cin >> x;
    }

    sort(a.begin(), a.end());

    vector<int>b;
    vector<int>c;

    int current = 0;
    int first = 0;
    for (int i = 0; i < n; i++)
    {
        if(!current){
            current = a[i];
            b.push_back(current);
            first = 1;
            continue;
        }

        if(!first){
            c.push_back(a[i]);
            continue;
        }

        if(a[i] != current && first){
            first = 0;
            c.push_back(a[i]);
        }

        if(first){
            b.push_back(a[i]);
            continue;
        }
    }
    
    if(c.size() == 0) cout << - 1 << endl;
    else{
        cout << b.size() << " " << c.size() << endl; 
        for (auto ans : b)
        {
            cout << ans << " ";
        }
        cout << endl;

        for (auto ans : c)
        {
            cout << ans << " ";
        }
        cout << endl;
               
    }

}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}