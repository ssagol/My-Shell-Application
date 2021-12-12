program: myShell tekrar islem topla cikar

myShell:
	gcc myShell.c -o myShell	
tekrar:
	gcc tekrar.c -o tekrar
islem:
	gcc islem.c -o islem
topla:
	gcc topla.c -o topla
cikar:
	gcc cikar.c -o cikar

clean:
	rm -f *.o myShell tekrar islem topla cikar
