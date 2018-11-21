#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bingofunction.h"

#define N 5			//빙고 테이블의 크기 기호 상수 N 
#define M 3			//이기는 조건 (빙고 개수) M 

 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	
void initiate_bingo(int n, int table1[n][n], int table2[n][n]);	//빙고 테이블을 처음에 만들어줌 
void print_bingo(int n, int table1[n][n]);	//빙고 테이블 현재 상황을 화면에 출력
void get_number_byMe(int tri, int n, int choice[n*n]);			
											//내가 빙고 번호 입력 선택
void get_number_byCom(int tri, int n, int choice[n*n]);
											//컴퓨터가 임의로 빙고 번호 선택
void process_bingo(int n, int tri, int table1[n][n], int table2[n][n], int choice[tri]);
											//선택된 숫자를 입력받아서 빙고 테이블 칸을 채움
void count_bingo(int n, int table[n][n], int *count);		//빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산하여 반환 
	
int main(int argc, char *argv[]) {

	int user_table[N][N];	//사용자의 N*N 크기의 빙고 테이블
	int com_table[N][N];	//컴퓨터의 N*N 크기의 빙고 테이블 
	
	int choice[N*N];		//크기가 N*N인 choice 배열 (사용자 choice와 컴퓨터 choice 모두) 
	int tri;				//choice 배열에 tri 번째 배열 
	int turn;				//몇번째 turn 에서 승부가 났는지 출력하기 위함 
	
	int usercount;			//사용자의 빙고 개수 
	int comcount;			//컴퓨터의 빙고 개수 
	
	srand((unsigned)time(NULL));					//실행마다 달라지는 빙고 값을 위함 
	
	printf("\t☆빙고게임☆\n\n");
	printf("< 게임방법 >\n");
	printf("사용자와 컴퓨터가 돌아가며 %d칸 짜리 빙고판에 숫자를 채운다.\n", N*N);
	printf("채워진 숫자는 -1로 바뀐다.\n");
	printf("count가 먼저 %d가  되는 사람이 승리!\n", M);
	printf("단, 사용자와 컴퓨터 동시에 빙고 count가 %d줄 이상이 되면 무승부로 한다.\n\n", M);
	 
	initiate_bingo(N, user_table, com_table);		//빙고판 설정 

	print_bingo(N, user_table); 			//설정된 빙고판을 보여줌 
	
	
	for(tri=0; tri<N*N; tri++){				//모든 칸이 채워지기 전까지 반복 
		
		//<turn을 계산하는 코드> 
		if(tri==0){									//tri가 0이면 
			turn = 1;								//turn 은 1 
		} 
			
		else if(tri%2==0){							//tri가 짝수면 = 사용자가 선택했을 때 
			turn = (tri/2)+1;						//turn은 tri를 2로 나눈 값 
		}
			
		else if(tri%2!=0){							//tri 가 홀수면 = 컴퓨터가 선택했을 때 
			turn = ((tri-1)/2)+1;					//turn은 tri-1 을 2로 나눈 값 
		}
		
		
		//<나머지 코드 실행> 
		printf("\n< %d 번째 turn >\n", turn);		//지금이 몇번째 turn인지 출력 ***나중에 뺌 
		
		if(tri==0||tri%2==0) 						//tri=0이거나 짝수면
			get_number_byMe(tri, N, choice); 		//사용자가 숫자 선택 
				
		else										//그렇지 않으면, 즉, tri가 홀수면 
			get_number_byCom(tri, N, choice); 		//컴퓨터가 숫자 선택 
				
			
		process_bingo(N, tri, user_table, com_table, choice);//숫자 채움 
		print_bingo(N, user_table);		//숫자 채운 빙고판을 다시 출력 

		count_bingo(N, user_table, &usercount);		//사용자의 빙고 몇갠지 셈 
			printf("user count = %d\n", usercount);	//사용자의 빙고 개수 출력 
			
		count_bingo(N, com_table, &comcount);		//컴퓨터의 빙고 몇갠지 셈 
			printf("com count = %d\n", comcount);	//컴퓨터의 빙고 개수 출력
				
				
		//<반복을 끝내는 조건을 나타내는 코드>	
		if((usercount>=M)||(comcount>=M))
			break;						//usercount가 M보다 크거나 같으면 혹은, comcount가 M보다 크거나 같으면 반복중지 

	}
	
	//<게임 결과를 출력하는 코드> 
	if(usercount>=M && comcount>=M){				//usercount와 comcount가 둘다 M보다 크거나 같으면 
		printf("\n무승부! turn : %d\n", turn);		//무승부와 turn을 출력한다.
													//(한칸을 채울때 빙고 개수가 +2 등이 될 수 있기 때문) 
	}
	
	else												//usercount와 comcount가 다른 경우(일반적인 경우) 
	{
		if(usercount>=M){								//usercount가 M보다 크거나 같으면 
			printf("\n사용자 승리! turn : %d\n", turn);	//사용자 승리와 turn 출력 
		}
	
		if(comcount>=M){								//comcount가 M보다 크거나 같으면 
			printf("\n컴퓨터 승리! turn : %d\n", turn);	//컴퓨터 승리와 turn 출력 
		}
	}
	
	
	return 0;
}

