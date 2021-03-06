#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 




int main(){

	char input[100];  // input dizisi
	char *str[100];   //inputtaki string ifadelerin tutulduğu dizi  kelimler
	char *islem[100]; //inputtaki istenen islemşn tutulduğu dizi     komutlar

	int e;   

	while(1){
	printf("myshell>>");
      
        fgets(input,100,stdin);	
    	char *temp;  
        divideSep(input, islem); 
        for(int i = 0; i< length(islem); i++){ 
            divideSpace(islem[i], str); // girileen komut bosluklara bolunur
            if(strcmp(str[0],"exit") == 0){ // eger input exit ise cikis

                exit(0);
            }else if(strcmp(str[0],"tekrar")==0){
              
		    pid_t f = fork(); //Fork yapıyoruz.
		    if(f == 0){ 
		        e = execv("tekrar",str);
			}
		    
		    else{
		        wait(&e); 
		    }
        
            }else if(strcmp(str[0],"ls")==0){
    		        system("/bin/ls");
   	    }else if(strcmp(str[0],"clear") == 0){ // eger input clear ise
                    system("clear");
            }else if(strcmp(str[0],"cat") == 0){ // input cat ise
            	char *catt[3]; 
                catt[0] = "cat";
                catt[1] = str[1]; 
                catt[2] = NULL; 
                pid_t fork1;
                fork1 = fork();
                if(fork1==0){
		            execv("/bin/cat", catt);
                }
            	
            }else if(strcmp(input,"bash")==0){
  		        system("/bin/bash"); 		
  		
  	}       else{
            	calistir(str);
                
            }
        }
        if(exit){
            break;
        }	
	}
	return 0;
}



int length(char *input[]){  // alınan input uzunluğu buna göre for döngusu yazılacaktır
    int length = 0;
    while (input[length] != '\0'){
        length++;
    }
    return length;
}

void divideSpace(char *islem, char **str) { 

    for (int i = 0; i < 100; i++){ 
        str[i] = strsep(&islem, " ");  // yazilan komutu bosluklara boler
        if (str[i] == NULL)  
            break; 
        if (strlen(str[i]) == 0) 
            i--; 
    } 
} 

void divideSep(char *islem, char **str){ 
    int i; 
    for (i = 0; i < 100; i++) { 
        str[i] = strsep(&islem, "|");   // yazzilan komutu | isaretine göre bölme islemi yapara
        if (str[i] == NULL) 
            break; 
        if (strlen(str[i]) == 0) 
            i--; 
    } 
} 


void calistir(char *str[]){ 
    char *argv[4];
    argv[0] = str[1];   // calistirmak icin giirlen komutların
    argv[1] = str[2];   // tutulması icin yeni bir diiziye aktarıyorum
    argv[2] = str[3];
    argv[3] = NULL;
    
    int i; 
    pid_t f= fork();   // yine bir process kopyası için fork oluşturulur
        if(f==0){      // 0'a eşit olması durumunda child islemleri gerçeklesir
            i = execv(str[0], argv);
            if(i < 0){
                printf("Komut yanlis girildi...");
            }
        }
        else{ 
            wait(&i);
        }
} 
