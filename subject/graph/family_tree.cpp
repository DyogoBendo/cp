#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

map<string, string> cow_mother;
map<string, vector<string>> cow_children; 


// 0 -> NOT RELATED
// 1 -> MOTHER/GRND-MOTHER... AUNT/GRAND-AUNT...
// 2 - COUSIN
int cenario = 0;

string ans = "NOT RELATED";

string me, relative;

int found = 0;

void dfs(string prev, string curr, int distance, int relationship){    
    if(found) return;
    // vamos olhar para a mãe
    //cout << "curr: " << curr << " rel: " << relationship << endl;
    if(relationship == 0 && cow_mother.find(curr) != cow_mother.end()){ // primeiro caso é quando estamos olhando o ramo principal da familia, se é mãe, vó, etc        
        if(cow_mother[curr] == relative){
            // significa que encontramos 
            if(distance == 0) ans = "mother";
            else if(distance == 1) ans = "grand-mother";
            else{
                string s = "";
                while(distance >= 2){
                    s += "great-";
                    distance--;
                }
                s+= "grand-mother";
                ans = s;
            }
            cenario = 1;
            found = 1;
            return;
        } else{
            dfs(curr, cow_mother[curr], distance + 1, 0); // vamos verificar se é um ancestral mais acima
            if(found) return;

            dfs(curr, cow_mother[curr], distance + 1, 1); // vamos verificar se é irma, tia... 
            if(found) return;
        }
    } else if(relationship == 1){ // estamos verificando se é irma, tia, etc
        for (auto child: cow_children[curr])
        {            
            // cout << "child: " << child << endl;
            if(child == prev) continue;
            if(child == relative){ // significa que encontramos                
                if(distance == 1){
                    ans = "sister";
                }
                else if(distance == 2){
                    ans = "aunt";
                } else{
                    string s = "";
                    while(distance >= 3){
                        s += "great-";
                        distance --;
                    }
                    s += "aunt";
                    ans = s;
                }
                cenario = 1;
                found = 1;
                return;
            }
        }

        for (auto child: cow_children[curr])
        {           
            if(child != prev) {
                dfs(curr, child, distance, 2); // verificar se é primo
                if(found) return;        
            }
        }        

    } else if(relationship == 2){
        for (auto child: cow_children[curr])
        {
            if(child == relative){ // significa que encontramos
                ans = "cousins";
                cenario = 2;
                found = 1;
                return;                
            } else{
                dfs(curr, child, distance, 2);
            }   
        }        
    }

}


int main(){
    setIO("family");

    int n;
    cin >> n;    
    cin >> me >> relative;

    for (int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;
        cow_mother[b] = a; // a is the mother of b;

        if(cow_children.find(a) == cow_children.end()) cow_children[a] = vector<string>();
        cow_children[a].push_back(b); // b is one of the children of a
    }    

    int found_prev = 0;
    dfs(me, me, 0, 0);
    found_prev = found;

    if(cenario == 1){
        if(ans == "sister") cout << "SIBLINGS" << endl;
        else cout << relative << " is the " << ans << " of " << me << endl;
        return 0;
    }
    else{        
        found = 0;                
        swap(relative, me);
        dfs(me, me, 0, 0);        


        if(cenario == 1) cout << relative << " is the " << ans << " of " << me << endl;
        else{            
            if(!found && !found_prev) cout << "NOT RELATED" << endl;
            else cout << "COUSINS" << endl;;
        }        
    }    
}