#include <bits/stdc++.h>

using namespace std;

#define int long long
const double ERROR = 10e-7;

signed main(){
    int n;
    cin >> n;

    vector<double> x(n);
    vector<double> v(n);

    
    double lo = 0;
    double hi = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        hi = max(hi, x[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    int max_left = 0;
    int max_right = 0;
    auto check = [&] (double loc){
        double maxDistance = 0;
        for (int i = 0; i < n; i++)
        {
            if(x[i] == loc) continue;

            double distance = abs(x[i] - loc) / v[i];
            if(distance > maxDistance){
                maxDistance = distance;
                if(x[i] < loc){
                    max_left = 1;
                    max_right = 0;
                } else{
                    max_left = 0;
                    max_right = 1;
                }
            } else if(distance == maxDistance){
                if(x[i] < loc){
                    max_left = 1;                    
                } else{                    
                    max_right = 1;
                }
            }
        }
        return maxDistance;
    };

    double ans = 10e9;
    while(hi - lo > ERROR){
        double mid = lo + (hi - lo) / 2;

        double time = check(mid);

        ans = min(ans, time);

        if(max_left && max_right){
            break;
        } else if(max_left){
            hi = mid;
        } else{
            lo = mid;
        }
    }    

    cout << fixed << ans << endl;
}