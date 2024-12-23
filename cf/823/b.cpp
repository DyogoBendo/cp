#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long n;
    cin >> n;
    vector<long long> p;
    vector<long long> t;

    for (long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        p.push_back(x);
    }

    for (long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        t.push_back(x);
    }
    
    vector <pair<long long, long long>> vpp;

    for (long long i = 0; i < n; i++)
    {
        vpp.push_back({p[i], t[i]});
    }

    sort(vpp.begin(), vpp.end());

    double start = vpp.begin()->first;
    double end = (vpp.end() - 1 )->first;
    double mid = (start + end) / 2;

    double bl = 0;
    double l = 0;
    double br = 0;
    double r = 0;
    double bm = 0;
    double m = 0;

    for (long long i = 0; i < n; i++)
    {
        if(vpp[i].first == mid){
            double d = vpp[i].second;
            if(d > bm) {
                bm = d;
                m = vpp[i].first;
            }
        }
        if(vpp[i].first < mid){
            double d = mid - vpp[i].first + vpp[i].second;
            if(d > bl){
                bl = d;
                l = vpp[i].first;
            }
        }
        if(vpp[i].first > mid){
            double d = vpp[i].first - mid + vpp[i].second;
            if(d > br){
                br = d;
                r = vpp[i].first;
            }
        }
    }

    cout << fixed;
    cout << setprecision(15);
    if(bm >= br && bm >= bl ){
        cout << m << endl;
    } else{
        if(br > bl){
            cout << min(r, mid + ((br - bl) / 2)) << endl;
        } else{
            cout << max(l, mid - ((bl - br) / 2)) << endl;
        }
    }

    
    
}

int main(){
    long long t;
    cin >> t;
    while(t--) solve();

}