#include <bits/stdc++.h>

using namespace std;


int main(){
    vector<int> v(6);
    for (int i = 0; i < 6; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int maior = v[5];
    v.pop_back();

    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            int a = v[i] + v[j];
            int b = 0;
            for (int k = 0; k < 5; k++)
            {
                if(k != i && k != j){
                    b += v[k];
                }
            }
            

            if(a == maior && a == b){
                cout << "S" << endl;
                return 0;
            }
        }
        
    }

    cout << "N" << endl;
    
}