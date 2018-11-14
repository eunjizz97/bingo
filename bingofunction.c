#include "bingofunction.h"


void initiate_bingo(int n, int table1[n][n], int table2[n][n])
{
	int i, j;				//이차원 배열 table들의 행,렬 표현 
	
	int value1[n*n];		//일차원 배열으로 table1 각요소의 값에 해당하는 value1 선언  
	int value2[n*n]; 		//일차원 배열으로 value2 각요소의 값에 해당하는 value2 선언 
	int a, b;				//a번째 배열, b번째 배열을 비교하기 위해 선언 
	
	int max;				//난수 발생 범위(=table 크기) 
	max = n*n;				//난수 발생 범위와 table크기는 n*n 
	
	
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
	
	a = 0;								//a=0으로 초기화 
	
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
	
	a = 0;								//a=0으로 초기화 
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			table2[i][j] = value2[a];	//각 테이블 값에 위에서 구한 반복되지 않은 value를 대응시킴 
			a++;						//a의 값을 하나씩 늘리면서 반복 
			
		}
	}
	
}


void print_bingo(int n, int table1[n][n])
{
	int i, j;								//반복문을 위한 변수 & 배열의 행과 열 
	
	printf("< 사용자 빙고 테이블 >\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%d\t", table1[i][j]);	//빙고 테이블을 출력하는 코드 
		}	printf("\n");					//행을 바꾸어 출력하는 코드 
	}
	printf("\n");
	
/*	printf("< 컴퓨터 빙고 테이블 >\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%d\t", table2[i][j]);	//빙고 테이블을 출력하는 코드 
		}	printf("\n");					//행을 바꾸어 출력하는 코드 
	}
	printf("\n");
*/	
}

void get_number_byMe(int tri, int n, int choice[n*n])
{
	int j;
	
	
	printf("1과 %d 사이의 숫자를 선택하시오. : ", n*n);	//숫자 선택하라고 출력 
	scanf("%d", &choice[tri]);							//tri번째 (사용자가) 선택 
	
		//<범위 밖의 값 제외하는 코드> 
		while(choice[tri]<1||choice[tri]>n*n){
			printf("범위 내의 값이 아닙니다. 1과 %d 사이의 값을 입력하시오. : ", n*n);
			scanf("%d", &choice[tri]);	//잘못된 선택이므로 tri번째 선택을 다시 할당시킴 
		}

	//<이미 선택된 값 제외하는 코드> 
	for(j=0; j<tri; j++){				//현재 선택보다 이전에의 선택과 비교하기 위함 
		
		while(choice[tri]==choice[j]){	//이미 선택한 수 제외하기 위함 
											
			printf("이미 선택된 값 입니다. 다시 입력하시오. : ");
			scanf("%d", &choice[tri]);	//잘못된 선택이므로 tri번째 선택을 다시 할당   
		}
	}	
}

void get_number_byCom(int tri, int n, int choice[n*n])
{
	int j;
	int max;
	max = n*n; 

	
		printf("컴퓨터가 선택한 숫자 입니다. : ");	
		
 
		choice[tri] = rand()%max+1;		//1부터 n*n+1 사이의 수 랜덤하게 발생 
		
			//<이미 선택된 값 제외하는 코드> 
			for(j=0; j<tri; j++){					//현재 선택보다 이전에의 선택과 비교하기 위함 
				if(choice[tri]==choice[j]){			//이미 선택한 수 제외 
				choice[tri] = rand()%max+1;			//다시 랜덤하게 선택 
					j = 0;							//또 겹칠 수 있음을 방지  
				}
			}
		
			//<컴퓨터가 선택한 숫자 출력> 
			printf("%d\n", choice[tri]);			//컴퓨터가 선택한 숫자 출력 
		

}

void process_bingo(int n, int tri, int table1[n][n], int table2[n][n], 
					int choice[tri])
{
	int i, j;
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(table1[i][j]==choice[tri])	//choice값과 table의 값이 같으면, 
				table1[i][j] = -1;			//(choice값을 바꾸면 get number by함수에 오류가 생기므로)
											//table 값을 -1로 바꾸어준다.
				
			if (table2[i][j]==choice[tri]) //choice값과 table의 값이 같으면, 
				table2[i][j] = -1;			//(choice값을 바꾸면 get number by함수에 오류가 생기므로)
											//table 값을 바꾸어준다.
		}
	}
}


void count_bingo(int n, int table[n][n], int *count)
{
	int i, j, k;		//table의 몇번째 배열인지를 다루기 위해 필요한 변수들   
	int sum=0;			//sum 값을 0으로 초기화  
	
	*count=0;			//count 값을 0으로 초기화 
	
	//<가로줄 빙고 개수 세는 코드> 
	for(i=0; i<n; i++){				//행 하나씩 증가시키며 반복 
		for(j=0; j<n; j++){			//행을 고정시킨 후 열을 하나씩 증가시키면서 
			sum += table[i][j];		//i행의 열들의 합을 구함 
			if(sum == -n){			//그 합이 -n 이면 
				(*count)++;			//빙고의 개수를 하나 증가 시킴 
			}
		}
		sum = 0;					//행이 바뀌기 전에, sum 을 다시 0으로 초기화 시킴 
	}
	
	//<세로줄 빙고 개수 세는 코드> 
	for(j=0; j<n; j++){				//열 하나씩 증가시키며 반복 
		for(i=0; i<n; i++){			//행을 고정시킨 후 행을 하나씩 증가시키면서 
			sum += table[i][j];		//j열의 행들의 합을 구함 
			if(sum == -n){			//그 합이 -n 이면 
				(*count)++;			//빙고의 개수를 하나 증가 시킴 
			}
		}
		sum = 0;					//열이 바뀌기 전에, sum을 다시 0으로 초기화 
	}
	
	//<대각선 빙고 개수 세는 코드> 
	for(i=0; i<n; i++){				//i를 하나씩 증가시키면서 
		sum += table[i][i];			//대각선의 총 합을 구함 
		if(sum == -n){				//그 합이 -n 이면 
			(*count)++;				//빙고의 개수를 하나 증가 시킴 
		}
	}
	
	sum = 0;						//sum=0 으로 할당시켜 다음 코드에서 sum=0으로 초기화 되게 함 
	
	//<반대방향 대각선 빙고 개수 세는 코드>
	for(i=0; i<n; i++){				//i를 하나씩 증가시키면서 
		k = n-1-i;					//k값은 줄어들도록 k값 설정 
		sum += table[i][k];			//대각선의 총 합을 구함 
		if(sum == -n){				//그 합이 -n이면 
			(*count)++;				//빙고의 개수를 하나 증가 시킴 
		}
	} 

}
