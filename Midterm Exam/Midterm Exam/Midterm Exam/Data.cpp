#include "Data.hpp"

Map map_class;
Enemy enemy_class;
Player player_class;
Render rend_class;
BFS bfs_class;

// Player Class
void Player::Init() {
	printf("�÷��̾��� ��ġ�� �Է����ּ���. >> ");
	scanf_s("%d %d", &playerX, &playerY);

	// �� �� ���� �� ����ó��
	if (map_class.map[playerX][playerY] == 0) {
		printf("�߸��� �Է��̰ų� �� �� ���� ���Դϴ�. �ٽ� �Է��� �ֽʽÿ�. �� \n\n");
		Init();
	}
	map_class.map[player_class.playerX][player_class.playerY] = 3;
}

// Enemy Class
void Enemy::Init() {
	printf("���� ��ġ�� �Է����ּ���. >> ");
	scanf_s("%d %d", &enemyX, &enemyY);

	// �� �� ���� ���̰ų� �÷��̾�� ���� ��ġ ����ó��
	if (map_class.map[enemyX][enemyY] == 0 || (enemyX == player_class.playerX && enemyY == player_class.playerY)) {
		printf("�߸��� �Է��̰ų� �� �� ���� ���Դϴ�. �ٽ� �Է��� �ֽʽÿ�. �� \n\n");
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
				printf("��"); // �� �� ���� ��
				break;
			case 1:
				printf("  "); // �� �� �ִ� ��
				break;
			case 2:
				printf("��"); // ������ ���� ���
				break;
			case 3:
				printf("��"); // �÷��̾�
				break;
			case 4:
				printf("��"); // ��
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

		// �������� ����
		if (cur.x == enemy_class.enemyX && cur.y == enemy_class.enemyY) { return cur.cost - 3; }

		for (int i = 0; i < 4; i++) {
			int nextY = cur.y + posY[i];
			int nextX = cur.x + posX[i];

			// �� �� ���� ���̰ų� �̹� �湮�� �� ����ó��
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

	player_class.Init(); // �÷��̾� ��ġ
	enemy_class.Init(); // �� ��ġ

	system("cls");

	int length = bfs_class.Find_ShortestDistance(player_class.playerX, player_class.playerY);

	rend_class.DrawMap();

	printf("�ִ� ���: %d\n", length);
}
