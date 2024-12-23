#include <bits/stdc++.h>
#include <fstream>

using namespace std;

void solve(int c){
    int s, d, k;
    cin >> s >> d >> k;

    int middle = s + (2 * d);
    int buns = 2 * (s + d);

    int middle_requeried = k;
    int buns_requeried = k + 1;

    string ans = "";
    if(middle >= middle_requeried && buns >= buns_requeried){
        ans = "YES";
    } else{
        ans = "NO";
    }
    ofstream myfile;

    myfile.open ("output.txt", ios_base::app);    
    myfile << "Case #" << c << ": " << ans << endl;    
    myfile.close();

}

int main(){
    int t;
    int c = 0;
    cin >> t;
    while(t--) solve(++c);    
}