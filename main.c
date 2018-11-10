#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	
void initiate_bingo(int n, int table1[n][n], int table2[n][n]);	//빙고 테이블을 처음에 만들어줌 
void print_bingo(int n, int table1[n][n], int table2[n][n]);	//빙고 테이블 현재 상황을 화면에 출력
void get_number_byMe(int choice);			//내가 빙고 번호 입력 선택
void get_number_byCom(int choice);			//컴퓨터가 임의로 빙고 번호 선택
void process_bingo();						//선택된 숫자를 입력받아서 빙고 테이블 칸을 채움
void count_bingo();							//빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산하여 반환 
	
int main(int argc, char *argv[]) {

	int N = 4;		//빙고테이블의 크기 조절
	int M = 3;		//빙고에서 이기는 조건 
	int user_table[N][N];	//사용자의 N*N 크기의 빙고 테이블
	int com_table[N][N];	//컴퓨터의 N*N 크기의 빙고 테이블 

	
	initiate_bingo(N, user_table, com_table);
	
	print_bingo(N, user_table, com_table); 
	
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

void initiate_bingo(int n, int table1[n][n], int table2[n][n])	//***좀 더 간단한거 생각 
{
	int i, j;
	int k, l;
	int max;
	max = n*n;
	
	srand((unsigned)time(NULL));
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){	 
			table1[i][j] = rand()%max+1;		//이차원 배열에 1~max까지의 값 할당
			
			for(k=0; k<i; k++){
				for(l=0; l<j; l++){
					if(table1[i][j]==table1[k][l])
						i--;
						j--;			// 이전 값과 중복되는 값이면 table[i][j]의 값 다시 할당 
						continue;		// continue 를 이용하여 다시 반복한다. 
				}
			} 
		}
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){	 
			table2[i][j] = rand()%max+1;		//이차원 배열에 1~max까지의 값 할당
			
			for(k=0; k<i; k++){
				for(l=0; l<j; l++){
					if(table2[i][j]==table2[k][l])
						i--;
						j--;			// 이전 값과 중복되는 값이면 table[i][j]의 값 다시 할당 
						continue;		// continue 를 이용하여 다시 반복한다. 
				}
			} 
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


