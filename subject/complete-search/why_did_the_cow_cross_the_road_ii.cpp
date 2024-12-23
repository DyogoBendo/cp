#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("circlecross");

   string s;

   cin >> s;
   
   int a = 'A';
   char c1;
   char c2;
   int total = 0;

   for (int i = 0; i < 26; i++)
   {
    for (int j = i + 1; j < 26; j++)
    {        
        int p1 = 0;
        for (int k = 0; k < 52; k++)
        {
            if(s[k] == a + i){
                p1 = k;
                break;
            }
        }
        int q = (p1 + 1) % 52;
        int right = 0;
        while(s[q] != a + i){            
            if(s[q] == a + j){
                right = 1;
                break;
            }
            q = (q + 1) % 52;
        }

        int left = 0;

        int t = (p1 - 1 + 52) % 52;

        while(s[t] != a + i){
            if(s[t] == a + j){                
                left = 1;
                break;
            }
            t = (t - 1 + 52) % 52;
        }
        

        if(left && right){
            total ++;            
        }
        
    }
    
   }
   
    cout << total << endl;
}