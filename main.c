#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	
void initiate_bingo(int n, int table1[n][n], int table2[n][n]);	//���� ���̺��� ó���� ������� 
void print_bingo(int n, int table1[n][n], int table2[n][n]);	//���� ���̺� ���� ��Ȳ�� ȭ�鿡 ���
void get_number_byMe(int *i, int n, int choice1[n*n], int choice2[n*n]);			
											//���� ���� ��ȣ �Է� ����
void get_number_byCom(int *i, int n, int choice1[n*n], int choice2[n*n]);
											//��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ����
void process_bingo();						//���õ� ���ڸ� �Է¹޾Ƽ� ���� ���̺� ĭ�� ä��
void count_bingo();							//���� ���̺��� ä�� ����/����/�밢�� �� ���� ����Ͽ� ��ȯ 
	
int main(int argc, char *argv[]) {

	int N = 4;		//�������̺��� ũ�� ����
	int M = 3;		//������ �̱�� ���� 
	int user_table[N][N];	//������� N*N ũ���� ���� ���̺�
	int com_table[N][N];	//��ǻ���� N*N ũ���� ���� ���̺� 
	int userchoice[N*N];	//����ڰ� ������ ���ڸ� �����ϴ� �迭 
	int comchoice[N*N]; 	//��ǻ�Ͱ� ������ ���ڸ� �����ϴ� �迭 
	int tri=0;				//���� ������ Ƚ�� ���� ���� (���° turn ����)
	int turn;				//���° turn ���� �ºΰ� ������ ����ϱ� ���� 
	
	turn = tri+1;
	 
	initiate_bingo(N, user_table, com_table);
	
	//do{
	
	print_bingo(N, user_table, com_table); 
	
	//tri = 0 
	get_number_byMe(&tri, N, userchoice, comchoice); //0�� �Ҵ� �� tri = 1 
	tri--;											//tri = 0
	get_number_byCom(&tri, N, userchoice, comchoice); //0�� �Ҵ� �� tri = 1
	
	//}while(tri>25||���� M�� �ϼ�); 
	
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

void initiate_bingo(int n, int table1[n][n], int table2[n][n])	//***�� �� �����Ѱ� ���� ****
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

void get_number_byMe(int *i, int n, int choice1[n*n], int choice2[n*n])	//** *i ��� *tri? 
{
	//int *i; 						**�Լ� �ۿ����� i���� �����Ǿ�� �ϱ� ������ ������ �ʿ�?
	int j;
	
	for(; *i<n*n; *i++){
	
	
		printf("���ڸ� �����Ͻÿ�. : ");
		scanf("%d", &choice1[*i]);		//i��° ����� ���� 
	
		if(choice1[*i]<1||choice1[*i]>25){
			printf("���� ���� ���� �Է��Ͻÿ�. : ");  
			scanf("%d", &choice1[*i]);	//�߸��� �����̹Ƿ� i��° ������ �ٽ� �Ҵ��Ŵ 
		}
		
		for(j=0; j<*i; j++){					//i(���� ���� Ƚ��)���� �������� ���ð� ���ϱ� ���� 
			if(choice1[*i]==choice1[j]||	//����ڰ� �̹� ������ �� �����ϱ� ���� 
				choice1[*i]==choice2[j]){	//��ǻ�Ͱ� �̹� ������ �� �����ϱ� ���� 
												
				printf("�̹� ���õ� �� �Դϴ�. �ٽ� �Է��Ͻÿ�. : ");
				scanf("%d", &choice1[*i]);	//�߸��� �����̹Ƿ� i��° ������ �ٽ� �Ҵ�  
			}
		}
	}
}

void get_number_byCom(int *i, int n, int choice1[n*n], int choice2[n*n])
{
	int j;
	int max;
	max = n*n; 
	
	for(; *i<max; *i++){
	
		printf("��ǻ�Ͱ� ������ ���� �Դϴ�. : ");
		
		srand((unsigned)time(NULL));
		choice2[*i] = rand()%max+1;		//1���� n*n+1 ������ �� �����ϰ� �߻� 
		
		
		for(j=0; j<*i; j++){					//i(���� ���� Ƚ��)���� �������� ���ð� ���ϱ� ���� 
			if(choice2[*i]==choice1[j]||	//����ڰ� �̹� ������ �� ����
				choice2[*i]==choice2[j]){	//��ǻ�Ͱ� �̹� ������ �� ���� 
				
				choice2[*i] = rand()%max+1;	//�ٽ� �����ϰ� ���� 
				
			}
		}
		
		printf("%d\n", &choice2[*i]);	//�߸��� �����̹Ƿ� i��° ������ �ٽ� �Ҵ�
	}
}
