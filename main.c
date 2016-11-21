#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include <conio.h>
#include <string.h>
#define UP 72//위쪽 방향키
#define DOWN 80//아래쪽 방향키
#define ENTER 13//엔터키
#define ESC 27//ESC 키
#define WORDCOUNT 10

//====================
typedef struct wordlist{
	char name[100]; //단어
	char mean[200]; //뜻
}VOCA;
VOCA a[WORDCOUNT];

//함수 넣는존
//==============================================-changun
int Calculator_Menu(); //계산기 메인 메뉴
int Matrix_Menu(); //행렬 계산 메뉴
int ACalculator_Menu(); //사칙연산 메뉴
int Stopwatch();//스톱워치 메뉴
//==============================================-changun
=======
int ACalulator_Menu(); //사칙연산 메뉴

//==============================================-changun
//================================================-SungHo
void gotoxy(int x, int y);//좌표 함수
void menu_scr(void);//단어장 메뉴화면을 출력하는 함수
void Function(int y);//단어장 해당 메뉴에 접속하는 함수
int MenuChoice(void); //단어장 메뉴를 가리키는 화살표를 이동시키는 함수
void AddWord(void);//단어장 단어추가 기능
void SearchWord(void);//단어장 단어검색 기능
void WordListCheck(void);//단어장 저장내용 확인기능
//================================================-SungHo

//====================
int main()
{
	int main_switch_num = 0;  //메인문에 스위치 값을 받기 위한 변수 - 사용자 입력 값
	int main_end=0;   //메인문을 종료시키기 위한 변수
	int End_C=0, C_M, CM_M, AC_M; //End_C:메인문에서 계산기메뉴를 종료하기 위한 변수 C_M : 계산기 메뉴 CM_M : 행렬계산 메뉴 AC_M : 일반 계산기 메뉴

	system("title Learing Support Program");  //제목 변화
	while (1)  //프로그램 반복
	{  //while 중괄호

		printf("=====================================================================\n");
		printf("                    Learing Support Program \n");
		printf("=====================================================================\n");
		printf(" 1.학습 계획표\n");
		printf(" 2.학습 통계표\n");
		printf(" 3.계 산 기 \n");
		printf(" 4.단 어 장\n");
		printf(" 5.타 이 머\n");
		printf(" 6.알 람\n");
		printf(" 7.스톱워치\n");
		printf(" 8.달 력\n");
		printf(" 9.종 료\n");
		printf("원하시는 메뉴에 숫자를 입력해주세요:");
		scanf_s("%d", &main_switch_num);

		switch (main_switch_num)
		{
		case 1:
			//학습 계획표
			break;
		case 2:
			//학습 통계표
			break;
		case 3: //===============================================계산기 - changun
			while(1)
			{
			C_M=Calculator_Menu();  //계산기 메뉴를 호출하고 사용자 입력값을 돌려받음
			switch (C_M)
						{
							case 1:
							CM_M=Matrix_Menu(); //행렬 계산기 메뉴
							break;
							case 2:
							AC_M = ACalculator_Menu(); //일반 계산기 메뉴
							break;
							case 3:
							End_C=10; //End_c에 10을 넣어줘서 반복문 탈출
							break;
							default:
							break;
						}//C_M _ switch문 중괄호
						if(End_C==10)
						break;//계산기 while에 따른 브레이크
		}//main_switch_num_case 3: while 중괄호
			break;//main_switch_num 3: break===============================-changun
		case 4:
			//단어장
			 system("cls");
			 menu_scr();
			 MenuChoice();
			break;
		case 5:
			//타이머
			break;
		case 6:
			//알람
			break;
		case 7: //===================================================-changun
			   StopWatch();//스톱워치
			break;//=====================================================-changun
		case 8:
			//달력
		case 9:
			main_end = 100;
			break;
		default:
			printf("잘못 누르셨습니다.\n");
			break;
		}

		if (main_end == 100)    //종료를 위해 쓰인 if문과 변수
		{
			printf("프로그램을 종료합니다.\n");
			exit(1);  //탈출 명령어
		}//if문 - 종료 중괄호
	} //while 중괄호
	return 0;
}

//===============================-changun

int Calculator_Menu()
{
	int user_num;
	printf("===========================\n");
	printf("         Calculator\n");
	printf("===========================\n");
	printf(" 1.행렬 계산기\n");
	printf(" 2.일반 계산기\n");
	printf(" 3.되돌아가기\n");
	scanf_s("%d",&user_num);
	return user_num;
}


int Matrix_Menu()
{
	int user_num;
	printf("===========================\n");
	printf("     Matrix Calculator\n");
	printf("===========================\n");
	printf(" 1.행렬 덧셈\n");
	printf(" 2.행렬 곱셈\n");
	printf(" 3.역행렬의 유무\n");
	printf(" 3.나가기\n");
	scanf_s("%d", &user_num);
	return user_num;
}

int ACalculator_Menu()
{
		int user_num;
		printf("===========================\n");
		printf("       Calculator\n");
		printf("===========================\n");
		printf(" 1.수 입력\n");
		printf(" 2.수식 입력\n");
		printf(" 3.나가기\n");
		scanf_s("%d", &user_num);
		return user_num;
}
void Stopwatch()
{
		printf("===========================\n");
		printf("        StopWatch\n");
		printf("===========================\n");
		printf(" 1.시 작\n");
		printf(" 2.중 지\n");
		printf(" 3.기 록\n");
		printf(" 4.나가기\n");
}
//================================================-changun

//================================================-SungHo
void gotoxy(int x, int y) //좌표함수 콘솔창내 커서의 좌표지정
{
   COORD Pos = {x , y };
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int MenuChoice(void)
{
	int key;//입력받은 키의 int값을 저장할 변수
	int x=47,y=11;//화살표의 시작 좌표 지정 x :x축 좌표  y:y축 좌표

	while(1)
	{
		key=getch();
		if(key == 0xE0 || key ==0)
		key = getch();
		switch(key)
		{
			case UP: //위쪽 방향키를 입력받으면
			system("cls");
			menu_scr();//메뉴창을 띄우고
			y-=2;	   //화살표("=>")의 y좌표를 2칸 아래로 내림
			if(y<=11)  //화살표("=>")의 y좌표가 메뉴 위쪽으로는 올라가지 않도록 단어검색과 같은 높이인 11까지만 올라가도록 고정
				y=11;
			gotoxy(x,y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

			case DOWN://아래쪽 방향키를 입력받으면
			system("cls");
			menu_scr();//메뉴창을 띄우고
			y+=2;	   //화살표("=>")의 y좌표를 2칸 위로 올림
			if(y>=17)  //화살표("=>")의 y좌표가 메뉴 아래쪽으로는 내려가지 않도록 단어퀴즈와 같은 높이인 17까지만 내려가도록 고정
				y=17;
			gotoxy(x,y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

			case ESC:
				 system("cls");
				 system("color 07");
				 return 0;

			case ENTER://엔터키를 입력받으면
				 Function(y);
		}

	}

}

void menu_scr(void)//메뉴 화면을 출력
{

	system("title 단어장");//콘솔의 제목을 바꿔줌
	system("color EC");//콘솔창의 배경색과 텍스트의 색을 바꿔줌  (배경:텍스트) E:노랑C:빨강


	printf("=======================================");
	gotoxy(50,11);
	printf("◆단어 검색\n");
	gotoxy(50,13);
	printf("◆단어 추가\n");
	gotoxy(50,15);
	printf("◆단어장 확인\n");
	gotoxy(50,17);
	printf("◆단어 퀴즈\n");
	gotoxy(46,23);
	printf("※프로그램 종료 [ESC]\n");

}

void Function (int y)
{
	 if(y==11)//단어 검색 화살표("=>")의 y좌표를 가져와서 화살표가 가리키는 메뉴를 실행
	    {
			system("cls");
			SearchWord();
	    }
	 if(y==13)//단어 추가 실행
	    {
			system("cls");
			AddWord();
	    }
	 if(y==15)//단어 확인 실행
	    {
			system("cls");
			 WordListCheck();
	    }
	 if(y==17)//단어 퀴즈 실행
	    {
			system("cls");
			printf("퀴즈");
	    }
}

void AddWord(void)//단어 추가 기능
{

	int i,key; //i for문 실행에 쓰일 변수 ,key: ENTER키나 ESC키로 받은 값을 저장받음
	for(i=0;i<WORDCOUNT;i++)
	{
		printf("추가하실 단어를 입력해주세요\n");
		gets(a[i].name);
		printf("단어의 뜻을 입력해주세요\n");
		gets(a[i].mean);
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
	label://goto 문으로 빠져나오는 곳
	menu_scr();
}

void SearchWord(void) //단어 검색
{
	int i;//for문을 돌리는데 쓰임
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
		for(i=0;i<WORDCOUNT;i++)
		{
			found++;
			if(!strcmp(a[i].name,target)||!strcmp(a[i].mean,target))
			{
				system("cls");
				printf("%s: %s\n",a[i].name,a[i].mean);
				found--;
			}
			if(found==WORDCOUNT)
				printf("찾는 단어가 없습니다\n");
		}
		Sleep(1000);
		system("cls");
	}
	menu_scr();
}

void WordListCheck(void)//저장한 단어를 전부 출력해줌
{
	int i;
	for(i=0;i<WORDCOUNT;i++)
		printf("[ %s : %s ]\n",a[i].name,a[i].mean);
}


//================================================-SungHo
