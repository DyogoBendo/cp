#include <bits/stdc++.h>

using namespace std;

int find_dfs_begin(vector<vector<int>> &graph, int index, vector<int> &visited){
    for (int e : graph[index])
    {
        if(!visited[e]){
            visited[e] = 1;
            return find_dfs_begin(graph, e, visited);
        }
    }
    return index;    
}

int find_problems(vector<vector<int>> &graph, int index, vector<int> &visited, vector<int> &answer, int begin){
    
    answer.push_back(index);    
    if(begin){
        if(graph[index].size() > 1){
            return 1;
        }
    }
    int currentValue = 0;
    int qtd = 0;
    for (int e : graph[index])
    {
        if(!visited[e]){
            qtd ++;
            visited[e] = 1;            
            currentValue = max(find_problems(graph, e, visited, answer, 0), currentValue);
        }
    }
    if(qtd > 1){
        currentValue = 1;
    }
    return currentValue;    
}

int main(){
    int n;
    cin >> n;    

    for (size_t j = 0; j < n; j++)
    {
        string s;
        cin >> s;
        vector<pair<char, int>> letters_index;
        vector<vector<int>> graph;        

        int i = 0;
        int current = 0;
        for (auto c : s)
        {            
            int index = i;            
            for (auto p : letters_index)
            {
                if(p.first == c){
                    index = p.second;
                }
            }

            if(index == i){
                letters_index.push_back(make_pair(c, i));
                i ++;
                vector<int> v;
                graph.push_back(v);
            }
                        
            
            if(current > 0 ){
                for (auto p : letters_index)
                {
                    if(p.first == s[current - 1]){
                        int already_added = 0;            
                        for (auto a : graph[index])
                        {
                            if(a == p.second) already_added = 1;
                        }
                        if(!already_added){
                            graph[index].push_back(p.second);
                            graph[p.second].push_back(index);
                        }                        
                    }
                }                
            }            

            current ++;
        }

        vector<int> visited;

        for (size_t i = 0; i < s.length(); i++)
        {
            visited.push_back(0);
        }

        visited[0] = 1;

        int start = find_dfs_begin(graph, 0, visited);

        visited.clear();
        for (size_t i = 0; i < s.length(); i++)
        {
            visited.push_back(0);
        }

        visited[start] = 1;
        vector<int> answer;
        int problem = find_problems(graph, start, visited, answer, 1);
        if(problem){
            cout <<"NO" << endl;
        } else{
            cout << "YES" << endl;
            string as;
            char alfabeto[26] = {0};
            for (auto a : answer)
            {                
                for (auto p : letters_index)
                {
                    if(p.second == a){
                        as += p.first;
                        alfabeto[p.first - 'a'] = 1;
                    }
                }                
            }
            int i = 0;
            for (auto c : alfabeto)
            {
                if(!c){
                    as +=  char('a' + i);
                }
                i ++;
            }
            
            cout << as << endl;
        }
    }
    
}
