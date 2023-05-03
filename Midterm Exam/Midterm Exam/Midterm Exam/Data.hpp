#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <Windows.h>

#define MAP_SIZE 15

// 플레이어 정보
class Player {
public:
	int playerX, playerY;
	void Init();
};

// 적 정보
class Enemy {
public:
	int enemyX, enemyY;
	void Init();
};

// 맵 정보
class Map {
public:
	int map[MAP_SIZE][MAP_SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
									0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0,
									0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0,
									0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0,
									0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0,
									0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
									0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0,
									0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0,
									0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0,
									0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0,
									0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
									0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0,
									0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0,
									0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
									0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	int isVisited[MAP_SIZE][MAP_SIZE] = { false, };
};

// UI
class Render {
public:
	void DrawMap();
};

// BFS
class BFS {
private:
	struct Edge {
		int x, y, cost;

		Edge(int _x, int _y, int _cost) {
			x = _x;
			y = _y;
			cost = _cost;
		}
	};

	std::queue<Edge> que;

	int posX[4] = { -1, 0, 1, 0 };
	int posY[4] = { 0, 1, 0, -1 };

public:
	int Find_ShortestDistance(int playerX, int playerY);
};

class GameManager {
public:
	GameManager();
};