#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("hoofball");

    int n;
    cin >> n;

    vector<int> v(n);

    for(int &x: v) cin >> x;

    sort(v.begin(), v.end());

    vector<int> prox(n);
    prox[0] = 1;
    prox[n - 1] = -1;


    //cout << v[0] << " -> ";

    for (int i = 1; i < n - 1; i++)
    {
        int d1 = v[i] - v[i - 1];
        int d2 = v[i + 1] - v[i];        

        if(d1 <= d2){
      //      cout << " <- " << v[i] << " ";
            prox[i] = - 1;
        } else{
        //    cout << " " << v[i] << " -> ";
            prox[i] = 1;
        }
    }

    // cout << " <- " << v[n-1] << endl;

    int ans = 0;

    // preencher primeiro os que vão para a esquerda

    vector<int> visited(n, 0);
    vector<int> qtd(n, 0);

    int in_visited = 0;    
    for (int i = 0; i < n - 1; i++)
    {                
        if(prox[i] == 1){
            visited[i] = 1;
            visited[i + 1] = 1;
        }

        if(!in_visited and prox[i] == 1){
            ans ++;
            in_visited = 1;
        } else{
            if(prox[i] == -1) in_visited = 0;
            else in_visited ++;
        }
        qtd[i] = in_visited;
    }     

    in_visited = 0;
    for (int i = n - 1; i > 0; i--)
    {        
        if(visited[i] && prox[i] == -1 && (in_visited == 0 || qtd[i - 1] == 1)){             
            if(in_visited != 0) ans --;
            continue;                         
        }
        if(!in_visited and prox[i] == -1){            
            ans ++;
            in_visited = 1;            
        } else{
            if(prox[i] == 1) in_visited = 0;
        }
    }
    
    
    cout << ans << endl;

}