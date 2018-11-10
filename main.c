#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	
void initiate_bingo(int n, int table1[n][n], int table2[n][n]);	//���� ���̺��� ó���� ������� 
void print_bingo(int n, int table1[n][n], int table2[n][n]);	//���� ���̺� ���� ��Ȳ�� ȭ�鿡 ���
void get_number_byMe(int choice);			//���� ���� ��ȣ �Է� ����
void get_number_byCom(int choice);			//��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ����
void process_bingo();						//���õ� ���ڸ� �Է¹޾Ƽ� ���� ���̺� ĭ�� ä��
void count_bingo();							//���� ���̺��� ä�� ����/����/�밢�� �� ���� ����Ͽ� ��ȯ 
	
int main(int argc, char *argv[]) {

	int N = 4;		//�������̺��� ũ�� ����
	int M = 3;		//������ �̱�� ���� 
	int user_table[N][N];	//������� N*N ũ���� ���� ���̺�
	int com_table[N][N];	//��ǻ���� N*N ũ���� ���� ���̺� 

	
	initiate_bingo(N, user_table, com_table);
	
	print_bingo(N, user_table, com_table); 
	
	return 0;
}

/* void initiate_bingo(int n, int *table1, int *table2)	//*** *table1? table1[n][n]? table1?
{
	int i, j;					//Ư�� Ƚ����ŭ �ݺ��ϱ� ���� ���� 
	int max;					//���� �߻� ������ ���� ������ ��  
	int assigned_value[n*n];	//�̹� ���� ���� ������ ��  
	
	max = n*n;		//���� ���̺� ĭ ��  
	
	srand((unsigned)time(NULL));
	
	//*** pointer ���? �迭 ���? 
}*/

void initiate_bingo(int n, int table1[n][n], int table2[n][n])	//***�� �� �����Ѱ� ���� 
{
	int i, j;
	int k, l;
	int max;
	max = n*n;
	
	srand((unsigned)time(NULL));
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){	 
			table1[i][j] = rand()%max+1;		//������ �迭�� 1~max������ �� �Ҵ�
			
			for(k=0; k<i; k++){
				for(l=0; l<j; l++){
					if(table1[i][j]==table1[k][l])
						i--;
						j--;			// ���� ���� �ߺ��Ǵ� ���̸� table[i][j]�� �� �ٽ� �Ҵ� 
						continue;		// continue �� �̿��Ͽ� �ٽ� �ݺ��Ѵ�. 
				}
			} 
		}
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){	 
			table2[i][j] = rand()%max+1;		//������ �迭�� 1~max������ �� �Ҵ�
			
			for(k=0; k<i; k++){
				for(l=0; l<j; l++){
					if(table2[i][j]==table2[k][l])
						i--;
						j--;			// ���� ���� �ߺ��Ǵ� ���̸� table[i][j]�� �� �ٽ� �Ҵ� 
						continue;		// continue �� �̿��Ͽ� �ٽ� �ݺ��Ѵ�. 
				}
			} 
		}
	}
}

void print_bingo(int n, int table1[n][n], int table2[n][n])
{
	int i, j;							//�ݺ����� ���� ���� 
	
	printf("< ����� ���� ���̺� >\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%d\t", table1[i][j]);	//���� ���̺��� ����ϴ� �ڵ� 
		}	printf("\n");					//���� �ٲپ� ����ϴ� �ڵ� 
	}
	printf("\n");
	
	printf("< ��ǻ�� ���� ���̺� >\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%d\t", table2[i][j]);	//���� ���̺��� ����ϴ� �ڵ� 
		}	printf("\n");					//���� �ٲپ� ����ϴ� �ڵ� 
	}
	printf("\n");
	
}


