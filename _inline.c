/*
加了inline之後，編譯器會在程式中有呼叫到這支function call的地方
視情況直接把function的桯式碼代入呼叫的地方，就好像function程式碼
就直接寫在你呼叫的地方。所以以inline宣告的member function必須將
程式碼寫在宣告的地方，讓編譯器在編到這支member function時都可以
參考到其程式碼才行。一般我們class的宣告跟程式碼是分開不同檔案的。
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

    printf("輸入數值："); 
    scanf("%d", &num); 

    printf("輸入平方："); 
    scanf("%d", &power); 

    printf("%d 平方：%d\n", num, myPow2(num));
    printf("%d 的 %d 次方 %d\n", num, power, myPow(num, power));
    system("PAUSE");   
    return;
}