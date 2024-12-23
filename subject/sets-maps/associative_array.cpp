#include <bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin >> q;

    map<int, int> a;

    for (int i = 0; i < q; i++)
    {
        int o, k, v;
        cin >> o >> k;
        if(!o){
            cin >> v;
            a[k] = v;
        } else{
            cout << a[k] << endl;
        }
    }
    
}