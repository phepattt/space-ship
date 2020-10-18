#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<conio.h>
int x, y, maxx, maxy, maxx2, Y1, X1;
char ch = ' ';
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void eraseship(int x, int y)
{
	gotoxy(x, y);
	printf("     ");
}
void drawship(int x, int y)
{
	gotoxy(x, y);
	printf("<-0->");
}
int main()
{
	printf("ENTER MAX X AXIS :");
	scanf("%d", &maxx);
	printf("ENTER MAX Y AXIS :");
	scanf("%d", &maxy);
	gotoxy(0, 0);
	printf("                                            ");
	gotoxy(0, 1);
	printf("                                            ");
	x = 0;
	y = 0;
	maxx2 = maxx - 4;
	Y1 = maxy + 1;
	X1 = maxx + 1;
	for (y = 0; y <= Y1; y++)
	{
		gotoxy(x = X1, y);
		printf("|");
	}
	for (x = 0; x <= X1; x++)
	{
		gotoxy(x, y = Y1);
		printf("=");
	}
	x = 0;
	y = 0;
	gotoxy(x, y);
	drawship(0, 0);
	do
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 'a') {
				if (x > 0) {
					eraseship(x, y);
					drawship(--x, y);
				}
				else drawship(0, y);
			}
			if (ch == 'd') {
				if (x < maxx2) {
					eraseship(x, y);
					drawship(++x, y);
				}
				else drawship(maxx2, y);
			}
			if (ch == 'w') {
				if (y > 0) {
					eraseship(x, y);
					drawship(x, --y);
				}
				else drawship(x, 0);
			}
			if (ch == 's') {
				if (y < maxy) {
					eraseship(x, y);
					drawship(x, ++y);
				}
				else drawship(x, maxy);
			}
			fflush(stdin);
		}
		Sleep(10);
	} while (ch != 'x');
	return 0;
}