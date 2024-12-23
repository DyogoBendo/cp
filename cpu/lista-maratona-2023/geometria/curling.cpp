#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, r;
    double distances[1000];
    int x[1000];
    cin >> n >> r;
    
    for (int i = 0; i < n; i++)
    {        
        cin >> x[i];
        distances[i] = r;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if(x[j] + r  < x[i] - r || x[j] - r > x[i] + r){
                continue;
            }

            double b = - 2 * (distances[j]);
            double c = (- 4 * (r * r ) ) + (x[i] * x [i]) - (2 * x[i] * x[j]) + (x[j] * x[j]) + (distances[j] * distances[j]);
            double delta = sqrt((b * b) - (4 * c));
            double newDistance = (-b + delta) / 2.0;

            if(newDistance > distances[i]){
                distances[i] = newDistance;
            }
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << setprecision(10) << distances[i] << " ";
    }
    cout << endl;
    

}