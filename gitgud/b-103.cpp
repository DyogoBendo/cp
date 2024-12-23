#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e3 + 1;
int n, k;

int p[MAXN];
bool check(int v){
    int sum = p[0] + v;    
    for (int i = 1; i < n; i++)
    {        
        if(100 * p[i] > k * sum){                        
            return false;
        } 
        sum += p[i];
    }

    return true;
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;


        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }


        int lo = 0;
        int hi = 1e16;

        while(lo < hi){
            int mid = (hi - lo) / 2 + lo;            

            if(check(mid)){
                hi = mid;
            } else{
                lo = mid + 1;
            }   
        }       

        cout << hi << endl;
    }

}