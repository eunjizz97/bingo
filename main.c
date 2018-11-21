#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bingofunction.h"

#define N 5			//���� ���̺��� ũ�� ��ȣ ��� N 
#define M 3			//�̱�� ���� (���� ����) M 

 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	
void initiate_bingo(int n, int table1[n][n], int table2[n][n]);	//���� ���̺��� ó���� ������� 
void print_bingo(int n, int table1[n][n]);	//���� ���̺� ���� ��Ȳ�� ȭ�鿡 ���
void get_number_byMe(int tri, int n, int choice[n*n]);			
											//���� ���� ��ȣ �Է� ����
void get_number_byCom(int tri, int n, int choice[n*n]);
											//��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ����
void process_bingo(int n, int tri, int table1[n][n], int table2[n][n], int choice[tri]);
											//���õ� ���ڸ� �Է¹޾Ƽ� ���� ���̺� ĭ�� ä��
void count_bingo(int n, int table[n][n], int *count);		//���� ���̺��� ä�� ����/����/�밢�� �� ���� ����Ͽ� ��ȯ 
	
int main(int argc, char *argv[]) {

	int user_table[N][N];	//������� N*N ũ���� ���� ���̺�
	int com_table[N][N];	//��ǻ���� N*N ũ���� ���� ���̺� 
	
	int choice[N*N];		//ũ�Ⱑ N*N�� choice �迭 (����� choice�� ��ǻ�� choice ���) 
	int tri;				//choice �迭�� tri ��° �迭 
	int turn;				//���° turn ���� �ºΰ� ������ ����ϱ� ���� 
	
	int usercount;			//������� ���� ���� 
	int comcount;			//��ǻ���� ���� ���� 
	
	srand((unsigned)time(NULL));					//���ึ�� �޶����� ���� ���� ���� 
	
	printf("\t�ٺ�����ӡ�\n\n");
	printf("< ���ӹ�� >\n");
	printf("����ڿ� ��ǻ�Ͱ� ���ư��� %dĭ ¥�� �����ǿ� ���ڸ� ä���.\n", N*N);
	printf("ä���� ���ڴ� -1�� �ٲ��.\n");
	printf("count�� ���� %d��  �Ǵ� ����� �¸�!\n", M);
	printf("��, ����ڿ� ��ǻ�� ���ÿ� ���� count�� %d�� �̻��� �Ǹ� ���ºη� �Ѵ�.\n\n", M);
	 
	initiate_bingo(N, user_table, com_table);		//������ ���� 

	print_bingo(N, user_table); 			//������ �������� ������ 
	
	
	for(tri=0; tri<N*N; tri++){				//��� ĭ�� ä������ ������ �ݺ� 
		
		//<turn�� ����ϴ� �ڵ�> 
		if(tri==0){									//tri�� 0�̸� 
			turn = 1;								//turn �� 1 
		} 
			
		else if(tri%2==0){							//tri�� ¦���� = ����ڰ� �������� �� 
			turn = (tri/2)+1;						//turn�� tri�� 2�� ���� �� 
		}
			
		else if(tri%2!=0){							//tri �� Ȧ���� = ��ǻ�Ͱ� �������� �� 
			turn = ((tri-1)/2)+1;					//turn�� tri-1 �� 2�� ���� �� 
		}
		
		
		//<������ �ڵ� ����> 
		printf("\n< %d ��° turn >\n", turn);		//������ ���° turn���� ��� ***���߿� �� 
		
		if(tri==0||tri%2==0) 						//tri=0�̰ų� ¦����
			get_number_byMe(tri, N, choice); 		//����ڰ� ���� ���� 
				
		else										//�׷��� ������, ��, tri�� Ȧ���� 
			get_number_byCom(tri, N, choice); 		//��ǻ�Ͱ� ���� ���� 
				
			
		process_bingo(N, tri, user_table, com_table, choice);//���� ä�� 
		print_bingo(N, user_table);		//���� ä�� �������� �ٽ� ��� 

		count_bingo(N, user_table, &usercount);		//������� ���� ��� �� 
			printf("user count = %d\n", usercount);	//������� ���� ���� ��� 
			
		count_bingo(N, com_table, &comcount);		//��ǻ���� ���� ��� �� 
			printf("com count = %d\n", comcount);	//��ǻ���� ���� ���� ���
				
				
		//<�ݺ��� ������ ������ ��Ÿ���� �ڵ�>	
		if((usercount>=M)||(comcount>=M))
			break;						//usercount�� M���� ũ�ų� ������ Ȥ��, comcount�� M���� ũ�ų� ������ �ݺ����� 

	}
	
	//<���� ����� ����ϴ� �ڵ�> 
	if(usercount>=M && comcount>=M){				//usercount�� comcount�� �Ѵ� M���� ũ�ų� ������ 
		printf("\n���º�! turn : %d\n", turn);		//���ºο� turn�� ����Ѵ�.
													//(��ĭ�� ä�ﶧ ���� ������ +2 ���� �� �� �ֱ� ����) 
	}
	
	else												//usercount�� comcount�� �ٸ� ���(�Ϲ����� ���) 
	{
		if(usercount>=M){								//usercount�� M���� ũ�ų� ������ 
			printf("\n����� �¸�! turn : %d\n", turn);	//����� �¸��� turn ��� 
		}
	
		if(comcount>=M){								//comcount�� M���� ũ�ų� ������ 
			printf("\n��ǻ�� �¸�! turn : %d\n", turn);	//��ǻ�� �¸��� turn ��� 
		}
	}
	
	
	return 0;
}

