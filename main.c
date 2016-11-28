#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
//====================
typedef struct plan {
	char pi1[50], pi2[50], pi3[50], pi4[50], pi5[50], pi6[50], pi7[50], pi8[50], pi9[50], pi10[50], pi11[50], pi12[50], pi13[50], pi14[50], pi15[50], pi16[50];
	//pi1~16배열은 1주차부터 16주차까지의 계획저장 변수
	int ac1, ac2, ac3, ac4, ac5, ac6, ac7, ac8, ac9, ac10, ac11, ac12, ac13, ac14, ac15, ac16;
}PLAN;//PLAN구조체는 계획 문자열 저장하기 위해서 사용

//==============================================-changun
int Calculator_Menu(); //계산기 메인 메뉴
int Matrix_Menu(); //행렬 계산 메뉴
int ACalulator_Menu(); //사칙연산 메뉴
void Matrix_add(); //행렬 덧셈/
//==============================================-changun
//==============================================-sungjae
void learningplanner();//학습계획표 메뉴 함수
int planinsert();//계획 입력 함수
int achievementcheck();//달성체크함수
//==============================================-sungjae
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
							switch (CM_M)
							{
								case 1:
								Matrix_add();
								default:
								break;
							}// 행렬계산기에 대한 switch
							break;
							case 2:
							AC_M = ACalulator_Menu(); //일반 계산기 메뉴
							break;
							case 3:
							End_C=10 //End_c에 10을 넣어줘서 반복문 탈출
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
			break;
		case 5:
			//타이머
			break;
		case 6:
			//알람
			break;
		case 7:
			//스톱워치
			break;
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

int ACalulator_Menu()
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


 void Matrix_add()  //행렬 덧셈
{
	int exone[MAX][MAX];
	int extwo[MAX][MAX];
	int exsum[MAX][MAX];
	int matrix_mrow;
	int matrix_mcolumn;
	int i = 0,j=0;

	printf("===========================\n");
	printf("        Matrix Add\n");
	printf("===========================\n");
	printf("더해줄 행렬은 같은 크기여야 합니다.\n");
	printf("덧셈 할 행렬의 행의 크기를 입력해주세요:");
	scanf_s("%d", &matrix_mrow);
	printf("덧셈 할 행렬의 열의 크기를 입력해주세요:");
	scanf_s("%d", &matrix_mcolumn);

	printf("첫번째 행렬 \n");
	for (i = 0; i < matrix_mcolumn; i++)
		for (j = 0; j < matrix_mrow; j++)
		{
			printf("exone[%d][%d]", i, j);
			scanf("%d", &exone[i][j]);
		}//첫번째 행렬 입력

	printf("두번째 행렬 \n");
	for (i = 0; i < matrix_mcolumn; i++)
		for (j = 0; j < matrix_mrow; j++)
		{
			printf("extwo[%d][%d]", i, j);
			scanf("%d", &extwo[i][j]);
		}//두번째 행렬 입력

	printf("첫번째 행렬 \n");
	for (i = 0; i < matrix_mcolumn; i++)
	{
		printf("\n");
		for (j = 0; j < matrix_mrow; j++)
		{
			printf("%d\t", exone[i][j]);
		} //행을 출력
	}//열을 출력

	printf("두번째 행렬 \n");
	for (i = 0; i < matrix_mcolumn; i++)
	{
		printf("\n");
		for (j = 0; j < matrix_mrow; j++)
		{
			printf("%d\t", extwo[i][j]);
		} //행을 출력
	}//열을 출력


	for (i = 0; i < matrix_mcolumn; i++)
		for (j = 0; j < matrix_mrow; j++)
		{
			exsum[i][j] = exone[i][j] + extwo[i][j];
		}//두번째 행렬 입력
	printf("덧셈한 행렬 \n");
	for (i = 0; i < matrix_mcolumn; i++)
	{
		printf("\n");
		for (j = 0; j < matrix_mrow; j++)
		{
			printf("%d\t", exsum[i][j]);
		} //행을 출력
	}//열을 출력

}// void Matrix_add() 함수 종료 중괄호


//================================================-changun
void learningplanner()
{
	int b;//b는 사용자가 메뉴선택하는 변수
    while (1) {
	printf("==================================\n");
	printf("         Learning  Planner        \n");
	printf("==================================\n");
	printf("1. 계획 입력\n");
	printf("2. 계획 달성 체크\n");
	printf("3. 달성률 보기\n");
	printf("4. 시간표\n");
	printf("5. 종료...\n");
	scanf("%d",&b);
		if (b == 5)
			exit(1);
		switch (b)
		{
		case 1:
			planinsert();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			break;
		}
	}
}//====================================-sungjae
int planinsert()
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
	PLAN insert = { 0 };
	printf("1. 1학기 계획입력\n");
	printf("2. 2학기 계획입력\n");
	printf("3. 종료\n");
	scanf("%d", &a);
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

		fclose(fpin1);
		fclose(fpin2);
		return 0;
	}
	else if (a == 3)
		return 0;
	printf("잘못 입력하셨습니다.\n");
	fclose(fpin1);
	fclose(fpin2);
	return 0;
}//====================================-sungjae
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
	FILE *chrate1=fopen("rate1.txt","w");//1학기 달성체크
	FILE *chrate2 = fopen("rate2.txt", "w");//2학기 달성체크
	int f=0;
	char c1[2], c2[2], c3[2], c4[2], c5[2], c6[2], c7[2], c8[2], c9[2], c10[2], c11[2], c12[2], c13[2], c14[2], c15[2], c16[2];
	PLAN out;
	printf("1. 1학기 달성체크\n");
	printf("2. 2학기 달성체크\n");
	printf("3. 종료\n");
	scanf("%d", &f);
	if (f == 3)
		exit(1);
	switch (f) {
	case 1:
		fscanf(fpout1, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", out.pi1, out.pi2, out.pi3, out.pi4, out.pi5, out.pi6, out.pi7, out.pi8, out.pi9, out.pi10, out.pi11, out.pi12, out.pi13, out.pi14, out.pi15, out.pi16);
		printf("1주차 : %s-->달성했으면 y / 아니면 n\n", out.pi1);
		scanf(" %s", c1);
		out.ac1 = check(c1);
		printf("2주차 : %s-->달성했으면 y / 아니면 n\n", out.pi2);
		scanf(" %s", c2);
		out.ac2 = check(c2);
		printf("3주차 : %s-->달성했으면 y / 아니면 n\n", out.pi3);
		scanf(" %s", c3);
		out.ac3 = check(c3);
		printf("4주차 : %s-->달성했으면 y / 아니면 n\n", out.pi4);
		scanf(" %s", c4);
		out.ac4 = check(c4);
		printf("5주차 : %s-->달성했으면 y / 아니면 n\n", out.pi5);
		scanf(" %s", c5);
		out.ac5 = check(c5);
		printf("6주차 : %s-->달성했으면 y / 아니면 n\n", out.pi6);
		scanf(" %s", c6);
		out.ac6 = check(c6);
		printf("7주차 : %s-->달성했으면 y / 아니면 n\n", out.pi7);
		scanf(" %s", c7);
		out.ac7 = check(c7);
		printf("8주차 : %s-->달성했으면 y / 아니면 n\n", out.pi8);
		scanf(" %s", c8);
		out.ac8 = check(c8);
		printf("9주차 : %s-->달성했으면 y / 아니면 n\n", out.pi9);
		scanf(" %s", c9);
		out.ac9 = check(c9);
		printf("10주차 : %s-->달성했으면 y / 아니면 n\n", out.pi10);
		scanf(" %s", c10);
		out.ac10 = check(c10);
		printf("11주차 : %s-->달성했으면 y / 아니면 n\n", out.pi11);
		scanf(" %s", c11);
		out.ac11 = check(c11);
		printf("12주차 : %s-->달성했으면 y / 아니면 n\n", out.pi12);
		scanf(" %s", c12);
		out.ac12 = check(c12);
		printf("13주차 : %s-->달성했으면 y / 아니면 n\n", out.pi13);
		scanf(" %s", c13);
		out.ac13 = check(c13);
		printf("14주차 : %s-->달성했으면 y / 아니면 n\n", out.pi14);
		scanf(" %s", c14);
		out.ac14 = check(c14);
		printf("15주차 : %s-->달성했으면 y / 아니면 n\n", out.pi15);
		scanf(" %s", c15);
		out.ac15 = check(c15);
		printf("16주차 : %s-->달성했으면 y / 아니면 n\n", out.pi16);
		scanf(" %s", c16);
		out.ac16 = check(c16);
		fprintf(chrate1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",out.ac1, out.ac2, out.ac3, out.ac4, out.ac5, out.ac6, out.ac7, out.ac8, out.ac9, out.ac10, out.ac11, out.ac12, out.ac13, out.ac14, out.ac15, out.ac16);
		break;
	case 2:
		fscanf(fpout1, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", out.pi1, out.pi2, out.pi3, out.pi4, out.pi5, out.pi6, out.pi7, out.pi8, out.pi9, out.pi10, out.pi11, out.pi12, out.pi13, out.pi14, out.pi15, out.pi16);
		printf("1주차 : %s-->달성했으면 y / 아니면 n\n", out.pi1);
		scanf(" %s", c1);
		out.ac1 = check(c1);
		printf("2주차 : %s-->달성했으면 y / 아니면 n\n", out.pi2);
		scanf(" %s", c2);
		out.ac2 = check(c2);
		printf("3주차 : %s-->달성했으면 y / 아니면 n\n", out.pi3);
		scanf(" %s", c3);
		out.ac3 = check(c3);
		printf("4주차 : %s-->달성했으면 y / 아니면 n\n", out.pi4);
		scanf(" %s", c4);
		out.ac4 = check(c4);
		printf("5주차 : %s-->달성했으면 y / 아니면 n\n", out.pi5);
		scanf(" %s", c5);
		out.ac5 = check(c5);
		printf("6주차 : %s-->달성했으면 y / 아니면 n\n", out.pi6);
		scanf(" %s", c6);
		out.ac6 = check(c6);
		printf("7주차 : %s-->달성했으면 y / 아니면 n\n", out.pi7);
		scanf(" %s", c7);
		out.ac7 = check(c7);
		printf("8주차 : %s-->달성했으면 y / 아니면 n\n", out.pi8);
		scanf(" %s", c8);
		out.ac8 = check(c8);
		printf("9주차 : %s-->달성했으면 y / 아니면 n\n", out.pi9);
		scanf(" %s", c9);
		out.ac9 = check(c9);
		printf("10주차 : %s-->달성했으면 y / 아니면 n\n", out.pi10);
		scanf(" %s", c10);
		out.ac10 = check(c10);
		printf("11주차 : %s-->달성했으면 y / 아니면 n\n", out.pi11);
		scanf(" %s", c11);
		out.ac11 = check(c11);
		printf("12주차 : %s-->달성했으면 y / 아니면 n\n", out.pi12);
		scanf(" %s", c12);
		out.ac12 = check(c12);
		printf("13주차 : %s-->달성했으면 y / 아니면 n\n", out.pi13);
		scanf(" %s", c13);
		out.ac13 = check(c13);
		printf("14주차 : %s-->달성했으면 y / 아니면 n\n", out.pi14);
		scanf(" %s", c14);
		out.ac14 = check(c14);
		printf("15주차 : %s-->달성했으면 y / 아니면 n\n", out.pi15);
		scanf(" %s", c15);
		out.ac15 = check(c15);
		printf("16주차 : %s-->달성했으면 y / 아니면 n\n", out.pi16);
		scanf(" %s", c16);
		out.ac16 = check(c16);
		fprintf(chrate1, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", out.ac1, out.ac2, out.ac3, out.ac4, out.ac5, out.ac6, out.ac7, out.ac8, out.ac9, out.ac10, out.ac11, out.ac12, out.ac13, out.ac14, out.ac15, out.ac16);
		break;
	default:
		break;
	}
	return 0;
}//=============================================-sungjae
