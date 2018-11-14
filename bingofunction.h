#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5			//빙고 테이블의 크기 기호 상수 N 
#define M 3			//이기는 조건 (빙고 개수) M 

void initiate_bingo(int n, int table1[n][n], int table2[n][n]);	
//빙고 테이블을 처음에 만들어줌 
void print_bingo(int n, int table1[n][n]);	
//빙고 테이블 현재 상황을 화면에 출력
void get_number_byMe(int tri, int n, int choice[n*n]);			
//내가 빙고 번호 입력 선택
void get_number_byCom(int tri, int n, int choice[n*n]);
//컴퓨터가 임의로 빙고 번호 선택
void process_bingo(int n, int tri, int table1[n][n], int table2[n][n], int choice[tri]);
//선택된 숫자를 입력받아서 빙고 테이블 칸을 채움
void count_bingo(int n, int table[n][n], int *count);		
//빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산하여 반환 
