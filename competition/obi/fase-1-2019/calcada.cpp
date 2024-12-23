#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    

    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        int a = v[i];
        
        for (int j = i + 1; j < n; j++)
        {

            int b = v[j];

            if (a != b){
                int total = 2;
                int current = 0;
                for (int k = j + 1; k < n; k++)
                {
                    if(current == 0 && v[k] == a){
                        current = 1;
                        total ++;
                    } else if(current == 1 && v[k] == b){
                        current = 0;
                        total ++;
                    }

                }
                ans = max(ans, total);            
            }
        }
        
    }
    
    cout << ans << endl;
}