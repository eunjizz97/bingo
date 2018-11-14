#include "bingofunction.h"


void initiate_bingo(int n, int table1[n][n], int table2[n][n])
{
	int i, j;				//������ �迭 table���� ��,�� ǥ�� 
	
	int value1[n*n];		//������ �迭���� table1 ������� ���� �ش��ϴ� value1 ����  
	int value2[n*n]; 		//������ �迭���� value2 ������� ���� �ش��ϴ� value2 ���� 
	int a, b;				//a��° �迭, b��° �迭�� ���ϱ� ���� ���� 
	
	int max;				//���� �߻� ����(=table ũ��) 
	max = n*n;				//���� �߻� ������ tableũ��� n*n 
	
	
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
	
	a = 0;								//a=0���� �ʱ�ȭ 
	
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
	
	a = 0;								//a=0���� �ʱ�ȭ 
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			table2[i][j] = value2[a];	//�� ���̺� ���� ������ ���� �ݺ����� ���� value�� ������Ŵ 
			a++;						//a�� ���� �ϳ��� �ø��鼭 �ݺ� 
			
		}
	}
	
}


void print_bingo(int n, int table1[n][n])
{
	int i, j;								//�ݺ����� ���� ���� & �迭�� ��� �� 
	
	printf("< ����� ���� ���̺� >\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%d\t", table1[i][j]);	//���� ���̺��� ����ϴ� �ڵ� 
		}	printf("\n");					//���� �ٲپ� ����ϴ� �ڵ� 
	}
	printf("\n");
	
/*	printf("< ��ǻ�� ���� ���̺� >\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%d\t", table2[i][j]);	//���� ���̺��� ����ϴ� �ڵ� 
		}	printf("\n");					//���� �ٲپ� ����ϴ� �ڵ� 
	}
	printf("\n");
*/	
}

void get_number_byMe(int tri, int n, int choice[n*n])
{
	int j;
	
	
	printf("1�� %d ������ ���ڸ� �����Ͻÿ�. : ", n*n);	//���� �����϶�� ��� 
	scanf("%d", &choice[tri]);							//tri��° (����ڰ�) ���� 
	
		//<���� ���� �� �����ϴ� �ڵ�> 
		while(choice[tri]<1||choice[tri]>n*n){
			printf("���� ���� ���� �ƴմϴ�. 1�� %d ������ ���� �Է��Ͻÿ�. : ", n*n);
			scanf("%d", &choice[tri]);	//�߸��� �����̹Ƿ� tri��° ������ �ٽ� �Ҵ��Ŵ 
		}

	//<�̹� ���õ� �� �����ϴ� �ڵ�> 
	for(j=0; j<tri; j++){				//���� ���ú��� �������� ���ð� ���ϱ� ���� 
		
		while(choice[tri]==choice[j]){	//�̹� ������ �� �����ϱ� ���� 
											
			printf("�̹� ���õ� �� �Դϴ�. �ٽ� �Է��Ͻÿ�. : ");
			scanf("%d", &choice[tri]);	//�߸��� �����̹Ƿ� tri��° ������ �ٽ� �Ҵ�   
		}
	}	
}

void get_number_byCom(int tri, int n, int choice[n*n])
{
	int j;
	int max;
	max = n*n; 

	
		printf("��ǻ�Ͱ� ������ ���� �Դϴ�. : ");	
		
 
		choice[tri] = rand()%max+1;		//1���� n*n+1 ������ �� �����ϰ� �߻� 
		
			//<�̹� ���õ� �� �����ϴ� �ڵ�> 
			for(j=0; j<tri; j++){					//���� ���ú��� �������� ���ð� ���ϱ� ���� 
				if(choice[tri]==choice[j]){			//�̹� ������ �� ���� 
				choice[tri] = rand()%max+1;			//�ٽ� �����ϰ� ���� 
					j = 0;							//�� ��ĥ �� ������ ����  
				}
			}
		
			//<��ǻ�Ͱ� ������ ���� ���> 
			printf("%d\n", choice[tri]);			//��ǻ�Ͱ� ������ ���� ��� 
		

}

void process_bingo(int n, int tri, int table1[n][n], int table2[n][n], 
					int choice[tri])
{
	int i, j;
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(table1[i][j]==choice[tri])	//choice���� table�� ���� ������, 
				table1[i][j] = -1;			//(choice���� �ٲٸ� get number by�Լ��� ������ ����Ƿ�)
											//table ���� -1�� �ٲپ��ش�.
				
			if (table2[i][j]==choice[tri]) //choice���� table�� ���� ������, 
				table2[i][j] = -1;			//(choice���� �ٲٸ� get number by�Լ��� ������ ����Ƿ�)
											//table ���� �ٲپ��ش�.
		}
	}
}


void count_bingo(int n, int table[n][n], int *count)
{
	int i, j, k;		//table�� ���° �迭������ �ٷ�� ���� �ʿ��� ������   
	int sum=0;			//sum ���� 0���� �ʱ�ȭ  
	
	*count=0;			//count ���� 0���� �ʱ�ȭ 
	
	//<������ ���� ���� ���� �ڵ�> 
	for(i=0; i<n; i++){				//�� �ϳ��� ������Ű�� �ݺ� 
		for(j=0; j<n; j++){			//���� ������Ų �� ���� �ϳ��� ������Ű�鼭 
			sum += table[i][j];		//i���� ������ ���� ���� 
			if(sum == -n){			//�� ���� -n �̸� 
				(*count)++;			//������ ������ �ϳ� ���� ��Ŵ 
			}
		}
		sum = 0;					//���� �ٲ�� ����, sum �� �ٽ� 0���� �ʱ�ȭ ��Ŵ 
	}
	
	//<������ ���� ���� ���� �ڵ�> 
	for(j=0; j<n; j++){				//�� �ϳ��� ������Ű�� �ݺ� 
		for(i=0; i<n; i++){			//���� ������Ų �� ���� �ϳ��� ������Ű�鼭 
			sum += table[i][j];		//j���� ����� ���� ���� 
			if(sum == -n){			//�� ���� -n �̸� 
				(*count)++;			//������ ������ �ϳ� ���� ��Ŵ 
			}
		}
		sum = 0;					//���� �ٲ�� ����, sum�� �ٽ� 0���� �ʱ�ȭ 
	}
	
	//<�밢�� ���� ���� ���� �ڵ�> 
	for(i=0; i<n; i++){				//i�� �ϳ��� ������Ű�鼭 
		sum += table[i][i];			//�밢���� �� ���� ���� 
		if(sum == -n){				//�� ���� -n �̸� 
			(*count)++;				//������ ������ �ϳ� ���� ��Ŵ 
		}
	}
	
	sum = 0;						//sum=0 ���� �Ҵ���� ���� �ڵ忡�� sum=0���� �ʱ�ȭ �ǰ� �� 
	
	//<�ݴ���� �밢�� ���� ���� ���� �ڵ�>
	for(i=0; i<n; i++){				//i�� �ϳ��� ������Ű�鼭 
		k = n-1-i;					//k���� �پ�鵵�� k�� ���� 
		sum += table[i][k];			//�밢���� �� ���� ���� 
		if(sum == -n){				//�� ���� -n�̸� 
			(*count)++;				//������ ������ �ϳ� ���� ��Ŵ 
		}
	} 

}
