#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;    
    cin >> n;
    vector<int> cumulative_sum(n + 1, 0);


    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;        
        cumulative_sum[i + 1] = cumulative_sum[i] + x;        
    }    

    int i = 0;
    int j = n;
    
    while(i < j){        
        int mid = (i + j) / 2;        

        cout << "? " << mid - i + 1 << " ";

        for(int k = i; k <= mid; k++) cout << k + 1 << " "; 
        cout.flush();        

        int x;
        cin >> x;

        int xv = cumulative_sum[mid + 1] - cumulative_sum[i];        

        if(xv == x) i = mid  + 1;
        else j = mid;

    }

    cout << "! " << i + 1 << endl;
    cout.flush();
    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}