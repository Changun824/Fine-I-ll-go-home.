/*menu_choice=%4

  case 0x0D : printf("Enter키를 누르셨군요\n");
                break;
    case 0x1B : printf("Esc키를 누르셨군요\n");
                break;
*/
#include <stdio.h>
#include <windows.h>//gotoxy
#include <conio.h>//getch
#define UP 72
#define DOWN 80
void gotoxy(int x, int y);
int x=42,y=11;
int main(void)
{
	int menu_choice=1;
	int key;


	gotoxy(45,11);
	printf("◆단어 검색\n");
	gotoxy(45,13);
	printf("◆단어 추가\n");
	gotoxy(45,15);
	printf("◆단어장 확인\n");
	gotoxy(45,17);
	printf("◆단어 퀴즈\n");
	while(1)
	{
		key=getch();
		if(key == 0xE0 || key ==0)
		key = getch();
		switch(key)
		{
			case UP:
			menu_choice++;
			menu_choice%=4;
			y-=2;
			if(y<=11)
				y=11;
			gotoxy(x,y);
			printf("=>");

			case DOWN:
			menu_choice--;
			menu_choice%=4;
			y+=2;
			if(y>=17)
				y=17;
			gotoxy(x,y);
			printf("=>");

			case 0x0D:
				break;
		}

	}

	/*if(화살표입력)
	{
		menu_choice%=4
	}*/
	if(menu_choice==3)//검색11 8
	{
		printf("검색");
	}
	if(menu_choice==2)//추가13 11
	{
		printf("추가");
	}
	if(menu_choice==1)//확인15 14
	{
		printf("확인");
	}
	if(menu_choice==0)//퀴즈17 17
	{
		printf("퀴즈");
	}
	return 0;
}

void gotoxy(int x, int y)
{
   COORD Pos = {x , y }; // 시작위치가 0,0 부터일때는 COORD Pos = {x, y}; 으로 수정
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
