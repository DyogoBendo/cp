#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int n, k;
    cin >> n >> k;

    vector<int> x(n);
    int left = 1;
    int right = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        right += x[i];
    }

    
    while(left < right){        
        int mid = left + (right - left) / 2;        

        int result = 1;
        int current = 0;        
        int total =0;
        for (int i = 0; i < n; i++)
        {            
            if(x[i] > mid){
                result = 0;
                break;
            }
            if(current + x[i] > mid){
                current = 0;
                total ++;
            }
            current += x[i];
        }

        if(current) total ++;
        
        if(total > k) result = 0;

        if(!result){
            left = mid + 1;
        } else{
            right = mid;
        }
    }

    cout << left<< endl;
}