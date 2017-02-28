#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<Windows.h>
#define WIDTH 20
#define HEIGHT 20
int map[WIDTH][HEIGHT];
int mine[WIDTH][HEIGHT];
int move;
int number_of_mine;

typedef struct _op {
	int x;
	int y;
}op;

op position;

void remove_cursor(void) {
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void init_map(void) {
	memset(map, 0, sizeof(map));
	memset(mine, 0, sizeof(mine));
}

void gotoxy(int x, int y)//gotoxy
{
	COORD pos = { x - 1, y - 1 };//커서가 X좌표에서 -1 한값. Y좌표에서 -1한 값으로 이동
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void make_mine(void) {
	static int count = 0;
	if (count == number_of_mine) {
		return;
	}
	int x = rand() % WIDTH;
	int y = rand() % HEIGHT;
	if (map[y][x] == 0) {
		map[y][x] = mine[y][x] = 9;
		count++;
	}
	else {
		make_mine();
	}
}

void show_map(void) { //맵표현 gotoxy
	/*
	매직넘버
	0:빈칸
	1:숫자１
	2:숫자２
	3:숫자３
	4:숫자４
	5:숫자５
	6:숫자６
	7:숫자７
	8:숫자８
	9:지뢰
	10:깃발
	11:유저
	*/
	int i, j;

	gotoxy(1, 1);
	printf("\n");


	printf("┌");
	for (j = 0; j < WIDTH; j++) { //메인창 바닥
		printf("─");
	}
	printf("┐");
	printf("\n");

	for (i = 0; i <= HEIGHT; i++) { //메인창의 높이
		if (i != HEIGHT) {
			printf("┃"); //메인창 테두리
			for (j = 0; j < WIDTH; j++) { //메인창 너비
				if (map[i][j] == 0) {
					printf("　");//벽
				}
				else if (map[i][j] == 1) {
					printf("１");//전각문자
				}
				else if (map[i][j] == 2) {
					printf("２");//hole
				}
				else if (map[i][j] == 3) {
					printf("３");//stone
				}
				else if (map[i][j] == 4) {
					printf("４");//전각문자
				}
				else if (map[i][j] == 5) {
					printf("５");//hole
				}
				else if (map[i][j] == 6) {
					printf("６");//stone
				}
				else if (map[i][j] == 7) {
					printf("７");//전각문자
				}
				else if (map[i][j] == 8) {
					printf("８");//hole
				}
				else if (map[i][j] == 9) {
					printf("※");//stone
				}
				else if (map[i][j] == 10) {
					printf("▶");//전각문자
				}
				else if (map[i][j] == 11) {
					printf("○");//hole
				}
			}
			printf("┃");// 테두리
			if (i == 4) {
				printf("moves:%d", move);
			}
			printf("\n");
		}
		else {
			printf("└");
			for (j = 0; j < WIDTH; j++) { //메인창 바닥
				printf("─");
			}
			printf("┘");
			printf("\n");
		}

	}
}

void game_over(void) {
	init_map();
	show_map();
	gotoxy((WIDTH + 7) / 2, (HEIGHT + 1) / 2);
	printf("Game Over");
	gotoxy((WIDTH + 7) / 2, ((HEIGHT + 1) / 2) + 1);
	printf("move :%d", move);
}


int main(void) {

}
