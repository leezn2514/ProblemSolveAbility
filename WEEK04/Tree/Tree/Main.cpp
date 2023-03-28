#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <array>

#define VERTEX 1001
using namespace std;

void dfs(int start);
void bfs(int start);

vector<int> dfs_graph[VERTEX];
vector<int> bfs_graph[VERTEX];
array <int, VERTEX> dfs_visited = { 0 }; // 정점의 방문 여부
array <int, VERTEX> bfs_visited = { 0 }; // 정점의 방문 여부

int main() {
    int n, m, v; // 정점의 개수, 간선의 개수, 시작 정점
    int edge1, edge2; // 입력받을 간선 정보

    printf("정점의 개수, 간선의 개수, 시작 정점 >> ");
    cin >> n >> m >> v;

    for (int i = 0; i < m; i++)
    {
        printf("간선 정보(%d) >> ", i + 1);
        cin >> edge1 >> edge2;
        dfs_graph[edge1].push_back(edge2); // 정점을 연결한다. ex) graph[1] => 2, 3, 4
        dfs_graph[edge2].push_back(edge1);
        bfs_graph[edge1].push_back(edge2);
        bfs_graph[edge2].push_back(edge1);
    }

    printf("\nDFS 정렬 결과: ");
    dfs(v);
    printf("\nBFS 정렬 결과: ");
    bfs(v);
    cout << endl;

    return 0;
}

void dfs(int start) {
    sort(dfs_graph[start].begin(), dfs_graph[start].end()); // 오름차순으로 정렬

    dfs_visited[start] = 1;
    printf("%d ", start);

    for (int i = 0; i < dfs_graph[start].size(); i++)
    {
        int result = dfs_graph[start][i];
        if (dfs_visited[result] != 1) dfs(result); // 방문이 끝나지 않았으면 재귀함수로 반복
    }
}

void bfs(int start) {
    queue<int> q;

    q.push(start);
    bfs_visited[start] = 1;

    sort(bfs_graph[start].begin(), bfs_graph[start].end());
    
    while (!q.empty())
    {
        int queue_num = q.front();
        q.pop();
        printf("%d ", queue_num);
          
        for (int i = 0; i < bfs_graph[queue_num].size(); i++)
        {
            int result = bfs_graph[queue_num][i];
            if (bfs_visited[result] != 1) {      
                q.push(result);
                bfs_visited[result] = 1;
            }
        }
    }
}