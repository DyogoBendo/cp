#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int q;
    cin >> q;
    priority_queue<int, vector<int>, greater<int> > pq;
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int x;
            cin >> x;
            pq.push(x);
        } else{
            cout << pq.top() << endl;
            pq.pop();
        }
    }
}