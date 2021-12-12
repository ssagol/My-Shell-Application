#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    char *callEl[4];
    callEl[0]=argv[1];  // [0] işlem adı topla, çıkar
    callEl[1]=argv[2];  // [1] verilecek elemanlar
    callEl[2]=argv[3];  // [2] verilecek elemanlar. 
    callEl[3]=NULL;     // liste ya da dizi olunca son eleman null olmalı
    // islem topla 3 4 gibi

    int i;
    pid_t f = fork();  // işlemleri yapmak için bir fork oluşturulur.
                       // process id'ler pid_t tipinde tutulur

    if(strcmp("topla",argv[0]) == 0 || strcmp("cikar", argv[0]) == 0){  
        // burda islem adlarını kontrol amaclı bir koşul yazdım
        if(numCheck(argv[1]) && numCheck(argv[2])){  // islem yapılacak
        // elemanların sayi olup olmadığının kontrolünü yapıyorum
            if(f < 0){   // eger fork 0 dan kucuk olursa exit failure olur
            exit(EXIT_FAILURE);	

            }else if (f == 0){ // 0'a esit ise child process işlemleri yapılır
                i = execv(argv[0], callEl); 
                perror("execv failed\n");
            // gönderilecek parametreler dizi olduğu için execv kullandım

            }else{  // else durumu f > 0 dır ve parent işlemleri yapılır
                wait(&i); // beklmeden sonra işlemin yapılması
            }

        }else{ // burada islem yapilacak elemanların number olmama durumu
            printf("Lutfen sayi giriniz..");
        }
    
    }else{  // burada islemlerin topla veya cikar olmama durumu
        printf("Hatali bir secim yaptiniz..");
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