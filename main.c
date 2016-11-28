
#include <stdio.h>
#include <windows.h>//gotoxy
#include <conio.h>//getch
#include <string.h>
#define UP 72
#define DOWN 80
#define ENTER 13
#define ESC 27
#define WORDCOUNT 100
void gotoxy(int x, int y);
void menu_scr(void);
void Function(int y);
int MenuCoice(void);
void AddWord(void);
void SearchWord(void);
void WordListCheck(void);
int ProgramRead(void);

typedef struct wordlist{
	char name[100]; //단어
	char mean[200]; //뜻

}VOCA;
VOCA a[WORDCOUNT];

int main(void)
{
	 ProgramRead();
	 menu_scr();
	 MenuCoice();
	 return 0;
}

void gotoxy(int x, int y) //좌표함수
{
   COORD Pos = {x , y };
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
			system("cls");
			menu_scr();
			y+=2;
			if(y>=17)
				y=17;
			gotoxy(x,y);
			printf("=>");
			break;

			case ENTER:
				 Function(y);
		}

	}

}

void menu_scr(void)
{

	system("title 단어장");
	system("color EC");


	printf("=======================================");
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
			 WordListCheck();
	    }
	 if(y==17)//퀴즈17 17
	    {
			system("cls");
			printf("퀴즈");
	    }
}

void AddWord(void)//단어 추가 기능
{
	int i=0,key; //i for문 실행에 쓰일 변수 ,key: ENTER키나 ESC키로 받은 값을 저장받음
	int count;
	FILE *fp;
	if((fp = fopen("Voca.txt","a"))==NULL)
	{
		fprintf(stderr,"파일 Voca.txt를 열 수 없습니다\n","Voca.txt");
	}
	while(1)
	{
		printf("추가하실 단어를 입력해주세요\n");
		gets(a[i].name);
		printf("단어의 뜻을 입력해주세요\n");
		gets(a[i].mean);
		i++;
		printf("단어를 더 추가합니까? 추가[ENTER] 종료[ESC]\n");//단어를 한 개 추가하고 나서 계속 추가할 것인지 키를 입력받아 사용자의 의사를 묻는다
		key=getch();										    //ENTER는 더 추가 ESC를 입력하면 종료 N
		if(key == 0xE0 || key ==0)
		key = getch();
			if(key==27)//ESC키를 입력하면
		   {
			  system("cls");
			  break;   //루프를 종료:[단어 검색]기능을 종료
		   }
			else if(key==13)//ENTER키를 입력하면 콘솔창을 깨끗하게 지우고 다시 처음 루프로 가서 추가할 단어를 입력받음
		   {
			 system("cls");
		   }
			else{//ENTER 와 ESC가 아닌 키를 입력했을 경우
				      while(1)
				      {  system("cls");
						 printf("추가[ENTER] 또는 종료[ESC] 키를 입력하세요\n"); //ENTER나 ESC를 입력할때까지 안내 메세지를 띄우고
						 key=getch();
						 if(key == 0xE0 || key ==0);
					     key=getch();
						 if(key==13)//Enter를 입력받으면 이 루프를 빠져나가 단어를 새로 입력받고
					    {
						  system("cls");
						  break;
					    }
					    else if(key==27)//ESC를 누르면
					    {
						system("cls");
						goto label;   //이중 루프를 빠져나가서 기능이 종료되게끔 한다.
					    }
					  }

			  }

	}
	count=i;
label://goto 문으로 빠져나오는 곳
	for(i=0;i<count;i++){
	fputs(a[i].name,fp);
	fputc('\n',fp);//fputs 는 텍스트로 저장할때 엔터값을 안받기에 개행을 위해 붙여줌
	fputs(a[i].mean,fp);
	fputc('\n',fp);
	}
	fclose(fp);
	menu_scr();
}

void SearchWord(void)
{
	int i=0,count;
	FILE *fp;
	if((fp = fopen("Voca.txt","r"))==NULL)
	{
		fprintf(stderr,"파일 Voca.txt를 열 수 없습니다\n","Voca.txt");
	}
	while(!feof(fp))
	{
		fgets(a[i].name,100,fp);
		a[i].name[strlen(a[i].name)-1]='\0';
		fgets(a[i].mean,100,fp);
		a[i].mean[strlen(a[i].mean)-1]='\0';
		i++;
	}
	fclose(fp);
	count=i;
	while(1){
		int found=0;//찾은 수
	    char target[100];
		char esc[8]="종료.";
	    printf("찾을 단어를 입력해주세요\n");
	    gets(target);
		if(!strcmp(esc,target)){
			system("cls");
				break;
		}
		for(i=0;i<count;i++)
		{
			found++;
			if(!strcmp(a[i].name,target)||!strcmp(a[i].mean,target))
			{
				system("cls");
				printf("%s: %s\n",a[i].name,a[i].mean);
				found--;
			}
			if(found==count)
				printf("찾는 단어가 없습니다\n");
		}
		Sleep(1000);
		system("cls");
	}
	menu_scr();
}

void WordListCheck(void)
{
	int i=0;
	int count;
	FILE *fp;
	if((fp = fopen("Voca.txt","r"))==NULL)
	{
		fprintf(stderr,"파일 Voca.txt를 열 수 없습니다\n","Voca.txt");
	}
	while(!feof(fp))
	{
		fgets(a[i].name,100,fp);
		a[i].name[strlen(a[i].name)-1]='\0';
		fgets(a[i].mean,100,fp);
		a[i].mean[strlen(a[i].mean)-1]='\0';
		i++;
	}
	fclose(fp);
	count=i;
	for(i=0;i<count;i++)
		printf("[ %s : %s ]\n",a[i].name,a[i].mean);//"wt"옆으로
}

int ProgramRead(void)
{
	int i=0;
	FILE *fp;
	if((fp = fopen("Voca.txt","r"))==NULL)
	{
		fprintf(stderr,"Voca.txt 파일을 열 수 없습니다.\n","Vocabulary Note.txt");
		exit(1);
	}
	while(!feof(fp))
	{
		fgets(a[i].name,100,fp);
		fgets(a[i].mean,100,fp);
		i++;
	}
	fclose(fp);
	return i;
}
//void Quiz(void)
