
#include <stdio.h>
#include <windows.h>//gotoxy
#include <conio.h>//getch
#include <string.h>
#define UP 72
#define DOWN 80
#define ENTER 13
#define ESC 27
void gotoxy(int x, int y);
void menu_scr(void);
void Function(int y);
int MenuCoice(void);
void AddWord(void);
void SearchWord(void);

struct wordlist{
	char name[100]; //단어
	char mean[200]; //뜻
	int num;
};
struct wordlist a[100];

int main(void)
{

	 menu_scr();
	 MenuCoice();

	return 0;
}

void gotoxy(int x, int y)
{
   COORD Pos = {x , y }; // 시작위치가 0,0 부터일때는 COORD Pos = {x, y}; 으로 수정
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int MenuCoice(void)
{
	int key;
	int x=47,y=11;

	while(1)
	{
		key=getch();
		if(key == 0xE0 || key ==0)
		key = getch();
		switch(key)
		{
			case UP:
			system("cls");
			menu_scr();
			y-=2;
			if(y<=11)
				y=11;
			gotoxy(x,y);
			printf("=>");
			break;

			case DOWN:
			system("cls");//break문을 빼먹어서 문제발생
			menu_scr();
			y+=2;
			if(y>=17)
				y=17;
			gotoxy(x,y);
			printf("=>");
			break;

			case ENTER:
				 Function(y); //y로 접속하는것 때문에 오류발생
				 printf("종료하시겠습니까?");



		}

	}

}

void menu_scr(void)
{
	int i;
	system("title 단어장");
	system("color EC");


	printf("=======================ㄷ");
	gotoxy(50,11);
	printf("◆단어 검색\n");
	gotoxy(50,13);
	printf("◆단어 추가\n");
	gotoxy(50,15);
	printf("◆단어장 확인\n");
	gotoxy(50,17);
	printf("◆단어 퀴즈\n");
}

void Function (int y)
{
	 if(y==11)//검색11 8
	    {
			system("cls");
			SearchWord();
	    }
	 if(y==13)//추가13 11
	    {
			system("cls");
			AddWord();
	    }
	 if(y==15)//확인15 14
	    {
			system("cls");
			printf("확인");
	    }
	 if(y==17)//퀴즈17 17
	    {
			system("cls");
			printf("퀴즈");
	    }
}

void AddWord(void)
{
	int i=0;
	char buffer[1];
	while(1)
	{
		i++;
		printf("추가하실 단어를 입력해주세요\n");
		scanf("%s",a[i].name);
		printf("단어의 뜻을 입력해주세요\n");
		scanf("%s",a[i].mean);

		printf("단어를 더 추가합니까? enter 추가\n");
		gets(buffer);
		if(buffer[0]=='\0'){

			break;}

	}

}

void SearchWord(void)
{
	int i;
	while(1){
		int found=0;
	    char target[100];
		char esc[7]={"종료"};
	    printf("찾을 단어를 입력해주세요\n");
	    scanf("%s",target);
		for(i=0;i<100;i++)
		{
			found++;
			if(!strcmp(a[i].name,target)||!strcmp(a[i].mean,target))
			{
				system("cls");
				printf("%s: %s\n",a[i].name,a[i].mean);
				found--;
			}
			if(found==100)
				printf("찾는 단어가 없습니다\n");
		}
	}
}
/*
void Quiz(void)
void WordListCheck(void)*/
