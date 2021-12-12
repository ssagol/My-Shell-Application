#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // ilk girilen input işlem adı  A[0]
    // ikinci girien input ekrana ne yazılması gerektiği  A[1]
    // üçüncü girilen input ise tekrar sayısı  A[2]

    // tekrar Saliha 4  gibi..
    int count = atoi(argv[2]);  //tekrar sayısı, 2 indeks
    int temp=0;  

    while (temp < count){  // kaç kez yazılacak olana kadar koşul
        printf("%s\n", argv[1]); // ne yazılacak
        temp++;  // kaç kez yazılacak
    }
    return 0;
}