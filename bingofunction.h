#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5			//���� ���̺��� ũ�� ��ȣ ��� N 
#define M 3			//�̱�� ���� (���� ����) M 

void initiate_bingo(int n, int table1[n][n], int table2[n][n]);	
//���� ���̺��� ó���� ������� 
void print_bingo(int n, int table1[n][n]);	
//���� ���̺� ���� ��Ȳ�� ȭ�鿡 ���
void get_number_byMe(int tri, int n, int choice[n*n]);			
//���� ���� ��ȣ �Է� ����
void get_number_byCom(int tri, int n, int choice[n*n]);
//��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ����
void process_bingo(int n, int tri, int table1[n][n], int table2[n][n], int choice[tri]);
//���õ� ���ڸ� �Է¹޾Ƽ� ���� ���̺� ĭ�� ä��
void count_bingo(int n, int table[n][n], int *count);		
//���� ���̺��� ä�� ����/����/�밢�� �� ���� ����Ͽ� ��ȯ 
