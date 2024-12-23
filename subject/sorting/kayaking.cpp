#include <bits/stdc++.h>

using namespace std;

vector<int> weights;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < 2 * n; i++)
    {
        int x;
        cin >> x;
        weights.push_back(x);
    }

    sort(weights.begin(), weights.end());    

    vector<int> marked(2*n, 0);
    int ans = 1e8;

    for (int i = 0; i < 2* n; i++)
    {
        marked[i] = 1;
        for (int j = i + 1; j < 2 * n; j++)
        {
            marked[j] = 1;
            int current = 0;            
            
            int k = 0;
            while(k < 2 * n){
                if(!marked[k]){
                    int l = k + 1;
                    while(marked[l]){                        
                        l++;
                    }                    
                    current += weights[l] - weights[k];
                    k = l + 1;
                } else{
                    k ++;
                }
            }                        

            for (int k = 0; k < 2 * n; k++)
            {
                if(k != i && k != j){
                    marked[k] = 0;
                }
            }

            ans = min(ans, current);                                
            
            marked[j] = 0;
        }
        marked[i] = 0;  
                
    }
    
    cout << ans << endl;
    
}