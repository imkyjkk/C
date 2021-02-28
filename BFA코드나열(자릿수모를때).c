
/* Brute-Force Attack */


#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


//Range 33~126
#define START_ASCII 65
#define FINAL_ASCII 90

char* make_password(int n);
void brute_force(char* ptr);

int main() {

	int n;
	char* password_ptr;

	printf("������ ��й�ȣ�� �ڸ���  : "); scanf("%d", &n);

	//��й�ȣ ����
	password_ptr = make_password(n);
	
	//��й�ȣ ����
	///printf("%s\n", password_ptr);

	
	//ã��
	brute_force(password_ptr);


	free(password_ptr);

	return 0;

}




char* make_password(int n) {

	int i; char j;
	char pool_arr[FINAL_ASCII - START_ASCII+1]; // ����� ���� +1
	int* index_ptr;
	char* password_ptr;
	srand((unsigned)time(NULL));


	//��й�ȣ Ǯ ����
	for (i = 0, j = START_ASCII; i < FINAL_ASCII - START_ASCII+1; i++,j++) {
		pool_arr[i] = j;
		//printf("%c", j);//Ǯ Ȯ��
	}
	

	//�����Ҵ� - �����ε�����
	index_ptr = (int*)malloc(n * sizeof(int));

	//�����Ҵ� - ����ȹ��ڿ�
	password_ptr = (char*)malloc(n * sizeof(char) + 1);


	//���� �ε����� n �� �߻�
	for (i = 0; i < n; i++) {
		*(index_ptr + i) = rand() % (FINAL_ASCII - START_ASCII+1); 
	}

	//password ���ڿ� ����
	for (i = 0; i < n; i++) {
		*(  password_ptr + i  ) =   pool_arr [ *(index_ptr + i) ] ;
	} 
	*(password_ptr + n) = '\0';

	//�޸� ��ȯ
	free(index_ptr);


	return password_ptr;

}

void brute_force(char* password_ptr) {
	int j = 0;//�Ҵ���� �ڸ��� ä���
	int k;//���ڸ� ��ȭ�� �����ڸ� �ʱ�ȭ��
	int ans_f = 0; //�����÷���
	int count = 1;//�ڸ��� �����Ҷ� +1
	int try3 = 1;//�õ� Ƚ�� ���
	char* me;

	while (1) { //ū ���ѷ���
		//��й�ȣ �ڸ����� �ش��ϴ� ���ڿ� ����.
		printf("\n\n\n--------------------------------------%d �� �ڸ��̴�!-----------------------------------------------\n", count);
		me = (char*)malloc(count * sizeof(char) + 1);
		for (j = 0; j < count * sizeof(char); j++) {
			*(me + j) = START_ASCII;
		}
		*(me + count * sizeof(char)) = '\0';



		while (1) { //���ڻ�����

					if (strcmp(password_ptr, me) == 0) { //������ �´ٸ� ���ڻ��R�� Ż��
						printf("%s ����!, %d ��° �õ�!\n", me, try++);
						ans_f = 1;
						break;
					}
					else {//������ �ƴ϶��
						printf("%s ����!, %d �� �õ�!\n", me, try3++);

								if (count - 0 > 0) {//1�ڸ� �����

									if (me[count - 1] < FINAL_ASCII) {
										me[count - 1] = me[count - 1] + 1;//���� ������ ��(��ȭ���Ѿ� ��)�� COUNT-1�� �ȴ�.
										for (k = count - 0; k < count; k++) {
											me[k] = START_ASCII; //�����ڸ����� ��  A�� ä���� ��. 
										}//
									}
									else {//���� ������ ���� Z �϶� �˻��ߴµ��� �ƴ� ��
													
													if (count - 1 > 0) {//2�ڸ� �����

															if (me[count - 2] < FINAL_ASCII) { //����  �� ���ڸ��� Z�� �ƴ϶�� // ZZ ���� �����ؾ���
																me[count - 2] = me[count - 2] + 1; //�������׺��� �ٷ� ���ڸ� 1���� //BZ
																for (k = count - 1; k < count; k++) {
																	me[k] = START_ASCII; //�����ڸ����� ��  A�� ä���� ��. 
																}//

															}
															else {

																			if (count - 2 > 0) {//�տ��� �� ���ڸ��� �ְ��ڸ��� �ƴϿ��ٸ�  //ZZZ���� ����

																				if (me[count - 3] < FINAL_ASCII) {//����  �� ���ڸ��� Z�� �ƴ϶�� // ZZ ���� �����ؾ���
																					me[count - 3] = me[count - 3] + 1;
																					for (k = count - 2; k < count; k++) {
																						me[k] = START_ASCII; //�����ڸ����� ��  A�� ä���� ��. 
																					}//

																				}
																				else {
																				

																					if (count - 3 > 0) {//�տ��� �� ���ڸ��� �ְ��ڸ��� �ƴϿ��ٸ�  //ZZZ���� ����

																						if (me[count - 4] < FINAL_ASCII) {//����  �� ���ڸ��� Z�� �ƴ϶�� // ZZ ���� �����ؾ���
																							me[count - 4] = me[count - 4] + 1;
																							for (k = count - 3; k < count; k++) {
																								me[k] = START_ASCII; //�����ڸ����� ��  A�� ä���� ��. 
																							}//

																						}
																						else {






																							///�̰��� �ݺ�.





																						}



																					}
																					else {//��ȭ��ų �����ڸ��� ���ٸ� �ڸ����� �÷��� ����
																						count++; //�ڸ��� ����ǥ��.
																						break;
																					}//AAZ���� ��
																				








																				
																				}



																			}
																			else {//��ȭ��ų �����ڸ��� ���ٸ� �ڸ����� �÷��� ����
																				count++; //�ڸ��� ����ǥ��.
																				break;
																			}//AAZ���� ��

															}



													}
													else {//��ȭ��ų �����ڸ��� ���ٸ� �ڸ����� �÷��� ����

														count++; //�ڸ��� ����ǥ��.
														break;
													}

									}
								}
								else {//��ȭ��ų �����ڸ��� ���ٸ� �ڸ����� �÷��� ����

									count++; //�ڸ��� ����ǥ��.
									break;
								}
					}
		}
									
									
					
							

								
	



		//�����̶���� �ƴϸ� �ڸ����� �÷��� �� ���
		free(me);
		//������ ��� ���� �ٱ� ���Ϲ� Ż��, ����.
		if (ans_f == 1) {
			break;
		}
	}

}


