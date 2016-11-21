#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
//====================

//함수 넣는존
//==============================================-changun
int Calculator_Menu(); //계산기 메인 메뉴
int Matrix_Menu(); //행렬 계산 메뉴
int ACalculator_Menu(); //사칙연산 메뉴
int Stopwatch();//스톱워치 메뉴
//==============================================-changun


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
