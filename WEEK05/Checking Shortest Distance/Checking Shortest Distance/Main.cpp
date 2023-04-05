#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <queue>

using namespace std;

struct Edge { // x, y, 길이 구조체
    int x, y, cost;

    Edge(int _x, int _y, int _cost) {
        x = _x;
        y = _y;
        cost = _cost;
    }
};

int N, M;
int map[101][101] = { 0, }; // 미로 행렬, 0으로 초기화
int isVisited[101][101] = { false, }; // 방문했는지 검사
queue<Edge> que;

int posX[4] = { -1, 0, 1, 0 }; // 왼쪽, 위, 오른쪽, 아래
int posY[4] = { 0, 1, 0, -1 }; // 왼쪽, 위, 오른쪽, 아래

bool isInside(int x, int y) {
    return (x >= 1) && (x <= N) && (y >= 1) && (y <= M);
}

int bfs(int X, int Y) {
    que.push(Edge(X, Y, map[X][Y])); // 큐에 Edge 정보를 삽입

    while (!que.empty()) {
        Edge cur = que.front(); // 삽입한 정보를 저장
        que.pop(); // 삽입한 정보 삭제

        if (isVisited[cur.x][cur.y]) { continue; } // 만약 방문 기록이 있다면 건너뛰기
        isVisited[cur.x][cur.y] = true; // 없다면 방문 기록 true

        if (cur.x == N && cur.y == M) { return cur.cost; } // 종료조건

        for (int i = 0; i < 4; i++) { // 왼쪽, 위, 오른쪽, 아래로 갈 수 있는지 조사
            int nextX = cur.x + posX[i];
            int nextY = cur.y + posY[i];

            if (isInside(nextX, nextY) == false) { continue; } // map 영역을 벗어나면 pass
            if (map[nextX][nextY] == 0) { continue; } // 이동 불가하면 pass
            que.push(Edge(nextX, nextY, cur.cost + 1)); // 이동 가능한 칸 정보(Edge)를 que에 넣는다
        }
    }
    return 0;
}

int main() {

    scanf_s("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf_s("%1d", &map[i][j]);
        }
    }

    int length = bfs(1, 1);
    printf("%d", length);

    return 0;
}