#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<Windows.h>
#define WIDTH 20
#define HEIGHT 20
int map[WIDTH][HEIGHT];

int move;

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
	memset(map, 4, sizeof(map));
}

void gotoxy(int x, int y)//gotoxy
{
	COORD pos = { x - 1, y - 1 };//커서가 X좌표에서 -1 한값. Y좌표에서 -1한 값으로 이동
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
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
