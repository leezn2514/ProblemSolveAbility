#include "Data.hpp"

Map map_class;
Enemy enemy_class;
Player player_class;
Render rend_class;
BFS bfs_class;

// Player Class
void Player::Init() {
	printf("플레이어의 위치를 입력해주세요. >> ");
	scanf_s("%d %d", &playerX, &playerY);

	// 갈 수 없는 길 예외처리
	if (map_class.map[playerX][playerY] == 0) {
		printf("잘못된 입력이거나 갈 수 없는 길입니다. 다시 입력해 주십시오. ▼ \n\n");
		Init();
	}
	map_class.map[player_class.playerX][player_class.playerY] = 3;
}

// Enemy Class
void Enemy::Init() {
	printf("적의 위치를 입력해주세요. >> ");
	scanf_s("%d %d", &enemyX, &enemyY);

	// 갈 수 없는 길이거나 플레이어와 같은 위치 예외처리
	if (map_class.map[enemyX][enemyY] == 0 || (enemyX == player_class.playerX && enemyY == player_class.playerY)) {
		printf("잘못된 입력이거나 갈 수 없는 길입니다. 다시 입력해 주십시오. ▼ \n\n");
		Init();
	}
	map_class.map[enemy_class.enemyX][enemy_class.enemyY] = 4;
}

// Render Calss
void Render::DrawMap() {
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			switch (map_class.map[i][j])
			{
			case 0:
				printf("■"); // 갈 수 없는 길
				break;
			case 1:
				printf("  "); // 갈 수 있는 길
				break;
			case 2:
				printf("▨"); // 지나온 맵의 경로
				break;
			case 3:
				printf("★"); // 플레이어
				break;
			case 4:
				printf("※"); // 적
				break;
			}
		}
		printf("\n");
	}
}

int BFS::Find_ShortestDistance(int playerX, int playerY) {
	que.push(Edge(playerX, playerY, map_class.map[playerX][playerY]));

	while (!que.empty()) {
		Edge cur = que.front();
		que.pop();

		// 목적지에 도착
		if (cur.x == enemy_class.enemyX && cur.y == enemy_class.enemyY) { return cur.cost - 3; }

		for (int i = 0; i < 4; i++) {
			int nextY = cur.y + posY[i];
			int nextX = cur.x + posX[i];

			// 갈 수 없는 길이거나 이미 방문한 곳 예외처리
			if (map_class.map[nextX][nextY] == 0) { continue; }
			if (map_class.isVisited[nextX][nextY]) { continue; }

			que.push(Edge(nextX, nextY, cur.cost + 1));
			map_class.isVisited[nextX][nextY] = true;
		}
	}
	return 0;
}

// GameManager Class
GameManager::GameManager() {
	rend_class.DrawMap();

	player_class.Init(); // 플레이어 위치
	enemy_class.Init(); // 적 위치

	system("cls");

	int length = bfs_class.Find_ShortestDistance(player_class.playerX, player_class.playerY);

	rend_class.DrawMap();

	printf("최단 경로: %d\n", length);
}
