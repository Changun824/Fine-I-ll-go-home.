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
#define WORDCOUNT 10
#define MAX 100 //Changun 씀 행렬 계산을 위해 사용

//================================================================== - sungho
typedef struct wordlist {
	char name[100]; //단어
	char mean[200]; //뜻
}VOCA;
VOCA a[WORDCOUNT];
//================================================================ - sungho

//함수 넣는존
//===============================================================-main
void main_menu();
int menu_switch();
//===============================================================-main
//==============================================-changun
int Calculator_Menu(); //계산기 메인 메뉴
int Matrix_Menu(); //행렬 계산 메뉴
int ACalulator_Menu(); //사칙연산 메뉴
void Matrix_add(); //행렬 덧셈
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
//================================================-SungHo

//================================================-seokhoon
void calender();
//================================================-seokhoon

//====================
int main()
{
	int main_switch= 0;  //메인문에 스위치 값을 받기 위한 변수 - 사용자 입력 값
	int main_end = 0;   //메인문을 종료시키기 위한 변수
	int End_C = 0, C_M, CM_M, AC_M; //End_C:메인문에서 계산기메뉴를 종료하기 위한 변수 C_M : 계산기 메뉴 CM_M : 행렬계산 메뉴 AC_M : 일반 계산기 메뉴
	int num=0;
	system("mode con: cols=70 lines=30"); //크기
	system("title Learing Support Program");  //제목 변화
	system("color 3F");
	while (1)  //프로그램 반복
	{  //while 중괄호
		system("cls");

		main_menu();
		num=menu_switch();
		switch (num)
		{
		case 5:
			//학습 계획표
			break;
		case 6:
			//학습 통계표
			break;
		case 7: //===============================================계산기 - changun
			system("cls");
			while (1)
			{
				C_M = Calculator_Menu();  //계산기 메뉴를 호출하고 사용자 입력값을 돌려받음
				switch (C_M)
				{
				case 1:
					system("cls");
					CM_M = Matrix_Menu(); //행렬 계산기 메뉴
					switch (CM_M)
					{
					case 1:
						system("cls");
						Matrix_add();
						break;
					case 2:
						system("cls");
						Matrix_mul();
						break;
					default:
						break;
					}// 행렬계산기에 대한 switch
					break;
				case 2:
					system("cls");
					AC_M = ACalulator_Menu(); //일반 계산기 메뉴
					break;
				case 3:
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
			//타이머
			break;
		case 10:
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
			printf("프로그램을 종료합니다.\n");
			exit(1);  //탈출 명령어
		}//if문 - 종료 중괄호
	} //while 중괄호
	return 0;
}
//=============================================================-main
void main_menu()
{

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
	system("cls");
	int user_num;
	printf("=====================================================================\n");
	printf("         Calculator\n");
	printf("=====================================================================\n");
	printf(" 1.행렬 계산기\n");
	printf(" 2.일반 계산기\n");
	printf(" 3.되돌아가기\n");
	scanf_s("%d", &user_num);
	return user_num;
}


int Matrix_Menu()        //행렬 계산기 메뉴
{
	system("cls");
	int user_num;
	printf("=====================================================================\n");
	printf("     Matrix Calculator\n");
	printf("=====================================================================\n");
	printf(" 1.행렬 덧셈\n");
	printf(" 2.행렬 곱셈\n");
	printf(" 3.역행렬의 유무\n");
	printf(" 3.나가기\n");
	scanf_s("%d", &user_num);
	return user_num;
}

int ACalulator_Menu()    //사친연산 계산기 메뉴
{
	system("cls");
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
void Matrix_add()  //행렬 덧셈
{
	int exone[MAX][MAX];
	int extwo[MAX][MAX];
	int exsum[MAX][MAX];
	int matrix_mrow;
	int matrix_mcolumn;
	int i = 0, j = 0;
	system("cls");
	printf("===========================\n");
	printf("        Matrix Add\n");
	printf("===========================\n");
	printf("더해줄 행렬은 같은 크기여야 합니다.\n");
	printf("덧셈 할 행렬의 행의 크기를 입력해주세요:");
	scanf_s("%d", &matrix_mrow);
	printf("덧셈 할 행렬의 열의 크기를 입력해주세요:");
	scanf_s("%d", &matrix_mcolumn);

	printf("첫번째 행렬 \n");
	for (i = 0; i < matrix_mrow; i++)
		for (j = 0; j < matrix_mcolumn; j++)
		{
			printf("exone[%d][%d]", i, j);
			scanf("%d", &exone[i][j]);
		}//첫번째 행렬 입력

	printf("두번째 행렬 \n");
	for (i = 0; i < matrix_mrow; i++)
		for (j = 0; j < matrix_mcolumn; j++)
		{
			printf("extwo[%d][%d]", i, j);
			scanf("%d", &extwo[i][j]);
		}//두번째 행렬 입력
	printf("\n");
	printf("첫번째 행렬 \n");
	for (i = 0; i < matrix_mrow; i++)
	{
		printf("\n");
		for (j = 0; j < matrix_mcolumn; j++)
		{
			printf("%d\t", exone[i][j]);
		} //행을 출력
	}//열을 출력
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
	printf("덧셈한 행렬 \n");
	for (i = 0; i < matrix_mrow; i++)
	{
		for (j = 0; j < matrix_mcolumn; j++)
		{
			printf("%d\t", exsum[i][j]);
		} //행을 출력
		printf("\n");
	}//열을 출력

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
	printf("===============================================\n");
	printf("             MATRIX MULTIPCATION\n");
	printf("===============================================\n");
	printf("곱하기를 할 A[m][n], B[m][n]은 A[n]과 B[m]이 같아야 합니다\n ");
	printf("곱셈 할 행렬의 A행렬의 크기를 입력해주세요 A[m][n]:");
	scanf_s("%d %d", &matrix_arow, &matrix_acolumn);

	printf("곱셈 할 행렬의 B행렬의 크기를 입력해주세요:");
	scanf_s("%d %d", &matrix_brow, &matrix_bcolumn);
	if (matrix_acolumn != matrix_brow)
	{
		printf("곱하기가 불가능한 행렬 입니다.\n");
		return 0;
	}
	printf("\n");
	printf("첫번째 행렬 \n");
	for (i = 0; i < matrix_arow; i++)
		for (j = 0; j < matrix_acolumn; j++)
		{
			printf("exone[%d][%d]", i, j);
			scanf("%d", &exone[i][j]);
		}//첫번째 행렬 입력
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
				return 0;
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
			if (y >= 17)  //화살표("=>")의 y좌표가 메뉴 아래쪽으로는 내려가지 않도록 단어퀴즈와 같은 높이인 17까지만 내려가도록 고정
				y = 17;
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
	system("mode con: cols=70 lines=30");
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
	gotoxy(46, 23);
	printf("※프로그램 종료 [ESC]\n");

}

void Function(int y)
{
	if (y == 5)//단어 검색 화살표("=>")의 y좌표를 가져와서 화살표가 가리키는 메뉴를 실행
	{
		system("cls");
		//;
	}
	if (y == 6)//단어 추가 실행
	{
		system("cls");
		AddWord();
	}
	if (y == 7)//단어 확인 실행
	{
		system("cls");
		;
	}
	if (y == 17)//단어 퀴즈 실행
	{
		system("cls");
		printf("퀴즈");
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
	count = i;
	while (1) {
		int found = 0;//찾은 수
		char target[100];
		char esc[8] = "종료.";
		printf("찾을 단어를 입력해주세요\n");
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
		Sleep(1000);
		system("cls");
	}
	menu_scr();
}

void WordListCheck(void)
{
	int i = 0;
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
	count = i;
	for (i = 0; i<count; i++)
		printf("[ %s : %s ]\n", a[i].name, a[i].mean);//"wt"옆으로
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
//void Quiz(void)
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
