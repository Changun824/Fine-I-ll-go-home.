/* 푸시 풀 확인 요망
*/

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
#define WORDCOUNT 1000
#define MAX 100 //Changun 씀 행렬 계산을 위해 사용

//================================================================== - sungho
typedef struct wordlist {
	char name[100]; //단어
	char mean[200]; //뜻
}VOCA;
VOCA a[WORDCOUNT];
//================================================================ - sungho

//================================================================-sungjae
typedef struct user {//사용자 입력 시간 구조체
	int hour;//시
	int min;//분
	int sec;//초
}USER;
typedef struct plan {
	char pi1[50], pi2[50], pi3[50], pi4[50], pi5[50], pi6[50], pi7[50], pi8[50], pi9[50], pi10[50], pi11[50], pi12[50], pi13[50], pi14[50], pi15[50], pi16[50];
	//pi1~16배열은 1주차부터 16주차까지의 계획저장 변수
	char c1[10], c2[10], c3[10], c4[10], c5[10], c6[10], c7[10], c8[10], c9[10], c10[10], c11[10], c12[10], c13[10], c14[10], c15[10], c16[10];
	//달성 체크시 사용
}PLAN;//PLAN구조체는 계획 문자열 저장하기 위해서 사용
	  //================================================================-sungjae

	  //함수 넣는존
	  //===============================================================-main
void main_menu();
int menu_switch();
//===============================================================-main
//==============================================-changun
int Calculator_Menu(); //계산기 메인 메뉴
int Matrix_Menu(); //행렬 계산 메뉴
int ACalulator_Menu(); //사칙연산 메뉴
int calculator_key();// 계산기 메뉴에서 =>를 위한 함수
void Matrix_add(); //행렬 덧셈
int Matrix_key();
void Matrix_mul(); // 행렬 곱셈
void stop_watch(); //스톱워치
void stopwatch_menu(); //스톱 워치 메뉴
//==============================================-changun
//================================================-SungHo
void gotoxy(int x, int y);//좌표 함수
void menu_scr(void);//단어장 메뉴화면을 출력하는 함수
void Function(int y);//단어장 해당 메뉴에 접속하는 함수
int MenuChoice(void); //단어장 메뉴를 가리키는 화살표를 이동시키는 함수
void AddWord(void);//단어장 단어추가 기능
void SearchWord(void);//단어장 단어검색 기능
void WordListCheck(void);//단어장 저장내용 확인기능
int ProgramRead(void);
void Quiz(void);
void del(void);
//================================================-SungHo
//================================================-seokhoon
void calender();
//================================================-seokhoon
//===============================================-sungjae
int alarm();//알람함수
int timer();//타이머함수
void learningplanner();//학습계획표 메뉴 함수
int planinsert();//계획 입력 함수
int achievementcheck();//달성체크함수
int achievementrate();//달성률보기함수
int timetable();//시간표 출력함수
				//===============================================-sungjae

				//==================================main메뉴존
int main()
{
	int main_switch = 0;  //메인문에 스위치 값을 받기 위한 변수 - 사용자 입력 값
	int main_end = 0;   //메인문을 종료시키기 위한 변수
	int End_C = 0, C_M, CM_M, AC_M; //End_C:메인문에서 계산기메뉴를 종료하기 위한 변수 C_M : 계산기 메뉴 CM_M : 행렬계산 메뉴 AC_M : 일반 계산기 메뉴
	int num = 0;
	system("mode con: cols=70 lines=30"); //크기
	system("title Learing Support Program");  //제목 변화
	system("color 3F");
	while (1)  //프로그램 반복
	{  //while 중괄호
		system("cls");

		main_menu();
		num = menu_switch();
		switch (num)
		{
		case 5:
			system("cls");
			learningplanner();
			//학습 계획표
			break;
		case 6:
			//학습 통계표
			break;
		case 7: //===============================================계산기 - changun
			system("cls");
			while (1)
			{
				Calculator_Menu();  //계산기 메뉴를 호출하고 사용자 입력값을 돌려받음
				C_M = calculator_key();
				switch (C_M)
				{
				case 4:
					Matrix_Menu();
					CM_M = Matrix_key(); //행렬 계산기 메뉴
					switch (CM_M)
					{
					case 4:
						Matrix_add();
						break;
					case 6:
						system("cls");
						Matrix_mul();
						break;
					case 8:
						break;
					case 10:
						main();
						break;
					default:
						break;
					}// 행렬계산기에 대한 switch
					break;
				case 6:
					system("cls");
					AC_M = ACalulator_Menu(); //일반 계산기 메뉴
					break;
				case 8:
					End_C = 10; //End_c에 10을 넣어줘서 반복문 탈출
					break;
				default:
					break;
				}//C_M _ switch문 중괄호
				if (End_C == 10)
					break;//계산기 while에 따른 브레이크
			}//main_switch_num_case 3: while 중괄호
			break;//main_switch_num 3: break===============================-changun
		case 8:
			//단어장
			system("cls");
			ProgramRead();
			menu_scr();
			MenuChoice();
			break;
		case 9:
			system("cls");
			timer();
			//타이머
			break;
		case 10:
			system("cls");
			alarm();
			//알람
			break;
		case 11:
			system("cls");
			stop_watch();
			break;
		case 12:
			system("cls");
			calender();//달력
		case 13:
			main_end = 100;
			break;
		default:
			printf("잘못 누르셨습니다.\n");
			break;
		}

		if (main_end == 100)    //종료를 위해 쓰인 if문과 변수
		{
			system("cls");
			printf("프로그램을 종료합니다.\n");
			exit(1);  //탈출 명령어
		}//if문 - 종료 중괄호
	} //while 중괄호
	return 0;
}
//=============================================================-main
void main_menu()
{
	system("title Learing Support Program");  //제목 변화
	system("color 3F");
	printf("=====================================================================\n");
	printf("                    Learing Support Program \n");
	printf("=====================================================================\n");
	gotoxy(18, 5);
	printf(" 1. 학  습  계  획  표\n");
	gotoxy(18, 6);
	printf(" 2. 학  습  통  계  표\n");
	gotoxy(18, 7);
	printf(" 3. 계  산  기 \n");
	gotoxy(18, 8);
	printf(" 4. 단  어  장\n");
	gotoxy(18, 9);
	printf(" 5. 타  이  머\n");
	gotoxy(18, 10);
	printf(" 6. 알   람\n");
	gotoxy(18, 11);
	printf(" 7. 스 톱 워 치\n");
	gotoxy(18, 12);
	printf(" 8. 달   력\n");
	gotoxy(18, 13);
	printf(" 9. 종   료\n");
}
int menu_switch()
{
	int key;//입력받은 키의 int값을 저장할 변수
	int x = 16, y = 5;//화살표의 시작 좌표 지정 x :x축 좌표  y:y축 좌표

	while (1)
	{
		key = getch();//키를 입력 받으면
		if (key == 0xE0 || key == 0)
			key = getch();
		switch (key)
		{
		case UP: //위쪽 방향키를 입력받으면
			system("cls");
			main_menu(); //메뉴창을 띄우고
			y -= 1;	   //화살표("=>")의 y좌표를 1칸 아래로 내림
			if (y <= 5)  //화살표("=>")의 y좌표가 메뉴 위쪽으로는 올라가지 않도록 고정
				y = 5;
			gotoxy(x, y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

		case DOWN://아래쪽 방향키를 입력받으면
			system("cls");
			main_menu();//메뉴창을 띄우고
			y += 1;	   //화살표("=>")의 y좌표를 1칸 위로 올림
			if (y >= 13)  //화살표("=>")의 y좌표가 메뉴 아래쪽으로는 내려가지 않도록 함
				y = 13;
			gotoxy(x, y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

		case ESC:
			system("cls");
			system("color 07");
			return 0;

		case ENTER://엔터키를 입력받으면
			return y;
		}

	}

}
//=============================================================-main
//===============================-changun

int Calculator_Menu()  //계산기 메뉴
{
	system("title Calculator");  //제목 변화
	system("color 1F");
	system("cls");
	printf("=====================================================================\n");
	printf("                      C a l c u l a t o r \n");
	printf("=====================================================================\n");
	gotoxy(4, 4);
	printf(" 1.행렬 계산기\n\n");
	gotoxy(4, 6);
	printf(" 2.일반 계산기\n\n");
	gotoxy(4, 8);
	printf(" 3.되돌아가기\n\n");
}
int calculator_key()
{
	int key;//입력받은 키의 int값을 저장할 변수
	int x = 2, y = 4;//화살표의 시작 좌표 지정 x :x축 좌표  y:y축 좌표

	while (1)
	{
		key = getch();//키를 입력 받으면
		if (key == 0xE0 || key == 0)
			key = getch();
		switch (key)
		{
		case UP: //위쪽 방향키를 입력받으면
			system("cls");
			Calculator_Menu(); //메뉴창을 띄우고
			y -= 2;	   //화살표("=>")의 y좌표를 1칸 아래로 내림
			if (y <= 4)  //화살표("=>")의 y좌표가 메뉴 위쪽으로는 올라가지 않도록 고정
				y = 4;
			gotoxy(x, y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

		case DOWN://아래쪽 방향키를 입력받으면
			system("cls");
			Calculator_Menu();//메뉴창을 띄우고
			y += 2;	   //화살표("=>")의 y좌표를 1칸 위로 올림
			if (y >= 8)  //화살표("=>")의 y좌표가 메뉴 아래쪽으로는 내려가지 않도록 함
				y = 8;
			gotoxy(x, y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

		case ESC:
			system("cls");
			system("color 07");
			return 0;

		case ENTER://엔터키를 입력받으면
			return y;
		}

	}
}

int Matrix_Menu()        //행렬 계산기 메뉴
{
	system("title Matrix Calculator");  //제목 변화
	system("cls");
	printf("=====================================================================\n");
	printf("              M a t r i x  C a l c u l a t o r\n");
	printf("=====================================================================\n");
	gotoxy(4, 4);
	printf(" 1.행렬 덧셈\n\n");
	gotoxy(4, 6);
	printf(" 2.행렬 곱셈\n\n");
	gotoxy(4, 8);
	printf(" 3.역행렬의 유무\n\n");
	gotoxy(4, 10);
	printf(" 4.나가기\n");
}

int Matrix_key()
{
	int key;//입력받은 키의 int값을 저장할 변수
	int x = 2, y = 4;//화살표의 시작 좌표 지정 x :x축 좌표  y:y축 좌표

	while (1)
	{
		key = getch();//키를 입력 받으면
		if (key == 0xE0 || key == 0)
			key = getch();
		switch (key)
		{
		case UP: //위쪽 방향키를 입력받으면
			system("cls");
			Matrix_Menu(); //메뉴창을 띄우고
			y -= 2;	   //화살표("=>")의 y좌표를 1칸 아래로 내림
			if (y <= 4)  //화살표("=>")의 y좌표가 메뉴 위쪽으로는 올라가지 않도록 고정
				y = 4;
			gotoxy(x, y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

		case DOWN://아래쪽 방향키를 입력받으면
			system("cls");
			Matrix_Menu();//메뉴창을 띄우고
			y += 2;	   //화살표("=>")의 y좌표를 1칸 위로 올림
			if (y >= 10)  //화살표("=>")의 y좌표가 메뉴 아래쪽으로는 내려가지 않도록 함
				y = 10;
			gotoxy(x, y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

		case ESC:
			system("cls");
			system("color 07");
			return 0;

		case ENTER://엔터키를 입력받으면
			return y;
		}

	}
}

int ACalulator_Menu()    //사친연산 계산기 메뉴
{
	system("cls");
	int user_num;
	printf("=====================================================================\n");
	printf("                     C a l c u l a t o r \n");
	printf("=====================================================================\n");
	printf(" 1.수 입력\n");
	printf(" 2.수식 입력\n");
	printf(" 3.나가기\n");
	scanf_s("%d", &user_num);
	return user_num;
}
void Matrix_add()  //행렬 덧셈
{
	int exone[MAX][MAX];
	int extwo[MAX][MAX];
	int exsum[MAX][MAX];
	int matrix_mrow;
	int matrix_mcolumn;
	int i = 0, j = 0;
	system("cls");
	system("title 행렬 덧셈");  //제목 변화
	printf("=====================================================================\n");
	printf("                     M a t r i x   A d d \n");
	printf("=====================================================================\n");
	printf("더해줄 행렬은 같은 크기여야 합니다.\n");
	printf("\n");
	printf("덧셈 할 행렬의 행의 크기를 입력해주세요:");
	printf("\n");
	scanf_s("%d", &matrix_mrow);
	printf("덧셈 할 행렬의 열의 크기를 입력해주세요:");
	printf("\n");
	scanf_s("%d", &matrix_mcolumn);
	system("pause");

	system("cls");
	system("title 첫번째 행렬 입력");  //제목 변화
	printf("=====================================================================\n");
	printf("                     F i r s t   M a t r i x\n");
	printf("=====================================================================\n");
	printf("\n");
	printf("첫번째 행렬 \n");
	printf("\n");
	for (i = 0; i < matrix_mrow; i++)
		for (j = 0; j < matrix_mcolumn; j++)
		{
			printf("행렬 A[%d][%d]", i, j);
			scanf("%d", &exone[i][j]);
		}//첫번째 행렬 입력
	system("cls");
	system("title 두번째 행렬 입력");  //제목 변화
	printf("=====================================================================\n");
	printf("                    S e c o n d   M a t r i x \n");
	printf("=====================================================================\n");
	printf("\n");
	printf("두번째 행렬 \n");
	printf("\n");
	for (i = 0; i < matrix_mrow; i++)
		for (j = 0; j < matrix_mcolumn; j++)
		{
			printf("행렬 B[%d][%d]", i, j);
			scanf("%d", &extwo[i][j]);
		}//두번째 행렬 입력
	system("cls");
	system("title 두행렬의 합");  //제목 변화
	printf("=====================================================================\n");
	printf("                    M a t r i x  Add\n");
	printf("=====================================================================\n");
	printf("\n");
	printf("\n");
	printf("첫번째 행렬\n");
	for (i = 0; i < matrix_mrow; i++)
	{
		printf("\n");
		for (j = 0; j < matrix_mcolumn; j++)
		{
			printf("%d\t", exone[i][j]);
		} //행을 출력
	}//열을 출력
	printf("\n");
	printf("\n");
	printf("두번째 행렬 \n");
	for (i = 0; i < matrix_mrow; i++)
	{
		printf("\n");
		for (j = 0; j < matrix_mcolumn; j++)
		{
			printf("%d\t", extwo[i][j]);
		} //행을 출력
	}//열을 출력


	for (i = 0; i < matrix_mrow; i++)
	{
		for (j = 0; j < matrix_mcolumn; j++)
		{
			exsum[i][j] = exone[i][j] + extwo[i][j];
		}//두번째 행렬 입력

	}
	printf("\n");
	printf("\n");
	printf("덧셈한 행렬 \n");
	printf("\n");
	for (i = 0; i < matrix_mrow; i++)
	{
		for (j = 0; j < matrix_mcolumn; j++)
		{
			printf("%d\t", exsum[i][j]);
		} //행을 출력
		printf("\n");
	}//열을 출력
	system("PAUSE");

}// void Matrix_add() 함수 종료 중괄호

void Matrix_mul()  //행렬 곱셈 함수
{
	int exone[MAX][MAX];
	int extwo[MAX][MAX];
	int sum[MAX][MAX];
	int matrix_arow, matrix_acolumn;
	int matrix_bcolumn, matrix_brow;
	int i = 0, j = 0, z = 0;
	system("cls");
	system("title 행렬 곱셈");
	printf("=====================================================================\n");
	printf("                      MATRIX MULTIPCATION\n");
	printf("=====================================================================\n");
	printf("\n");
	printf("곱하기를 할 A[m][n], B[m][n]은 A[n]과 B[m]이 같아야 합니다\n ");
	printf("\n");
	printf("곱셈 할 행렬의 A행렬의 크기를 입력해주세요 A[m][n]:");
	printf("\n");
	scanf_s("%d %d", &matrix_arow, &matrix_acolumn);

	printf("곱셈 할 행렬의 B행렬의 크기를 입력해주세요:");
	printf("\n");
	scanf_s("%d %d", &matrix_brow, &matrix_bcolumn);
	if (matrix_acolumn != matrix_brow)
	{
		system("cls");
		system("title Error");
		printf("=====================================================================\n");
		printf("                      MATRIX MULTIPCATION\n");
		printf("=====================================================================\n");
		printf("곱하기가 불가능한 행렬 입니다.\n");
		return;
	}
	system("cls");
	system("title Amatrix");
	printf("=====================================================================\n");
	printf("                         A MATRIX\n");
	printf("=====================================================================\n");
	printf("\n");
	printf("첫번째 행렬 \n");
	for (i = 0; i < matrix_arow; i++)
		for (j = 0; j < matrix_acolumn; j++)
		{
			printf("exone[%d][%d]", i, j);
			scanf("%d", &exone[i][j]);
		}//첫번째 행렬 입력
	system("cls");
	system("title Bmatrix");
	printf("=====================================================================\n");
	printf("                         B MATRIX\n");
	printf("=====================================================================\n");
	printf("\n");
	printf("두번째 행렬 \n");
	for (i = 0; i < matrix_brow; i++)
		for (j = 0; j < matrix_bcolumn; j++)
		{
			printf("extwo[%d][%d]", i, j);
			scanf("%d", &extwo[i][j]);
		}//두번째 행렬 입력
	printf("\n");
	//곱을 위한 포문
	for (i = 0; i < matrix_arow; i++)
	{
		for (j = 0; j < matrix_bcolumn; j++)
		{
			sum[i][j] = 0;
			for (z = 0; z < matrix_brow; z++)
			{
				sum[i][j] = sum[i][j] + exone[i][z] * extwo[z][j];
			}
		}//곱해줄 행렬 계산
	}//곱에 필요한 for문

	system("cls");
	system("title MATRIX MULTIPCATION");
	printf("=====================================================================\n");
	printf("                         MATRIX MULTIPCATION\n");
	printf("=====================================================================\n");
	printf("\n");
	printf("첫번째 행렬\n");
	for (i = 0; i < matrix_arow; i++)
	{
		printf("\n");
		for (j = 0; j < matrix_acolumn; j++)
			printf("%d \t", exone[i][j]);
	} //첫번째 행렬 중괄호

	printf("\n");
	printf("두번째 행렬\n");
	for (i = 0; i < matrix_brow; i++)
	{
		printf("\n");
		for (j = 0; j < matrix_bcolumn; j++)
			printf("%d \t", extwo[i][j]);
	} //두번째 행렬 중괄호

	printf("\n");
	printf("행렬을 곱한 값\n");
	for (i = 0; i < matrix_acolumn; i++)
	{
		printf("\n");
		for (j = 0; j < matrix_brow; j++)
			printf("%d \t", sum[i][j]);
	} //합을 출력하는 중괄호
	printf("\n");
	system("PAUSE");
}//행렬 곱셈 함수 종료

void stop_watch()  //스탑 워치 함수
{
	int hour = 0, min = 0, sec = 0, frame = 0;
	char ch;
	stopwatch_menu();
	while (1)
	{
		printf("%2d : %2d : %2d : %2d", hour, min, sec, frame);
		Sleep(10);
		frame++;
		if (frame == 100)
		{
			sec++;
			frame = 0;
		}
		if (sec == 60)
		{
			min++;
			sec = 0;
		}
		if (min == 60)
		{
			hour++;
			min = 0;
		}

		if (kbhit())
		{
			ch = getch();
			switch (ch)
			{
			case 'S': case 's':
				ch = getch();
				break;
			case 'R': case 'r':
				system("cls");
				stopwatch_menu();
				hour = min = sec = frame = 0;
				break;
			case 'Q': case 'q':
				printf("\n");
				return;
			case 'W': case 'w':
				printf("\n");
				printf("\t\t ");
				break;
			default:
				break;
			} //키보드로 부터 입력 받은 값에 대한 switch
		} // if문 키보드로 부터 무엇인가 입력 받았다면
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	}// 시간에 대한 반복문 중괄호
} // 스탑워치 메인 코드 함수
void stopwatch_menu()  //스탑 워치 메뉴
{
	system("cls");
	printf("======================================================\n");
	printf("                   Stop Watch\n");
	printf("======================================================\n");
	printf("S:시작/멈춤 \nW: 기록\nR:리셋\nQ:나가기\n");
	printf("시 : 분 : 초 :0.01초\n");
}

//================================================-changun

//================================================-SungHo
void gotoxy(int x, int y) //좌표함수 콘솔창내 커서의 좌표지정
{
	COORD Pos = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int MenuChoice(void)
{
	int key;//입력받은 키의 int값을 저장할 변수
	int x = 47, y = 11;//화살표의 시작 좌표 지정 x :x축 좌표  y:y축 좌표

	while (1)
	{
		key = getch();
		if (key == 0xE0 || key == 0)
			key = getch();
		switch (key)
		{
		case UP: //위쪽 방향키를 입력받으면
			system("cls");
			menu_scr();//메뉴창을 띄우고
			y -= 2;	   //화살표("=>")의 y좌표를 2칸 아래로 내림
			if (y <= 11)  //화살표("=>")의 y좌표가 메뉴 위쪽으로는 올라가지 않도록 단어검색과 같은 높이인 11까지만 올라가도록 고정
				y = 11;
			gotoxy(x, y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

		case DOWN://아래쪽 방향키를 입력받으면
			system("cls");
			menu_scr();//메뉴창을 띄우고
			y += 2;	   //화살표("=>")의 y좌표를 2칸 위로 올림
			if (y >= 19)  //화살표("=>")의 y좌표가 메뉴 아래쪽으로는 내려가지 않도록 단어퀴즈와 같은 높이인 17까지만 내려가도록 고정
				y = 19;
			gotoxy(x, y);
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
	gotoxy(50, 11);
	printf("◆단어 검색\n");
	gotoxy(50, 13);
	printf("◆단어 추가\n");
	gotoxy(50, 15);
	printf("◆단어장 확인\n");
	gotoxy(50, 17);
	printf("◆단어 퀴즈\n");
	gotoxy(50, 19);
	printf("◆단어 삭제\n");
	gotoxy(46, 23);
	printf("※프로그램 종료 [ESC]\n");

}

void Function(int y)
{
	if (y == 11)//단어 검색 화살표("=>")의 y좌표를 가져와서 화살표가 가리키는 메뉴를 실행
	{
		system("cls");
		SearchWord();
	}
	if (y == 13)//단어 추가 실행
	{
		system("cls");
		AddWord();
	}
	if (y == 15)//단어 확인 실행
	{
		system("cls");
		WordListCheck();
	}
	if (y == 17)//단어 퀴즈 실행
	{
		system("cls");
		Quiz();
	}
	if (y == 19)//단어 퀴즈 실행
	{
		system("cls");
		del();
	}

}

void AddWord(void)//단어 추가 기능
{
	int i = 0, key; //i for문 실행에 쓰일 변수 ,key: ENTER키나 ESC키로 받은 값을 저장받음
	int count;
	FILE *fp;
	if ((fp = fopen("Voca.txt", "a")) == NULL)
	{
		fprintf(stderr, "파일 Voca.txt를 열 수 없습니다\n", "Voca.txt");
	}
	while (1)
	{
		printf("추가하실 단어를 입력해주세요\n");
		gets(a[i].name);
		printf("단어의 뜻을 입력해주세요\n");
		gets(a[i].mean);
		i++;
		printf("단어를 더 추가합니까? 추가[ENTER] 종료[ESC]\n");//단어를 한 개 추가하고 나서 계속 추가할 것인지 키를 입력받아 사용자의 의사를 묻는다
		key = getch();										    //ENTER는 더 추가 ESC를 입력하면 종료 N
		if (key == 0xE0 || key == 0)
			key = getch();
		if (key == 27)//ESC키를 입력하면
		{
			system("cls");
			break;   //루프를 종료:[단어 검색]기능을 종료
		}
		else if (key == 13)//ENTER키를 입력하면 콘솔창을 깨끗하게 지우고 다시 처음 루프로 가서 추가할 단어를 입력받음
		{
			system("cls");
		}
		else {//ENTER 와 ESC가 아닌 키를 입력했을 경우
			while (1)
			{
				system("cls");
				printf("추가[ENTER] 또는 종료[ESC] 키를 입력하세요\n"); //ENTER나 ESC를 입력할때까지 안내 메세지를 띄우고
				key = getch();
				if (key == 0xE0 || key == 0);
				key = getch();
				if (key == 13)//Enter를 입력받으면 이 루프를 빠져나가 단어를 새로 입력받고
				{
					system("cls");
					break;
				}
				else if (key == 27)//ESC를 누르면
				{
					system("cls");
					goto label;   //이중 루프를 빠져나가서 기능이 종료되게끔 한다.
				}
			}

		}

	}
	count = i;
label://goto 문으로 빠져나오는 곳
	for (i = 0; i<count; i++) {
		fputs(a[i].name, fp);
		fputc('\n', fp);//fputs 는 텍스트로 저장할때 엔터값을 안받기에 개행을 위해 붙여줌
		fputs(a[i].mean, fp);
		fputc('\n', fp);
	}
	fclose(fp);
	menu_scr();
}

void SearchWord(void)
{
	int i = 0, count;
	int key;
	FILE *fp;
	if ((fp = fopen("Voca.txt", "r")) == NULL)
	{
		fprintf(stderr, "파일 Voca.txt를 열 수 없습니다\n", "Voca.txt");
	}
	while (!feof(fp))
	{
		fgets(a[i].name, 100, fp);
		a[i].name[strlen(a[i].name) - 1] = '\0';
		fgets(a[i].mean, 100, fp);
		a[i].mean[strlen(a[i].mean) - 1] = '\0';
		i++;
	}
	fclose(fp);
	count = i - 1;
	while (1) {
		int found = 0;//찾은 수
		char target[100];
		char esc[8] = "종료.";
		printf("찾을 단어를 입력해주세요.종료하려면 [종료.]입력\n");
		gets(target);
		if (!strcmp(esc, target)) {
			system("cls");
			break;
		}
		for (i = 0; i<count; i++)
		{
			found++;
			if (!strcmp(a[i].name, target) || !strcmp(a[i].mean, target))
			{
				system("cls");
				printf("%s: %s\n", a[i].name, a[i].mean);
				found--;
			}
			if (found == count)
				printf("찾는 단어가 없습니다\n");
		}
		while (1) {
			printf("더 찾으시겠습니까? [ENTER]찾기,[ESC]종료\n");
			key = getch();
			if (key == 27)
			{
				system("cls");
				goto label;
			}
			else if (key == 13)
			{
				system("cls");
				break;
			}
			else
			{
				printf("[ENTER]찾기,[ESC]종료\n");
			}
		}
	}
label:
	menu_scr();
}

void WordListCheck(void)
{
	int i = 0;
	int key;
	int count;
	FILE *fp;
	if ((fp = fopen("Voca.txt", "r")) == NULL)
	{
		fprintf(stderr, "파일 Voca.txt를 열 수 없습니다\n", "Voca.txt");
	}
	while (!feof(fp))
	{
		fgets(a[i].name, 100, fp);
		a[i].name[strlen(a[i].name) - 1] = '\0';
		fgets(a[i].mean, 100, fp);
		a[i].mean[strlen(a[i].mean) - 1] = '\0';
		i++;
	}
	fclose(fp);
	count = i - 1;
	for (i = 0; i<count; i++)
		printf("[ %s : %s ]\n", a[i].name, a[i].mean);//"wt"옆으로
	printf("\n종료하시겠습니까?ESC입력\n");
	while (1) {
		key = getch();
		if (key == 27)
		{
			system("cls");
			break;
		}
	}
	menu_scr();
}

int ProgramRead(void)
{
	int i = 0;
	FILE *fp;
	if ((fp = fopen("Voca.txt", "r")) == NULL)
	{
		fprintf(stderr, "Voca.txt 파일을 열 수 없습니다.\n", "Vocabulary Note.txt");
		exit(1);
	}
	while (!feof(fp))
	{
		fgets(a[i].name, 100, fp);
		fgets(a[i].mean, 100, fp);
		i++;
	}
	fclose(fp);
	return i;
}
void Quiz(void) {
	int i = 0, count, j = 0, k, good = 0;
	int key;
	char input[100];
	FILE *fp;
	if ((fp = fopen("Voca.txt", "r")) == NULL)
	{
		fprintf(stderr, "파일 Voca.txt를 열 수 없습니다\n", "Voca.txt");
	}
	while (!feof(fp))
	{
		fgets(a[i].name, 100, fp);
		a[i].name[strlen(a[i].name) - 1] = '\0';
		fgets(a[i].mean, 100, fp);
		a[i].mean[strlen(a[i].mean) - 1] = '\0';
		i++;
	}
	fclose(fp);
	count = i - 1;
	printf("단어 퀴즈는 단어장 안에 있는 단어중 5개의 단어의 설명이 랜덤으로 나옵니다\n\n");
	Sleep(2500);
	printf("단어의 설명을 보고 어떤 단어를 설명하고 있는지 해당하는 단어를 키보드로 입력해주세요\n\n");
	Sleep(2500);
	printf("그럼 시작합니다.\n");
	Sleep(1500);
	for (j = 0; j<5; j++) {
		srand((unsigned)time(NULL));
		i = rand() % count;
		system("cls");
		printf("[%s]는 무엇일까요?:\n", a[i].mean);
		gets(input);
		if (!strcmp(a[i].name, input))
		{
			printf("정답입니다\n");
			Sleep(1000);
			good++;
		}
		else
		{
			for (k = 2; k>0; k--)
			{

				printf("틀리셨습니다. 잘 생각해 보세요\n");
				printf("남은 기회 [%d]번", k - 1);
				gets(input);
				if (!strcmp(a[i].name, input))
				{
					system("cls");
					printf("정답입니다\n");
					break;
				}
			}
		}
	}
	printf("5문제중 맞은 개수는 %d개 입니다\n", good);
	while (1)
	{
		printf("다시 하시겠습니까? 예ENTER 아니오ESC\n");// esc눌렀을때 무한루프
		key = getch();
		if (key == 13)
		{
			system("cls");
			Quiz();
		}
		if (key == 27)
		{
			system("cls");
			break;
		}
		else
		{
			system("cls");
			printf("잘못 누르셨습니다 다시하기 ENTER 아니오ESC");
		}
	}
	menu_scr();
}
void del(void)
{
	int i = 0, count;
	char target[100];
	FILE *fp;
	if ((fp = fopen("Voca.txt", "r")) == NULL)
	{
		fprintf(stderr, "파일 Voca.txt를 열 수 없습니다\n", "Voca.txt");
	}
	while (!feof(fp))
	{
		fgets(a[i].name, 100, fp);
		a[i].name[strlen(a[i].name) - 1] = '\0';
		fgets(a[i].mean, 100, fp);
		a[i].mean[strlen(a[i].mean) - 1] = '\0';
		i++;
	}
	fclose(fp);
	count = i - 1;
	printf("삭제하실 단어를 입력하세요\n");
	gets(target);
	for (i = 0; i<count; i++)
	{
		if (!strcmp(a[i].name, target))
		{
			printf("[%s]를 단어장에서 제거합니다.\n", a[i].name);
			strcpy(a[i].name, "\0");
			strcpy(a[i].mean, "\0");
		}

	}
	if ((fp = fopen("Voca.txt", "w")) == NULL)
	{
		fprintf(stderr, "파일 Voca.txt를 열 수 없습니다\n", "Voca.txt");
	}
	for (i = 0; i<count; i++)
	{
		if ((strcmp(a[i].name, "\0")) != 0)
		{
			fputs(a[i].name, fp);
			fputc('\n', fp);//fputs 는 텍스트로 저장할때 엔터값을 안받기에 개행을 위해 붙여줌
			fputs(a[i].mean, fp);
			fputc('\n', fp);
		}
	}
	fclose(fp);
	printf("메뉴로 돌아갑니다\n");
	Sleep(1000);
	system("cls");
	menu_scr();
}

//================================================-SungHo

//================================================-seokhoon
void calender() {
	int year = 0;//년을 입력받음
	int month = 0;//월을 입력받음
	int day = 1;//달력의 시작일을 찾기 위한 변수이다(시작일 전 공백을 찍는 횟수)
	int everyday = 0;//입력 달 까지의 그 년의 총 날짜 수
	int monthday[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//1~12월까지 일자수
																		   //배열의 첫번째는 배열의 0번 이므로 0을 넣고 1번 부터 날짜를 넣어 달과 배열의 번지를 맞추려했다.
	int yoonyear = 0;//윤년 스위치
	int preyear = 0;//입력 년 전 까지의 총 날짜 수
	int i;
	int j;
	int z;//1년 부터 입력한 년 까지 반복
	int w;
	char swch = 'h';//날짜를 w a s d로 이동시킬 스위치이다
	int start = 0;
	system("cls");
	printf("몇 년도를 입력하시겠나요?\n");
	scanf("%d", &year);
	printf("몇 월을 원하시나요?\n");
	scanf("%d", &month);

	if (month > 12) {
		printf("12월까지입니다!\n");
		return;
	}

	while (1) {

		monthday[2] = 28;
		yoonyear = 0;
		preyear = 0;
		everyday = 0;
		day = 1;

		if (((year) % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {//윤년인 경우
																		//윤년 4년에 한번, 100의 배수인 해는 평년, 400의 배수해는 윤년
			yoonyear = 1;//윤년이면 yoonyear를 1로 바꿔준다
		}

		for (z = 1; z < year; z++) {//입력한 년 전 까지의 총 일 수를 구하는것이다
			if (((z) % 4 == 0 && (z % 100 != 0 || z % 400 == 0))) {
				preyear = (preyear + 366) % 7;
				/*1년 부터 전부 계산하되 윤년인 날짜가 나오면 366일 임으로 366을 더한다, 나누기 7을 하는 이유는
				위 과정이 달력에서 시작일을 결정하는 것 이므로 한 줄에 출력 되는 7일을 미리 나누어 주는것이다
				미리 나누어주는 이유는 입력 년이 너무 크면 int 자료형의 크기를 초과 할 수도 있기 때문이다
				*/
			}
			else {
				preyear = (preyear + 365) % 7;
				/*평년일때는 365일 임으로 365을 더한다*/
			}
		}

		if (yoonyear == 1) {//yoonyear=1이면 윤년
			monthday[2] = 29;//2월 달에 해당하는 monnthday의 배열값을 28에서 29로 수정한다
		}

		preyear = preyear + 1;

		for (j = 1; j < month; j++) {//입력한 년의 입력한 월 까지의 날짜를 계산한다
			everyday += (monthday[j]) % 7;
			/*monthday에 0번째를 제외한 1번째 부터 입력한 월 까지의 번지의 값들을 전부 더하면
			입력한 년의 입력한 월 까지의 날짜를 구할 수 있다. 윤년인 경우에도 위에서 2번째를 28에서
			29로 수정하였으므로 정상적으로 계산이 가능하다 7일을 미리 나누어 주는 이유는 위의 주석과 같다*/
		}

		day = (preyear + everyday) % 7;
		/*day는 입력한 년 월의 전의 날짜를 모두 더한것에 7을 나눈것이다. 1월 1일 월요일을 시작으로
		달력의 1일 시작일은 그 전의 모든 날짜들의 영향을 받아 한칸씩 밀리기 때문이다. 다만 달력의
		한줄은 7칸 이므로 모든 날짜를 7로 나눈 나머지가 달력 첫줄 7칸에서 밀리는 갯수가 된다*/
		printf("%14d년 %d월\n", year, month);
		printf("  일  월  화  수  목  금  토\n"); //월화수목금토 출력
		for (w = 0; w < day; w++) {
			printf("    ");
		}

		for (i = 1; i <= monthday[month]; i++) {
			printf("%4d", i);//1는 1부터 입력한 월의 monthday번째의 크기만큼 1씩 증가하며 출력한다
			if ((i + day) % 7 == 0) {//7번째 칸 내림
				printf("\n");
			}
		}
		printf("\n");
		system("pause");


	}


}
//==================================================-seokhoon
//====================================================-sungjae
int alarm()      //시간을 알려주는 함수/메인에서 주소를 받아와 저장해주기 위해 포인터로 쓰임.
{
	int i = 0;
	USER utime;//사용자 입력 시간저장구조체
	time_t now;//현재시간을 받기위한 구조체
	struct tm *time_;//현재시간을 받기위한 구조체
	printf("========================\n");
	printf("==========ALARM=========\n");
	printf("========================\n");
	printf("알람이 울리는 시간을 입력해주세요...\n");
	printf("hour : "); scanf("%d", &utime.hour);//사용자가 입력하는 시
	printf("min : "); scanf("%d", &utime.min);//사용자가 입력하는 분
	while (1) {//무한루프로 사용자 입력시간과 비교함
		now = time(NULL);
		time_ = localtime(&now);//로컬시간을 불러와줌
		printf("현재 시간 : %2d시 %2d분 %2d초\n", time_->tm_hour, time_->tm_min, time_->tm_sec);//로컬시간 보여줌
		printf("입력 시간 : %2d시 %2d분\n", utime.hour, utime.min);//사용자 입력시간보여줌
		Sleep(200);
		system("cls");//화면지움
		if (utime.hour == time_->tm_hour&&utime.min == time_->tm_min)//사용자 입력시간과 같다면 빠져나옴
			break;
	}
	while (!_kbhit()) {
		printf("알람 작동!!!!\n");
		printf("아무키나 입력하시면 끝납니다.");
		Beep(262, 200);/* 도 음계 *///알람음 출력
		Beep(294, 200); /* 레 음계 */
		Beep(330, 200); /* 미 음계 */
		Beep(349, 200); /* 파 음계 */
		Beep(392, 200); /* 솔 음계 */
		Beep(440, 200); /* 라 음계 */
		Beep(494, 200); /* 시 음계 */
		Beep(524, 200); /* 도 음계 */
		Sleep(500);//0.5초 지연
		system("cls");
	}

	return 0;
}//====================================================-sungjae
int timer() {

	int a = 0, inmin = 0, insec = 0, inhour = 0, key = 0;
	printf("타이머의 시간을 입력해주세요\n");
	printf("min : ");
	scanf("%d", &inmin);
	printf("sec : ");
	scanf("%d", &insec);

	while (1) {
		if (inmin >= 60)//분이 60이 넘는다면
		{
			inmin -= 60;//분 -60을 해주고
			inhour++;//시간에 1을 더한다
		}
		else
			break;//아니라면 빠져나온다
	}
	while (1) {
		if (insec >= 60) {//초가 60이 넘는다면
			insec -= 60;//초에서 -60을 해주고
			inmin++;//분에 1을 더한다
		}
		else
			break;//아니라면 빠져나온다
	}
	if (inmin >= 60)//위에 똑같은 식이 잇지만 분이 60일경우가 잇어 다시써준다
	{
		inmin -= 60;
		inhour++;
	}
	while (1)
	{
		if (insec == 0 && inmin == 0 && inhour != 0)//시간이 흐를때 분이 0이되면 시간을 1빼고
		{
			inhour--;
			inmin = 60;//분을 60으로 만들어준다
		}
		if (insec == 0)//초가 0이되면
		{
			inmin--;//분에서 1을 빼주고
			insec = 59;//초를 59로 초기화시켜준다
		}
		printf("■■■■■■■■■■■■■\n");
		printf("■■■■■ Timer■■■■■\n");
		printf("■■■■■■■■■■■■■\n");
		printf("■      ■      ■      ■\n");
		printf("■  %2d  ■  %2d  ■  %2d  ■\n", inhour, inmin, insec);//타이머 시간 출력
		printf("■      ■      ■      ■\n");
		printf("■■■■■■■■■■■■■\n");
		Sleep(1000);//1초지연
		insec -= 1;//시간이 흐름을 나타냄
		system("cls");//화면 초기화

		if (insec == 0 && inmin == 0 && inhour == 0)//모두 0이되면
			break;//타이머종료/
	}

	while (!_kbhit()) {//아무키나 입력한다면 while문은 끝나게됨
		printf("타이머 종료!!!!\n");
		printf("아무키나 입력하시면 끝납니다.");
		Beep(262, 200);/* 도 음계 *///알람음 출력
		Beep(294, 200); /* 레 음계 */
		Beep(330, 200); /* 미 음계 */
		Beep(349, 200); /* 파 음계 */
		Beep(392, 200); /* 솔 음계 */
		Beep(440, 200); /* 라 음계 */
		Beep(494, 200); /* 시 음계 */
		Beep(524, 200); /* 도 음계 */
		Sleep(500);
		system("cls");
	}
	return 0;
}//====================================================-sungjae
void learningplanner()
{
	int b;//b는 사용자가 메뉴선택하는 변수

	while (1) {
		system("cls");
		printf("==================================\n");
		printf("         Learning  Planner        \n");
		printf("==================================\n");
		printf("1. 계획 입력\n");
		printf("2. 계획 달성 체크\n");
		printf("3. 달성률 보기\n");
		printf("4. 시간표(현재 이 기능은 잠겨있습니다.)\n");
		printf("5. 종료...\n");
		scanf("%d", &b);//사용자가 메뉴선택
		system("cls");
		if (b == 5)
			return;
		switch (b)
		{
		case 1:
			planinsert();//계획입력
			break;
		case 2: achievementcheck();//달성 체크
			break;
		case 3: achievementrate();//달성보기
			break;
		case 4: //timetable();
			break;
		default:
			break;
		}
	}
}
int planinsert()//계획입력함수
{
	FILE *fpin1;//1학기 계획을 파일에 저장하기 위해서 만든 파일포인터
	if ((fpin1 = fopen("plan1.txt", "w")) == NULL)
	{
		printf("plan1.txt에 쓰기를 실패하였습니다.\n");
	}
	FILE *fpin2;//2학기 계획을 파일에 저장하기 위해서 만든 파일포인터
	if ((fpin2 = fopen("plan2.txt", "w")) == NULL)
	{
		printf("plan2.txt에 쓰기를 실패하였습니다.\n");
	}
	int a = 0;
	PLAN insert;
	printf("1. 1학기 계획입력\n");
	printf("2. 2학기 계획입력\n");
	printf("3. 종료\n");
	scanf("%d", &a);
	system("cls");
	if (a == 1)
	{
		printf("1주차 계획 :  ");
		scanf("%s", insert.pi1, 50);
		printf("2주차 계획 :  ");
		scanf("%s", insert.pi2, 50);
		printf("3주차 계획 :  ");
		scanf("%s", insert.pi3, 50);
		printf("4주차 계획 :  ");
		scanf("%s", insert.pi4, 50);
		printf("5주차 계획 :  ");
		scanf("%s", insert.pi5, 50);
		printf("6주차 계획 :  ");
		scanf("%s", insert.pi6, 50);
		printf("7주차 계획 :  ");
		scanf("%s", insert.pi7, 50);
		printf("8주차 계획 :  ");
		scanf("%s", insert.pi8, 50);
		printf("9주차 계획 :  ");
		scanf("%s", insert.pi9, 50);
		printf("10주차 계획 : ");
		scanf("%s", insert.pi10, 50);
		printf("11주차 계획 : ");
		scanf("%s", insert.pi11, 50);
		printf("12주차 계획 : ");
		scanf("%s", insert.pi12, 50);
		printf("13주차 계획 : ");
		scanf("%s", insert.pi13, 50);
		printf("14주차 계획 : ");
		scanf("%s", insert.pi14, 50);
		printf("15주차 계획 : ");
		scanf("%s", insert.pi15, 50);
		printf("16주차 계획 : ");
		scanf("%s", insert.pi16, 50);
		fprintf(fpin1, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", insert.pi1, insert.pi2, insert.pi3, insert.pi4, insert.pi5, insert.pi6, insert.pi7, insert.pi8, insert.pi9, insert.pi10, insert.pi11, insert.pi12, insert.pi13, insert.pi14, insert.pi15, insert.pi16);
		//입력받은 문자열 파일에 저장
		fclose(fpin1);
		fclose(fpin2);
		return 0;
	}
	else if (a == 2)
	{
		printf("1주차 계획 :  ");
		scanf("%s", insert.pi1, 50);
		printf("2주차 계획 :  ");
		scanf("%s", insert.pi2, 50);
		printf("3주차 계획 :  ");
		scanf("%s", insert.pi3, 50);
		printf("4주차 계획 :  ");
		scanf("%s", insert.pi4, 50);
		printf("5주차 계획 :  ");
		scanf("%s", insert.pi5, 50);
		printf("6주차 계획 :  ");
		scanf("%s", insert.pi6, 50);
		printf("7주차 계획 :  ");
		scanf("%s", insert.pi7, 50);
		printf("8주차 계획 :  ");
		scanf("%s", insert.pi8, 50);
		printf("9주차 계획 :  ");
		scanf("%s", insert.pi9, 50);
		printf("10주차 계획 : ");
		scanf("%s", insert.pi10, 50);
		printf("11주차 계획 : ");
		scanf("%s", insert.pi11, 50);
		printf("12주차 계획 : ");
		scanf("%s", insert.pi12, 50);
		printf("13주차 계획 : ");
		scanf("%s", insert.pi13, 50);
		printf("14주차 계획 : ");
		scanf("%s", insert.pi14, 50);
		printf("15주차 계획 : ");
		scanf("%s", insert.pi15, 50);
		printf("16주차 계획 : ");
		scanf("%s", insert.pi16, 50);
		fprintf(fpin1, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", insert.pi1, insert.pi2, insert.pi3, insert.pi4, insert.pi5, insert.pi6, insert.pi7, insert.pi8, insert.pi9, insert.pi10, insert.pi11, insert.pi12, insert.pi13, insert.pi14, insert.pi15, insert.pi16);
		//입력받은 문자열 파일에 저장
		fclose(fpin1);
		fclose(fpin2);
		return 0;
	}
	else if (a == 3)//3누르면 종료
		return 0;
	printf("잘못 입력하셨습니다.\n");
	fclose(fpin1);
	fclose(fpin2);
	return 0;
}//===================================================-sungjae
int achievementcheck() {
	FILE *fpout1 = fopen("plan1.txt", "r");//1학기 읽어오는 파일포인터
	if ((fpout1 = fopen("plan1.txt", "r")) == NULL)
	{
		printf("오류!!\n");
		return 0;
	}
	FILE *fpout2 = fopen("plan2.txt", "r");//2학기 읽어오는 파일포인터
	if ((fpout2 = fopen("plan2.txt", "r")) == NULL)
	{
		printf("오류!!\n");
		return 0;
	}
	FILE *chrate1 = fopen("rate1.txt", "w");//1학기 달성체크
	FILE *chrate2 = fopen("rate2.txt", "w");//2학기 달성체크
	int f = 0;
	char c1[10], c2[10], c3[10], c4[10], c5[10], c6[10], c7[10], c8[10], c9[10], c10[10], c11[10], c12[10], c13[10], c14[10], c15[10], c16[10];
	PLAN out;
	printf("1. 1학기 달성체크\n");
	printf("2. 2학기 달성체크\n");
	printf("3. 종료\n");
	scanf("%d", &f);
	system("cls");
	if (f == 3)
		exit(1);
	switch (f) {
	case 1:
		fscanf(fpout1, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", out.pi1, out.pi2, out.pi3, out.pi4, out.pi5, out.pi6, out.pi7, out.pi8, out.pi9, out.pi10, out.pi11, out.pi12, out.pi13, out.pi14, out.pi15, out.pi16);
		printf("1주차 : %s-->달성했으면 y / 아니면 n\n", out.pi1);
		scanf(" %s", c1);
		printf("2주차 : %s-->달성했으면 y / 아니면 n\n", out.pi2);
		scanf(" %s", c2);
		printf("3주차 : %s-->달성했으면 y / 아니면 n\n", out.pi3);
		scanf(" %s", c3);
		printf("4주차 : %s-->달성했으면 y / 아니면 n\n", out.pi4);
		scanf(" %s", c4);
		printf("5주차 : %s-->달성했으면 y / 아니면 n\n", out.pi5);
		scanf(" %s", c5);
		printf("6주차 : %s-->달성했으면 y / 아니면 n\n", out.pi6);
		scanf(" %s", c6);
		printf("7주차 : %s-->달성했으면 y / 아니면 n\n", out.pi7);
		scanf(" %s", c7);
		printf("8주차 : %s-->달성했으면 y / 아니면 n\n", out.pi8);
		scanf(" %s", c8);
		printf("9주차 : %s-->달성했으면 y / 아니면 n\n", out.pi9);
		scanf(" %s", c9);
		printf("10주차 : %s-->달성했으면 y / 아니면 n\n", out.pi10);
		scanf(" %s", c10);
		printf("11주차 : %s-->달성했으면 y / 아니면 n\n", out.pi11);
		scanf(" %s", c11);
		printf("12주차 : %s-->달성했으면 y / 아니면 n\n", out.pi12);
		scanf(" %s", c12);
		printf("13주차 : %s-->달성했으면 y / 아니면 n\n", out.pi13);
		scanf(" %s", c13);
		printf("14주차 : %s-->달성했으면 y / 아니면 n\n", out.pi14);
		scanf(" %s", c14);
		printf("15주차 : %s-->달성했으면 y / 아니면 n\n", out.pi15);
		scanf(" %s", c15);
		printf("16주차 : %s-->달성했으면 y / 아니면 n\n", out.pi16);
		scanf(" %s", c16);
		fprintf(chrate1, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15, c16);
		//사용자가 입력한 달성체크 저장
		break;
	case 2:
		fscanf(fpout2, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", out.pi1, out.pi2, out.pi3, out.pi4, out.pi5, out.pi6, out.pi7, out.pi8, out.pi9, out.pi10, out.pi11, out.pi12, out.pi13, out.pi14, out.pi15, out.pi16);
		printf("1주차 : %s-->달성했으면 y / 아니면 n\n", out.pi1);
		scanf(" %s", c1);
		printf("2주차 : %s-->달성했으면 y / 아니면 n\n", out.pi2);
		scanf(" %s", c2);
		printf("3주차 : %s-->달성했으면 y / 아니면 n\n", out.pi3);
		scanf(" %s", c3);
		printf("4주차 : %s-->달성했으면 y / 아니면 n\n", out.pi4);
		scanf(" %s", c4);
		printf("5주차 : %s-->달성했으면 y / 아니면 n\n", out.pi5);
		scanf(" %s", c5);
		printf("6주차 : %s-->달성했으면 y / 아니면 n\n", out.pi6);
		scanf(" %s", c6);
		printf("7주차 : %s-->달성했으면 y / 아니면 n\n", out.pi7);
		scanf(" %s", c7);
		printf("8주차 : %s-->달성했으면 y / 아니면 n\n", out.pi8);
		scanf(" %s", c8);
		printf("9주차 : %s-->달성했으면 y / 아니면 n\n", out.pi9);
		scanf(" %s", c9);
		printf("10주차 : %s-->달성했으면 y / 아니면 n\n", out.pi10);
		scanf(" %s", c10);
		printf("11주차 : %s-->달성했으면 y / 아니면 n\n", out.pi11);
		scanf(" %s", c11);
		printf("12주차 : %s-->달성했으면 y / 아니면 n\n", out.pi12);
		scanf(" %s", c12);
		printf("13주차 : %s-->달성했으면 y / 아니면 n\n", out.pi13);
		scanf(" %s", c13);
		printf("14주차 : %s-->달성했으면 y / 아니면 n\n", out.pi14);
		scanf(" %s", c14);
		printf("15주차 : %s-->달성했으면 y / 아니면 n\n", out.pi15);
		scanf(" %s", c15);
		printf("16주차 : %s-->달성했으면 y / 아니면 n\n", out.pi16);
		scanf(" %s", c16);
		fprintf(chrate2, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15, c16);
		//사용자가 입력한 달성체크 저장
		break;
	default:
		break;
	}
	return 0;
}//====================================================-sungjae
int achievementrate() {
	FILE *rate1 = fopen("rate1.txt", "r");
	if ((fopen("rate1.txt", "r")) == NULL)
	{
		printf("File open fail!!\n");
		return 0;
	}
	FILE *rate2 = fopen("rate2.txt", "r");
	if ((fopen("rate2.txt", "r")) == NULL)
	{
		printf("File open fail!!\n");
		return 0;
	}
	PLAN ch;//달성체크파일에서 받아오기위해 사용한 구조체
	int ratesum = 0;//달성 여부 확인용 정수형 변수
	int ac;//사용자 메뉴선택변수
	printf("1. 1학기 달성률\n");
	printf("2. 2학기 달성률\n");
	printf("3. 종료\n");
	scanf("%d", &ac);
	system("cls");
	if (ac == 3)
		return 0;
	switch (ac) {
	case 1:
		fscanf(rate1, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", ch.c1, ch.c2, ch.c3, ch.c4, ch.c5, ch.c6, ch.c7, ch.c8, ch.c9, ch.c10, ch.c11, ch.c12, ch.c13, ch.c14, ch.c15, ch.c16);
		printf("1주차 달성여부 : %s\n", ch.c1);
		if (strcmp(ch.c1, "y") == 0)//대답이 y라면
			ratesum++;
		printf("2주차 달성여부 : %s\n", ch.c2);
		if (strcmp(ch.c2, "y") == 0)//대답이 y라면
			ratesum++;
		printf("3주차 달성여부 : %s\n", ch.c3);
		if (strcmp(ch.c3, "y") == 0)//대답이 y라면
			ratesum++;
		printf("4주차 달성여부 : %s\n", ch.c4);
		if (strcmp(ch.c4, "y") == 0)//대답이 y라면
			ratesum++;
		printf("5주차 달성여부 : %s\n", ch.c5);
		if (strcmp(ch.c5, "y") == 0)//대답이 y라면
			ratesum++;
		printf("6주차 달성여부 : %s\n", ch.c6);
		if (strcmp(ch.c6, "y") == 0)//대답이 y라면
			ratesum++;
		printf("7주차 달성여부 : %s\n", ch.c7);
		if (strcmp(ch.c7, "y") == 0)//대답이 y라면
			ratesum++;
		printf("8주차 달성여부 : %s\n", ch.c8);
		if (strcmp(ch.c8, "y") == 0)//대답이 y라면
			ratesum++;
		printf("9주차 달성여부 : %s\n", ch.c9);
		if (strcmp(ch.c9, "y") == 0)//대답이 y라면
			ratesum++;
		printf("10주차 달성여부 : %s\n", ch.c10);
		if (strcmp(ch.c10, "y") == 0)//대답이 y라면
			ratesum++;
		printf("11주차 달성여부 : %s\n", ch.c11);
		if (strcmp(ch.c11, "y") == 0)//대답이 y라면
			ratesum++;
		printf("12주차 달성여부 : %s\n", ch.c12);
		if (strcmp(ch.c12, "y") == 0)//대답이 y라면
			ratesum++;
		printf("13주차 달성여부 : %s\n", ch.c13);
		if (strcmp(ch.c13, "y") == 0)//대답이 y라면
			ratesum++;
		printf("14주차 달성여부 : %s\n", ch.c14);
		if (strcmp(ch.c14, "y") == 0)//대답이 y라면
			ratesum++;
		printf("15주차 달성여부 : %s\n", ch.c15);
		if (strcmp(ch.c15, "y") == 0)//대답이 y라면
			ratesum++;
		printf("16주차 달성여부 : %s\n", ch.c16);
		if (strcmp(ch.c16, "y") == 0)//대답이 y라면
			ratesum++;
		printf("1학기 달성률 %.2lf%%\n", ((float)ratesum / 16) * 100);
		fclose(rate1);
		break;
	case 2:
		fscanf(rate2, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", ch.c1, ch.c2, ch.c3, ch.c4, ch.c5, ch.c6, ch.c7, ch.c8, ch.c9, ch.c10, ch.c11, ch.c12, ch.c13, ch.c14, ch.c15, ch.c16);
		printf("1주차 달성여부 : %s\n", ch.c1);
		if (strcmp(ch.c1, "y") == 0)//대답이 y라면
			ratesum++;
		printf("2주차 달성여부 : %s\n", ch.c2);
		if (strcmp(ch.c2, "y") == 0)//대답이 y라면
			ratesum++;
		printf("3주차 달성여부 : %s\n", ch.c3);
		if (strcmp(ch.c3, "y") == 0)//대답이 y라면
			ratesum++;
		printf("4주차 달성여부 : %s\n", ch.c4);
		if (strcmp(ch.c4, "y") == 0)//대답이 y라면
			ratesum++;
		printf("5주차 달성여부 : %s\n", ch.c5);
		if (strcmp(ch.c5, "y") == 0)//대답이 y라면
			ratesum++;
		printf("6주차 달성여부 : %s\n", ch.c6);
		if (strcmp(ch.c6, "y") == 0)//대답이 y라면
			ratesum++;
		printf("7주차 달성여부 : %s\n", ch.c7);
		if (strcmp(ch.c7, "y") == 0)//대답이 y라면
			ratesum++;
		printf("8주차 달성여부 : %s\n", ch.c8);
		if (strcmp(ch.c8, "y") == 0)//대답이 y라면
			ratesum++;
		printf("9주차 달성여부 : %s\n", ch.c9);
		if (strcmp(ch.c9, "y") == 0)//대답이 y라면
			ratesum++;
		printf("10주차 달성여부 : %s\n", ch.c10);
		if (strcmp(ch.c10, "y") == 0)//대답이 y라면
			ratesum++;
		printf("11주차 달성여부 : %s\n", ch.c11);
		if (strcmp(ch.c11, "y") == 0)//대답이 y라면
			ratesum++;
		printf("12주차 달성여부 : %s\n", ch.c12);
		if (strcmp(ch.c12, "y") == 0)//대답이 y라면
			ratesum++;
		printf("13주차 달성여부 : %s\n", ch.c13);
		if (strcmp(ch.c13, "y") == 0)//대답이 y라면
			ratesum++;
		printf("14주차 달성여부 : %s\n", ch.c14);
		if (strcmp(ch.c14, "y") == 0)//대답이 y라면
			ratesum++;
		printf("15주차 달성여부 : %s\n", ch.c15);
		if (strcmp(ch.c15, "y") == 0)//대답이 y라면
			ratesum++;
		printf("16주차 달성여부 : %s\n", ch.c16);
		if (strcmp(ch.c16, "y") == 0)//대답이 y라면
			ratesum++;
		printf("2학기 달성률 %.2lf%% \n", ((float)ratesum / 16) * 100);
		fclose(rate2);
		break;
	default:
		break;
	}
	printf("10초 뒤에 메뉴화면으로 넘어갑니다\n");
	Sleep(10000);
	return 0;
}//====================================-sungjae
int timetable() {
	int x = 0;
	printf("==========================================\n");
	printf("===============time table=================\n");
	printf("==========================================\n");
	printf("1.시간표 입력\n");
	printf("2.시간표 보기\n");
	scanf("%d", &x);
	switch (x)
	{
	case 1:
		break;
	case 2:
		break;
	default:
		return 0;
	}
	return 0;
}//====================================-sungjae
