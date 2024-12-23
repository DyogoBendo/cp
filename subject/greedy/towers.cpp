#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;


    multiset<int> towers;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        auto p = towers.upper_bound(x);
        if(p != towers.end()) towers.erase(p);
        towers.insert(x);
    }
     
    cout << towers.size() << endl;
}