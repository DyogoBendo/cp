#include <bits/stdc++.h>
#include <fstream>

using namespace std;
vector<int> prime_factors;
int prime_limit = 100000;

void find_primes(){    
    bool marked[100001] = {0};

    prime_factors.push_back(2);    
    

    for (int i = 3; i < prime_limit; i+=2)
    {                        
        if(!marked[i]){            
            prime_factors.push_back(i);

            for (int j = i + i; j < prime_limit; j+= i)
            {                
                marked[j] = 1;
            }            
        }        
    }
    
}

void solve(int c){         
    int p;
    cin >> p;
    
    vector<pair<int, int>> m;

    for (auto prime : prime_factors)
    {        
        if(p % prime) continue;
        int r = 0;
        while(p % prime == 0){
            p /= prime;
            r ++;
        }
        m.push_back({prime, r});
    }

    cout << p << endl;
    
    int current_sum = 0;
    
    int l = 0;
    string s = ""; 
    for (auto prime : m)
    {        
        current_sum += prime.first * prime.second;
        for (int i = 0; i < prime.second; i++)
        {
            l ++;
            s +=  to_string(prime.first) + " ";
        }
        
    }
    

    ofstream myfile;
    myfile.open ("output.txt", ios_base::app);    
    int result;
    if(current_sum > 41){        
        result = -1;
        myfile << "Case #" << c << ": " << result << endl;    
    } else{        
        while(current_sum < 41){
            current_sum ++;
            s += "1 ";
            l ++;
        }
        string ans = to_string(l) + " " + s;
        myfile << "Case #" << c << ": " << ans << endl;            
    }
    
    

    myfile.close();    

}

int main(){
    freopen("in.txt", "r", stdin);
    find_primes();
    int t;
    int c = 0;
    scanf("%d", &t);
    while(t--) solve(++c);  
    fclose (stdout);  
}