#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> graph(n + 1);
    vector<int> counts(n + 1, 0);
    vector<bool> visited(n + 1, false);
    queue<int> queue;
    int answer = 0;

    for(int i = 0; i < edge.size(); i++){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    queue.push(1);
    visited[1] = true;

    while(!queue.empty()){
        int node = queue.front();
        queue.pop();

        for(int i = 0; i < graph[node].size(); i++){
            if(!visited[graph[node][i]]){
                int currentCount = counts[node] + 1;
                visited[graph[node][i]] = true;
                counts[graph[node][i]] = currentCount;
                queue.push(graph[node][i]);
            }
        }
    }

    sort(counts.begin(), counts.end(), greater<int>());
    for(auto cnt: counts){
        if(counts[0] != cnt) break;
        answer++;
    }
    return answer;
}

int main(void){
    int n = 6;
    vector<vector<int>> vertex = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};
    cout << solution(n, vertex) << endl;
    return 0;
}