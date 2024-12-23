#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, k;
vector<int> v;

bool check(int m){
    int avaiable = k;
    for (int i = n - 1; i >= n/2; i--)
    {        
        if(v[i] < m){            
            avaiable -= m - v[i];
            if(avaiable < 0){
                return false;
            }
        }

    }

    return true;
    
}

signed main(){
    cin >> n >> k;
    int a;
    for (int i = 0; i < n; i++)
    {   
        cin >> a;
        v.push_back(a);
    }        

    sort(v.begin(), v.end());

    int left = v[0];
    int right = v[n - 1] + k + 1;

    while(left < right){              
        int mid = left + (right - left) / 2;

        if(check(mid)){            
            left = mid + 1;
        } else{
            right = mid;
        }
    }

    cout << left - 1 << endl;
}