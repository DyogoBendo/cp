#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<tuple<int, int, int>> v;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        v.push_back({a, -1, i});
        v.push_back({b, 1, i});
    }

    priority_queue<int> pq;

    for (int i = 1; i <= n; i++)
    {
        pq.push(-i);
    }

    sort(v.begin(), v.end());

    int biggest = 0;
    for (int i = 0; i < 2*n; i++)
    {
        int t, f, p;
        tie(t, f, p) = v[i];        

        if(f == -1){
            biggest = max(biggest, -pq.top());
            ans[p] = -pq.top();
            pq.pop();
        } else{
            pq.push(-ans[p]);
        }
    }

    cout << biggest << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

}