//#include <Windows.h>
//#include <conio.h>
//#include <iostream>
//#include <queue>
//#include <vector>
//#include <array>
//
//#define MAP_SIZE 6
//#define VERTEX 1001
//
//using namespace std;
//
//void gotoxy(int x, int y);
//void bfs(int _x, int _y);
//
//// 20 X 20 ��
//int map[MAP_SIZE][MAP_SIZE] = {
//    // col  :    0  1  2  3  4  5  6  7 
//    /*row : 0*/    { 1, 1, 1, 1, 1, 1 },
//    /*row : 1*/    { 0, 0, 1, 0, 0, 1 },
//    /*row : 2*/    { 1, 1, 1, 0, 1, 1 },
//    /*row : 3*/    { 1, 0, 0, 0, 1, 0 },
//    /*row : 4*/    { 1, 1, 1, 0, 1, 0 },
//    /*row : 5*/    { 0, 0, 1, 1, 1, 1 } };
//
//vector<int> bfs_graph[VERTEX];
//array <int, VERTEX> bfs_visited = { 0 };
//
//int n;
//int cnt = 0;
//int x[100], y[100], l[100]; // ��ǥ�� ���̸� ���� �迭
//void enqueue(int _x, int _y, int _l)
//{
//    x[cnt] = _x;
//    y[cnt] = _y;
//    l[cnt] = _l;
//    cnt++;
//}
//
//int main() {
//    srand(time(NULL));
//    int playerX = 0; // rand() % MAP_SIZE;
//    int playerY = 0; // rand() % MAP_SIZE;
//    int enemyX = 5;
//    int enemyY = 5;
//    // �÷��̾�� ���� ������ �� ����ó�� �ʿ�
//
//
//    while (true)
//    {
//        ///*gotoxy(0, MAP_SIZE + 1);
//        //printf("X coord : %d\n", playerX);
//        //printf("Y coord : %d\n", playerY);*/
//
//        gotoxy(playerX, playerY);
//        printf("��");
//        gotoxy(enemyX, enemyY);
//        printf("X");
//
//    }
//
//
//
//    //site = _getch();
//
//    //switch (site) {
//    //case 224:                           
//    //    site = _getch();
//    //    switch (site) { 
//    //    case 72:                    // top
//    //        if (playerY != 0) playerY--;
//    //        break;
//    //    case 75:                    // left
//    //        if (playerX != 0) playerX--;
//    //        break;
//    //    case 77:                    // right
//    //        if (playerX != MAP_SIZE) playerX++;
//    //        break;
//    //    case 80:                    // bottom
//    //        if (playerY != MAP_SIZE) playerY++;
//    //        break;
//    //    default:
//    //        break;
//    //    }         
//    //default:
//    //    break;
//    //}
//    system("cls");
//}
//
//
//void gotoxy(int x, int y) {
//    COORD pos;
//
//    pos.X = x;
//    pos.Y = y;
//
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//}
//
//void bfs(int _x, int _y) {
//    int pos = 0;
//
//    enqueue(_x, _y, 1);
//
//    while (pos < cnt && (x[pos] != MAP_SIZE - 1 || y[pos] != MAP_SIZE - 1)) {
//        // ���� �� �� �ִٸ�, �� ������ ��ǥ ������ ���̸� ť�� �����Ѵ�
//        if (y[pos] > 0 && map[y[pos] - 1][x[pos]] == 0)
//            enqueue(x[pos], y[pos] - 1, l[pos] + 1);
//
//
//        // ť�� ���� ������ ������ �湮�Ѵ�
//        pos++;
//    }
//    if (pos < cnt)
//        printf("�ִ� ��� ����: %d\n", l[pos]);
//}