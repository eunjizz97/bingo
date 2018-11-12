#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tri;		//get number by ___ �Լ��鿡 �������� ���Ǿ�� �ϹǷ� ���������� ����.
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	
void initiate_bingo(int n, int table1[n][n], int table2[n][n]);	//���� ���̺��� ó���� ������� 
void print_bingo(int n, int table1[n][n], int table2[n][n]);	//���� ���̺� ���� ��Ȳ�� ȭ�鿡 ���
void get_number_byMe(int tri, int n, int choice1[n*n], int choice2[n*n]);			
											//���� ���� ��ȣ �Է� ����
void get_number_byCom(int tri, int n, int choice1[n*n], int choice2[n*n]);
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
	int turn;				//���° turn ���� �ºΰ� ������ ����ϱ� ���� 
	
	turn = tri+1;
	 
	initiate_bingo(N, user_table, com_table);
	
	//do{
	
	print_bingo(N, user_table, com_table); 
	
	for(tri=0; tri<N*N; tri++){
	
		get_number_byMe(tri, N, userchoice, comchoice); //***���⼭ ���� 

		get_number_byCom(tri, N, userchoice, comchoice); 
		
	}
	
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
	int max;
	int value1[n*n];		//������ �迭���� value1 ����  
	int value2[n*n]; 
	int a, b;
	max = n*n;
	
	srand((unsigned)time(NULL));
	
	value1[0] = rand()%max+1;			//value[0] �� ��ĥ �� �����Ƿ� �����Լ��� ������ �ٷ� �Ҵ� 
	
	for(a=1; a<max; a++){
	
		value1[a] = rand()%max+1;		//������ �迭�� 1~max������ �� �Ҵ�

		for(b=0; b<a; b++){
			while(value1[a]==value1[b]){	//a ��° ���� ������ ���� ������ 
				value1[a] = rand()%max+1;	//���Ҵ�  ****�� ��ĥ �� ���� 
				b = 0;				// �� ������ ������ b�� ����ؼ� Ŀ���� ������ ���� ��ĥ �� ����  
			}
		}
	}
	
	a = 0;							//a=0���� �ʱ�ȭ 
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			table1[i][j] = value1[a];	//�� ���̺� ���� ������ ���� �ݺ����� ���� value�� ������Ŵ 
			a++;						//a�� ���� �ϳ��� �ø��鼭 �ݺ� 
			
		}
	}

	value2[0] = rand()%max+1;			//value[0] �� ��ĥ �� �����Ƿ� �����Լ��� ������ �ٷ� �Ҵ� 
	
	for(a=1; a<max; a++){
	
		value2[a] = rand()%max+1;		//������ �迭�� 1~max������ �� �Ҵ�

		for(b=0; b<a; b++){
			while(value2[a]==value2[b]){	//a ��° ���� ������ ���� ������ 
				value2[a] = rand()%max+1;	//���Ҵ�  ****�� ��ĥ �� ���� 
				b = 0;				// �� ������ ������ b�� ����ؼ� Ŀ���� ������ ���� ��ĥ �� ����  
			}
		}
	}
	
	a = 0;							//a=0���� �ʱ�ȭ 
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			table2[i][j] = value2[a];	//�� ���̺� ���� ������ ���� �ݺ����� ���� value�� ������Ŵ 
			a++;						//a�� ���� �ϳ��� �ø��鼭 �ݺ� 
			
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

void get_number_byMe(int tri, int n, int choice1[n*n], int choice2[n*n])
{
	int j;
	
	
	printf("���ڸ� �����Ͻÿ�. : ");
	scanf("%d", &choice1[tri]);		//tri��° ����� ���� 
	
	do{
	
		if(choice1[tri]<1||choice1[tri]>n*n){
			printf("���� ���� ���� �ƴմϴ�. 1�� %d ������ ���� �Է��Ͻÿ�. : ", n*n);
			scanf("%d", &choice1[tri]);	//�߸��� �����̹Ƿ� tri��° ������ �ٽ� �Ҵ��Ŵ 
		}
	}while(choice1[tri]<1||choice1[tri]>n*n);
	
	do{
			
		for(j=0; j<tri; j++){				//���� ���ú��� �������� ���ð� ���ϱ� ���� 
			if(choice1[tri]==choice1[j]||	//����ڰ� �̹� ������ �� �����ϱ� ���� 
				choice1[tri]==choice2[j]){	//��ǻ�Ͱ� �̹� ������ �� �����ϱ� ���� 
												
				printf("�̹� ���õ� �� �Դϴ�. �ٽ� �Է��Ͻÿ�. : ");
				scanf("%d", &choice1[tri]);	//�߸��� �����̹Ƿ� tri��° ������ �ٽ� �Ҵ�  
			}
		}
	}while(choice1[tri]==choice1[j]||choice1[tri]==choice2[j]);	//�ѹ� �ݺ� �� ������ �߸��� ������
																	//�����ϱ� ������ do-while�� ��� 
	
}

void get_number_byCom(int tri, int n, int choice1[n*n], int choice2[n*n])
{
	int j;
	int max;
	max = n*n; 

	
		printf("��ǻ�Ͱ� ������ ���� �Դϴ�. : ");
		
		srand((unsigned)time(NULL));
		choice2[tri] = rand()%max+1;		//1���� n*n+1 ������ �� �����ϰ� �߻� 
		
		
		for(j=0; j<tri; j++){				//���� ���ú��� �������� ���ð� ���ϱ� ���� 
			if(choice2[tri]==choice1[j]||	//����ڰ� �̹� ������ �� ����
				choice2[tri]==choice2[j]){	//��ǻ�Ͱ� �̹� ������ �� ���� 
				
				choice2[tri] = rand()%max+1;	//�ٽ� �����ϰ� ���� 
				
			}
		}
		
		printf("%d\n", &choice2[tri]);	//�߸��� ������ �����ϰ� tri��° ������ ���Ҵ�

}
