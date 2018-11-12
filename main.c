#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tri;		//get number by ___ 함수들에 공통으로 사용되어야 하므로 전역변수를 쓴다.
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	
void initiate_bingo(int n, int table1[n][n], int table2[n][n]);	//빙고 테이블을 처음에 만들어줌 
void print_bingo(int n, int table1[n][n], int table2[n][n]);	//빙고 테이블 현재 상황을 화면에 출력
void get_number_byMe(int tri, int n, int choice1[n*n], int choice2[n*n]);			
											//내가 빙고 번호 입력 선택
void get_number_byCom(int tri, int n, int choice1[n*n], int choice2[n*n]);
											//컴퓨터가 임의로 빙고 번호 선택
void process_bingo();						//선택된 숫자를 입력받아서 빙고 테이블 칸을 채움
void count_bingo();							//빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산하여 반환 
	
int main(int argc, char *argv[]) {

	int N = 4;		//빙고테이블의 크기 조절
	int M = 3;		//빙고에서 이기는 조건 
	int user_table[N][N];	//사용자의 N*N 크기의 빙고 테이블
	int com_table[N][N];	//컴퓨터의 N*N 크기의 빙고 테이블 
	int userchoice[N*N];	//사용자가 선택한 숫자를 저장하는 배열 
	int comchoice[N*N]; 	//컴퓨터가 선택한 숫자를 저장하는 배열 
	int turn;				//몇번째 turn 에서 승부가 났는지 출력하기 위함 
	
	turn = tri+1;
	 
	initiate_bingo(N, user_table, com_table);
	
	//do{
	
	print_bingo(N, user_table, com_table); 
	
	for(tri=0; tri<N*N; tri++){
	
		get_number_byMe(tri, N, userchoice, comchoice); //***여기서 멈춤 

		get_number_byCom(tri, N, userchoice, comchoice); 
		
	}
	
	//}while(tri>25||빙고 M줄 완성); 
	
	return 0;
}

/* void initiate_bingo(int n, int *table1, int *table2)	//*** *table1? table1[n][n]? table1?
{
	int i, j;					//특정 횟수만큼 반복하기 위한 변수 
	int max;					//난수 발생 범위를 위해 변수로 둠  
	int assigned_value[n*n];	//이미 사용된 값을 변수로 둠  
	
	max = n*n;		//빙고 테이블 칸 수  
	
	srand((unsigned)time(NULL));
	
	//*** pointer 사용? 배열 사용? 
}*/

void initiate_bingo(int n, int table1[n][n], int table2[n][n])	//***좀 더 간단한거 생각 ****
{
	int i, j;
	int max;
	int value1[n*n];		//일차원 배열으로 value1 선언  
	int value2[n*n]; 
	int a, b;
	max = n*n;
	
	srand((unsigned)time(NULL));
	
	value1[0] = rand()%max+1;			//value[0] 은 겹칠 수 없으므로 난수함수의 값으로 바로 할당 
	
	for(a=1; a<max; a++){
	
		value1[a] = rand()%max+1;		//이차원 배열에 1~max까지의 값 할당

		for(b=0; b<a; b++){
			while(value1[a]==value1[b]){	//a 번째 값이 이전의 값과 같으면 
				value1[a] = rand()%max+1;	//재할당  ****또 겹칠 수 있음 
				b = 0;				// 이 문장이 없으면 b는 계속해서 커져서 이전의 값과 겹칠 수 있음  
			}
		}
	}
	
	a = 0;							//a=0으로 초기화 
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			table1[i][j] = value1[a];	//각 테이블 값에 위에서 구한 반복되지 않은 value를 대응시킴 
			a++;						//a의 값을 하나씩 늘리면서 반복 
			
		}
	}

	value2[0] = rand()%max+1;			//value[0] 은 겹칠 수 없으므로 난수함수의 값으로 바로 할당 
	
	for(a=1; a<max; a++){
	
		value2[a] = rand()%max+1;		//이차원 배열에 1~max까지의 값 할당

		for(b=0; b<a; b++){
			while(value2[a]==value2[b]){	//a 번째 값이 이전의 값과 같으면 
				value2[a] = rand()%max+1;	//재할당  ****또 겹칠 수 있음 
				b = 0;				// 이 문장이 없으면 b는 계속해서 커져서 이전의 값과 겹칠 수 있음  
			}
		}
	}
	
	a = 0;							//a=0으로 초기화 
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			table2[i][j] = value2[a];	//각 테이블 값에 위에서 구한 반복되지 않은 value를 대응시킴 
			a++;						//a의 값을 하나씩 늘리면서 반복 
			
		}
	}
	
}


void print_bingo(int n, int table1[n][n], int table2[n][n])
{
	int i, j;							//반복문을 위한 변수 
	
	printf("< 사용자 빙고 테이블 >\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%d\t", table1[i][j]);	//빙고 테이블을 출력하는 코드 
		}	printf("\n");					//행을 바꾸어 출력하는 코드 
	}
	printf("\n");
	
	printf("< 컴퓨터 빙고 테이블 >\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%d\t", table2[i][j]);	//빙고 테이블을 출력하는 코드 
		}	printf("\n");					//행을 바꾸어 출력하는 코드 
	}
	printf("\n");
	
}

void get_number_byMe(int tri, int n, int choice1[n*n], int choice2[n*n])
{
	int j;
	
	
	printf("숫자를 선택하시오. : ");
	scanf("%d", &choice1[tri]);		//tri번째 사용자 선택 
	
	do{
	
		if(choice1[tri]<1||choice1[tri]>n*n){
			printf("범위 내의 값이 아닙니다. 1과 %d 사이의 값을 입력하시오. : ", n*n);
			scanf("%d", &choice1[tri]);	//잘못된 선택이므로 tri번째 선택을 다시 할당시킴 
		}
	}while(choice1[tri]<1||choice1[tri]>n*n);
	
	do{
			
		for(j=0; j<tri; j++){				//현재 선택보다 이전에의 선택과 비교하기 위함 
			if(choice1[tri]==choice1[j]||	//사용자가 이미 선택한 수 제외하기 위함 
				choice1[tri]==choice2[j]){	//컴퓨터가 이미 선택한 수 제외하기 위함 
												
				printf("이미 선택된 값 입니다. 다시 입력하시오. : ");
				scanf("%d", &choice1[tri]);	//잘못된 선택이므로 tri번째 선택을 다시 할당  
			}
		}
	}while(choice1[tri]==choice1[j]||choice1[tri]==choice2[j]);	//한번 반복 후 여전히 잘못된 선택이
																	//가능하기 때문에 do-while문 사용 
	
}

void get_number_byCom(int tri, int n, int choice1[n*n], int choice2[n*n])
{
	int j;
	int max;
	max = n*n; 

	
		printf("컴퓨터가 선택한 숫자 입니다. : ");
		
		srand((unsigned)time(NULL));
		choice2[tri] = rand()%max+1;		//1부터 n*n+1 사이의 수 랜덤하게 발생 
		
		
		for(j=0; j<tri; j++){				//현재 선택보다 이전에의 선택과 비교하기 위함 
			if(choice2[tri]==choice1[j]||	//사용자가 이미 선택한 수 제외
				choice2[tri]==choice2[j]){	//컴퓨터가 이미 선택한 수 제외 
				
				choice2[tri] = rand()%max+1;	//다시 랜덤하게 선택 
				
			}
		}
		
		printf("%d\n", &choice2[tri]);	//잘못된 선택을 삭제하고 tri번째 선택을 재할당

}
