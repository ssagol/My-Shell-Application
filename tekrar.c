#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
    // ilk girilen input işlem adı  A[0]
    // ikinci girien input ekrana ne yazılması gerektiği  A[1]
    // üçüncü girilen input ise tekrar sayısı  A[2]

    // tekrar Saliha 4  gibi..

	if(numCheck(argv[2])){  // önce sayı kontrolü
		int i;
		for(i = 0; i< atoi(argv[2]);i++){
			printf("%s",argv[1]);  // ekrana yazılacak metni basar
			printf("\n");
		}
		printf("\n");
	}
	else{
        printf("Yanlis giris yapildi");

    }
	
	return 0;
}

int numCheck (char *argv){  
    int i = 0;
	while(argv[i] != '\0'){ // karakter olmayana kadar dön
		if(argv[i]  <= '0' || argv[i] >= '9'){ // eğer 0-9 arasında bişey değilse
			return 0;   // num değilse 0 dönsün
		}else{
         	return 1;  // num ise 1 dönsün
        }
		i++;
    }
}
