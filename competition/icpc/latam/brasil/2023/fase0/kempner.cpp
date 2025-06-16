#include <bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        long long n;
        cin >> n;

        set<vector<int>> answers;


        int n4 = pow(n, 0.25);

        long long result = 0;
        for (int j = 0; j <= n4; j++)
        {
            int j4 = pow(j, 4);
            result = j4;            
            for (int k = j; k <= pow(n - result, 0.25); k++)
            {
                int k4 = pow(k, 4);
                result += k4;                
                for (int l = k; l <= pow(n - result, 0.25); l++)
                {
                    int l4 = pow(l, 4);
                    result += l4;                    

                    double r = pow(n - result, 0.25);                    
                    int ri = r;                    
                    if(r == ri){                        
                        vector<int> v = {j, k, l, ri};
                        sort(v.begin(), v.end());
                        answers.insert(v);                        
                    }
                    result -= l4;
                    
                }
                result -= k4;
                                
            }
            result -= j4;
            
        }

        cout << answers.size() << endl;
        for (auto a : answers)
        {
            sort(a.begin(), a.end());
            for (int j = 0; j < 4; j++)
            {
                cout << a[j] << " ";
            }
            
            cout << endl;
        }
        
        
    }
    
}