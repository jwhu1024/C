/*
�[�Finline����A�sĶ���|�b�{�������I�s��o��function call���a��
�����p������function��չ���X�N�J�I�s���a��A�N�n��function�{���X
�N�����g�b�A�I�s���a��C�ҥH�Hinline�ŧi��member function�����N
�{���X�g�b�ŧi���a��A���sĶ���b�s��o��member function�ɳ��i�H
�ѦҨ��{���X�~��C�@��ڭ�class���ŧi��{���X�O���}���P�ɮת��C
*/
#include <stdio.h>

inline int myPow2(int);
int myPow(int, int);

inline int myPow2(int num) { 
    return num*num; 
}

int myPow(int n, int p) {
    int r = 1; 
    int i;
    for(i = 0; i < p; i++) {
        r *= n;
    } 
    return r; 
}

void main()
{
	int num = 0;
    int power = 0; 

    printf("��J�ƭȡG"); 
    scanf("%d", &num); 

    printf("��J����G"); 
    scanf("%d", &power); 

    printf("%d ����G%d\n", num, myPow2(num));
    printf("%d �� %d ���� %d\n", num, power, myPow(num, power));
    system("PAUSE");   
    return;
}