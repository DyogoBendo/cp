#include <bits/stdc++.h>
#include <fstream>

using namespace std;
vector<int> prime_factors;
int prime_limit = 100000;

void solve(int c){         
    int n, q;
    string s;
    cin >> n;
    cin >> s;
    cin >> q;

    vector<int> flip (n + 1, 0);

    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        flip[x] = (flip[x] + 1) % 2;
    }

    int result = 0;
    vector<int> previous_flip(n+1, 0);
    for (int i = 1; i <= n; i++)
    {        

        int has_to_flip = (previous_flip[i] + flip[i]) % 2;                
        int flipped = 0;

        if(s[i - 1] == '1'){            
            if(!has_to_flip){
                flipped = 1;                
                result ++;                
                if(flip[i]) continue;
                for(int j = i + i; j <= n; j += i){
                    previous_flip[j] = (previous_flip[j] + 1) % 2;                
                }
            } 
        } else{
            if(has_to_flip){
                result ++;        
                if(flip[i]) continue;    
                for(int j = i + i; j <= n; j += i){
                    previous_flip[j] = (previous_flip[j] + 1) % 2;
                }
            }
        }

        if(flip[i] && !flipped){            
            for(int j = i + i; j <= n; j += i){
                previous_flip[j] = (previous_flip[j] + 1) % 2;
            }
        }             
    }
    

    ofstream myfile;
    myfile.open ("output.txt", ios_base::app);    
    myfile << "Case #" << c << ": " << result << endl;    

    myfile.close();    

}

int main(){
    freopen("in.txt", "r", stdin);    
    int t;
    int c = 0;
    scanf("%d", &t);
    while(t--) solve(++c);  
    fclose (stdout);  
}