include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<math.h>

/*1. ==두번치는 문제- 는 또는 엔터로 처리할 수 있도록 하기,

2. 과정출력*

4. 이어서연산시 곱하기?..

5.123  는 하고 지우면 다날라감.*/

int frameSIZE = 20;
int sleeptime = 40;
int limit = 9;
int i = 0, j = 0, k = 0, l = 0;
char input;
int flag = 0;
char arr[9] = { '0' };//i//버퍼.
int brr[2] = { 0 };//j//완성된 수 저장.
char orr[2] = { '0' };//k//연산자 저장.

void gotoxy(int x, int y);
void set_place_Frame();
void set_place_Num();
void set_place_Op();
void set_ready();
void set_note_on_use();
void set_start_point();
void reset();
void disp_proc();
void bracket();
void show_effect();
void hapche();
void operation();
void startCalc();

void main() {


    set_place_Frame();

    set_place_Num();

    set_place_Op();

    set_note_on_use();

    startCalc();


}

void gotoxy(int x, int y) {

    COORD pos = { x,y };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

void set_place_Frame() {

    //맨윗줄
    printf("\u250F");
    for (l = 0; l < frameSIZE; l++) {
        printf("\u2501");
    }
    printf("\u2513\n");


    //중간
    printf("\u2503--------------------\u2503 \n");//?
    for (l = 0; l < 13; l++) {
        printf("\u2503                    \u2503 \n");

        if (l == 1) {
            printf("\u2503--------------------\u2503 \n");
        }
    }
    //이름
    printf("\u2503                 KYJ\u2503 \n");


    //맨아랫줄
    printf("\u2517");
    for (l = 0; l < frameSIZE; l++) {
        printf("\u2501");

    }
    printf("\u251B\n");

}

void set_place_Num() {

    gotoxy(5, 8); printf("7");
    gotoxy(8, 8); printf("8");
    gotoxy(11, 8); printf("9");

    gotoxy(5, 10); printf("4");
    gotoxy(8, 10); printf("5");
    gotoxy(11, 10); printf("6");

    gotoxy(5, 12); printf("1");
    gotoxy(8, 12); printf("2");
    gotoxy(11, 12); printf("3");

    gotoxy(8, 14); printf("0");

}

void set_place_Op() {

    gotoxy(5, 6); printf("←");
    gotoxy(8, 6); printf("A");
    gotoxy(11, 6); printf("C");

    gotoxy(18, 6); printf("+");
    gotoxy(18, 8); printf("-");
    gotoxy(18, 10); printf("*");
    gotoxy(18, 12); printf("/");
    gotoxy(18, 14); printf("=");

}

void set_ready() {
    set_place_Frame();
    set_place_Num();
    set_place_Op();
    set_start_point();
}

void set_note_on_use() {
    gotoxy(26, 1); printf("--주의사항--");
    gotoxy(26, 3); printf("1. 정수 연산만 가능.");
    gotoxy(26, 5); printf("2. 숫자 9자리까지만 입력 해주세요.");
    gotoxy(26, 7); printf("3. 결과값 출력은 = 을 2번 입력하세요.");

}

void set_start_point() {

    gotoxy(19, 2);

}

void reset() {

    i = 0;
    j = 0;
    k = 0;
    l = 0;
    for (l = 0; l < limit; l++) { arr[l] = 0; }
    for (l = 0; l < 2; l++) { brr[l] = 0; orr[l] = 0; }

}

void disp_proc() {

    gotoxy(2, 18);
    for (l = 0; l < limit; l++) {
        printf("[%d]:%c\t", l, arr[l]);
    }
    gotoxy(2, 21);
    printf("num1: %d\tnum2: %d", brr[0], brr[1]);

    gotoxy(2, 23);
    printf("op1: %c\top2: %c", orr[0], orr[1]);

    set_start_point();

}

void bracket() {

    switch (input) {

    case'+':
        gotoxy(17, 6); printf("[");//+
        gotoxy(19, 6); printf("]");
        Sleep(sleeptime);
        gotoxy(17, 6); printf(" ");
        gotoxy(19, 6); printf(" ");
        break;
    case'-':
        gotoxy(17, 8); printf("[");//-
        gotoxy(19, 8); printf("]");
        Sleep(sleeptime);
        gotoxy(17, 8); printf(" ");//-
        gotoxy(19, 8); printf(" ");
        break;
    case'*':
        gotoxy(17, 10); printf("[");//*
        gotoxy(19, 10); printf("]");
        Sleep(sleeptime);
        gotoxy(17, 10); printf(" ");//*
        gotoxy(19, 10); printf(" ");
        break;
    case'/':
        gotoxy(17, 12); printf("[");///
        gotoxy(19, 12); printf("]");
        Sleep(sleeptime);
        gotoxy(17, 12); printf(" ");///
        gotoxy(19, 12); printf(" ");
        break;
    case'=':
        gotoxy(17, 14); printf("[");//=
        gotoxy(19, 14); printf("]");
        Sleep(sleeptime);
        gotoxy(17, 14); printf(" ");//=
        gotoxy(19, 14); printf(" ");
        break;

    case 8:
        gotoxy(4, 6); printf("[");
        gotoxy(7, 6); printf("]");
        Sleep(sleeptime);
        gotoxy(4, 6); printf(" ");
        gotoxy(7, 6); printf(" ");
        break;
    case'A':
    case'a':
        gotoxy(7, 6); printf("[");
        gotoxy(9, 6); printf("]");
        Sleep(sleeptime);
        gotoxy(7, 6); printf(" ");
        gotoxy(9, 6); printf(" ");
        break;
    case'C':
    case'c':
        gotoxy(10, 6); printf("[");
        gotoxy(12, 6); printf("]");
        Sleep(sleeptime);
        gotoxy(10, 6); printf(" ");
        gotoxy(12, 6); printf(" ");
        break;

    case '7':
        gotoxy(4, 8); printf("[");
        gotoxy(6, 8); printf("]");
        Sleep(sleeptime);
        gotoxy(4, 8); printf(" ");
        gotoxy(6, 8); printf(" ");
        break;
    case '8':
        gotoxy(7, 8); printf("[");
        gotoxy(9, 8); printf("]");
        Sleep(sleeptime);
        gotoxy(7, 8); printf(" ");
        gotoxy(9, 8); printf(" ");
        break;
    case '9':
        gotoxy(10, 8); printf("[");
        gotoxy(12, 8); printf("]");
        Sleep(sleeptime);
        gotoxy(10, 8); printf(" ");
        gotoxy(12, 8); printf(" ");
        break;
    case '4':
        gotoxy(4, 10); printf("[");
        gotoxy(6, 10); printf("]");
        Sleep(sleeptime);
        gotoxy(4, 10); printf(" ");
        gotoxy(6, 10); printf(" ");
        break;
    case '5':
        gotoxy(7, 10); printf("[");
        gotoxy(9, 10); printf("]");
        Sleep(sleeptime);
        gotoxy(7, 10); printf(" ");
        gotoxy(9, 10); printf(" ");
        break;
    case '6':
        gotoxy(10, 10); printf("[");
        gotoxy(12, 10); printf("]");
        Sleep(20);
        gotoxy(10, 10); printf(" ");
        gotoxy(12, 10); printf(" ");
        break;
    case '1':
        gotoxy(4, 12); printf("[");
        gotoxy(6, 12); printf("]");
        Sleep(sleeptime);
        gotoxy(4, 12); printf(" ");
        gotoxy(6, 12); printf(" ");
        break;
    case '2':
        gotoxy(7, 12); printf("[");
        gotoxy(9, 12); printf("]");
        Sleep(sleeptime);
        gotoxy(7, 12); printf(" ");
        gotoxy(9, 12); printf(" ");
        break;
    case '3':
        gotoxy(10, 12); printf("[");
        gotoxy(12, 12); printf("]");
        Sleep(sleeptime);
        gotoxy(10, 12); printf(" ");
        gotoxy(12, 12); printf(" ");
        break;
    case '0':
        gotoxy(7, 14); printf("[");
        gotoxy(9, 14); printf("]");
        Sleep(sleeptime);
        gotoxy(7, 14); printf(" ");
        gotoxy(9, 14); printf(" ");
        break;

    }
}

void show_effect() {

    system("cls");
    set_ready();
    bracket();

    if ('0' <= input && input <= '9') {
        set_start_point();
        printf("%c", input);

    }
    else if (input == '=' || input == '+' || input == '-' || input == 8 || input == 'a' || input == 'A' || input == 'C' || input == 'c' || input == '*' || input == '/') {
        gotoxy(19, 3);
        printf("%c", input);
    }
    set_start_point();
}

void hapche() {

    int su = 0;

    //합체
    for (l = 0; l < i; l++) {

        su = su + (arr[l] - 48) * pow(10, (i - l - 1));

    }

    i = 0;//버퍼비우기

    //brr에 삽입.
    if (brr[0]) {//값이 이미 존재할경우 1에 넣어야 함
        if (flag == 1) {//새출발:
            brr[0] = su;
            flag = 0;
        }
        else {
            brr[1] = su;
        }

    }
    else {

        brr[0] = su;//값이 없다면 최초실행이므로
    }


}

void operation() {

    int temp;
    int count = 0;

    hapche();

    if (orr[0]) {//기존연산자존재하면 1에 넣기
        if (orr[0] == '=') {
            orr[0] = input;//=으로 결과 출력 후 이어서 연산: next op 들어왔을때 orr[0]의= 연산 수행되서 출력되는것 방지. next op가 orr[0] 에 들어갈 수 있도록. 
            disp_proc();
        }

        orr[1] = input;
        disp_proc();
    }
    else {
        orr[0] = input;//최초실행.
        disp_proc();

    }


    if (orr[1]) {//+_*///= 에서 두번쨰 연산자가 들어오면 첫번째 연산자 실행.

        switch (orr[0]) {
        case '+':
            brr[0] = brr[0] + brr[1];
            brr[1] = 0;
            disp_proc();
            break;
        case '-':
            brr[0] = brr[0] - brr[1];
            brr[1] = 0;
            break;
        case '/':
            brr[0] = brr[0] / brr[1];
            brr[1] = 0;
            disp_proc();
            break;
        case '*':
            brr[0] = brr[0] * brr[1];
            brr[1] = 0;
            disp_proc();
            break;
        case '=':
            temp = brr[0];

            while (temp != 0) {
                temp = temp / 10;
                count++;
            }
            if (brr[0] == 0) {//0이면 1자리수이지만 while문을 실행하지 않으므로
                set_start_point();
            }
            else {
                gotoxy(19 - count + 1, 2);
            }
            printf("%d", brr[0]);
            gotoxy(19, 3); printf(" ");
            disp_proc();
        }

        orr[0] = orr[1];
        orr[1] = '0';
    }

    disp_proc();
}

void print_proc() {

    //연산자 들어가면 위에 여태까지 들어간 숫자랑 연산자랑 출력해줌

    gotoxy(19, 3);
    printf("%d", brr[0]);
    printf("%c", orr[0]);
          
}

void startCalc() {

    while (1) {

        disp_proc();
        set_start_point();
        input = _getche();
        show_effect();

        //숫자
        if ('0' <= input && input <= '9') {

            arr[i] = input;//입력값 저장

            if (orr[0] == '=') {//=으로 연산 결과를 내고 그다음 바로 숫자를 입력한 경우. 새출발      
                flag = 1;
            }


            if (i != 0) {//기존값이 있다면 출력. (입력받은거 제외하고)

                gotoxy(19 - i, 2);
                for (k = 0; k < i; k++) {
                    printf("%c", arr[k]);
                }
            }

            i++;//arr index 증가. max 9

            if (i >= 10) {// 안전장치.

                system("cls");
                set_ready();

                gotoxy(2, 2); printf("ERROR! PRESS NUMBER");
                reset();

                continue;

            }

            continue;
            disp_proc();
        }
        //연산자
        else if (input == '=' || input == '+' || input == '-' || input == 8 || input == 'a' || input == 'A' || input == 'C' || input == 'c' || input == '*' || input == '/') {

            switch (input) {

            case '+':
            case '-':
            case '*':
            case '/':
            case '=':
                show_effect();
                operation();
                continue;

            case 'A': //C. all clear
            case 'a':
                system("cls");
                set_ready();
                bracket();
                reset();
                continue;

            case 'C'://CE. orr에 안들어감
            case 'c':
                i = 0;
                system("cls");
                set_ready();
                bracket();
                continue;

            case 8:
                show_effect();

                if (i != 0) {//기존값 존재시
                    gotoxy(19 - i+2, 2);
                    for (k =0; k < i-1; k++) {
                        printf("%c", arr[k]);
                    }
                    i--;
                    if (i < 0) {//i값 이탈 방지

                        i = 0;
                    }

                }
                else {//처음부터 지우기 누를떄

                    i = 0;
                }
                continue;

            default:
                continue;

                }

            }
        //종료
        else if (input == 'x') {//프로그램 종료 x
            gotoxy(17, 2); printf("OFF");
            gotoxy(0, 20);
            exit(0);
        }
        //기타 문자 - 추후 수정.
        else {
            system("cls");
            set_ready();

            gotoxy(2, 2); printf("ERROR! PRESS NUMBER");
            reset();

            continue;

        }
    }
}
