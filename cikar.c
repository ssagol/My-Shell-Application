#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int num1, num2, result;
    num1 = atoi(argv[0]);   // string diziyi integer'a çevirme işlemi
    num2 = atoi(argv[1]);

    result = num1 - num2;   // çıkarma işlemi
    
    printf("%d - %d = %d \n",num1,num2,result);  // sonuc yazdırrma
    
    return 0;
}
