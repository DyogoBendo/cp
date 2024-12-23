#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int x, n;
    cin >> x >> n;

    set<int> traffic;
    multiset<int> distance;
    traffic.insert(0);
    traffic.insert(x);

    distance.insert(x);

    int p;
    for (int i = 0; i < n; i++)
    {
        cin >> p; 

        auto previous = --traffic.lower_bound(p);
        auto next = traffic.upper_bound(p);

        int d =  *next - *previous;
        distance.erase(distance.find(d));

        int before = p - *previous;
        int after = *next - p;
        distance.insert(before);
        distance.insert(after);
        traffic.insert(p);

        cout << *(--distance.end()) << endl;
    }
    
}