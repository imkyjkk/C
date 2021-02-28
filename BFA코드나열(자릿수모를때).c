
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

	printf("생성할 비밀번호의 자리수  : "); scanf("%d", &n);

	//비밀번호 생성
	password_ptr = make_password(n);
	
	//비밀번호 보기
	///printf("%s\n", password_ptr);

	
	//찾기
	brute_force(password_ptr);


	free(password_ptr);

	return 0;

}




char* make_password(int n) {

	int i; char j;
	char pool_arr[FINAL_ASCII - START_ASCII+1]; // 경우의 수는 +1
	int* index_ptr;
	char* password_ptr;
	srand((unsigned)time(NULL));


	//비밀번호 풀 생성
	for (i = 0, j = START_ASCII; i < FINAL_ASCII - START_ASCII+1; i++,j++) {
		pool_arr[i] = j;
		//printf("%c", j);//풀 확인
	}
	

	//동적할당 - 랜덤인덱스용
	index_ptr = (int*)malloc(n * sizeof(int));

	//동적할당 - 추출된문자용
	password_ptr = (char*)malloc(n * sizeof(char) + 1);


	//랜덤 인덱스값 n 개 발생
	for (i = 0; i < n; i++) {
		*(index_ptr + i) = rand() % (FINAL_ASCII - START_ASCII+1); 
	}

	//password 문자열 생성
	for (i = 0; i < n; i++) {
		*(  password_ptr + i  ) =   pool_arr [ *(index_ptr + i) ] ;
	} 
	*(password_ptr + n) = '\0';

	//메모리 반환
	free(index_ptr);


	return password_ptr;

}

void brute_force(char* password_ptr) {
	int j = 0;//할당받은 자리수 채우기
	int k;//앞자리 변화시 하위자리 초기화용
	int ans_f = 0; //정답플래그
	int count = 1;//자리수 증가할때 +1
	int try3 = 1;//시도 횟수 출력
	char* me;

	while (1) { //큰 무한루프
		//비밀번호 자리수에 해당하는 문자열 생성.
		printf("\n\n\n--------------------------------------%d 의 자리이다!-----------------------------------------------\n", count);
		me = (char*)malloc(count * sizeof(char) + 1);
		for (j = 0; j < count * sizeof(char); j++) {
			*(me + j) = START_ASCII;
		}
		*(me + count * sizeof(char)) = '\0';



		while (1) { //숫자뺑뺑이

					if (strcmp(password_ptr, me) == 0) { //정답이 맞다면 숫자뺑뻉이 탈출
						printf("%s 정답!, %d 번째 시도!\n", me, try++);
						ans_f = 1;
						break;
					}
					else {//정답이 아니라면
						printf("%s 실패!, %d 번 시도!\n", me, try3++);

								if (count - 0 > 0) {//1자리 수라면

									if (me[count - 1] < FINAL_ASCII) {
										me[count - 1] = me[count - 1] + 1;//제일 마지막 항(변화시켜야 할)이 COUNT-1이 된다.
										for (k = count - 0; k < count; k++) {
											me[k] = START_ASCII; //하위자리들은 다  A로 채워야 함. 
										}//
									}
									else {//제일 마지막 항이 Z 일때 검사했는데도 아닐 때
													
													if (count - 1 > 0) {//2자리 수라면

															if (me[count - 2] < FINAL_ASCII) { //아직  그 앞자리가 Z가 아니라면 // ZZ 까지 가능해야함
																me[count - 2] = me[count - 2] + 1; //마지막항보다 바로 앞자리 1증가 //BZ
																for (k = count - 1; k < count; k++) {
																	me[k] = START_ASCII; //하위자리들은 다  A로 채워야 함. 
																}//

															}
															else {

																			if (count - 2 > 0) {//앞에서 한 앞자리가 최고자리가 아니였다면  //ZZZ까지 가능

																				if (me[count - 3] < FINAL_ASCII) {//아직  그 앞자리가 Z가 아니라면 // ZZ 까지 가능해야함
																					me[count - 3] = me[count - 3] + 1;
																					for (k = count - 2; k < count; k++) {
																						me[k] = START_ASCII; //하위자리들은 다  A로 채워야 함. 
																					}//

																				}
																				else {
																				

																					if (count - 3 > 0) {//앞에서 한 앞자리가 최고자리가 아니였다면  //ZZZ까지 가능

																						if (me[count - 4] < FINAL_ASCII) {//아직  그 앞자리가 Z가 아니라면 // ZZ 까지 가능해야함
																							me[count - 4] = me[count - 4] + 1;
																							for (k = count - 3; k < count; k++) {
																								me[k] = START_ASCII; //하위자리들은 다  A로 채워야 함. 
																							}//

																						}
																						else {






																							///이곳에 반복.





																						}



																					}
																					else {//변화시킬 상위자리가 없다면 자릿수를 늘려서 생성
																						count++; //자리수 증가표시.
																						break;
																					}//AAZ까진 댐
																				








																				
																				}



																			}
																			else {//변화시킬 상위자리가 없다면 자릿수를 늘려서 생성
																				count++; //자리수 증가표시.
																				break;
																			}//AAZ까진 댐

															}



													}
													else {//변화시킬 상위자리가 없다면 자릿수를 늘려서 생성

														count++; //자리수 증가표시.
														break;
													}

									}
								}
								else {//변화시킬 상위자리가 없다면 자릿수를 늘려서 생성

									count++; //자리수 증가표시.
									break;
								}
					}
		}
									
									
					
							

								
	



		//정답이라던가 아니면 자릿수를 늘려서 할 경우
		free(me);
		//정답일 경우 제일 바깥 와일문 탈출, 종료.
		if (ans_f == 1) {
			break;
		}
	}

}


