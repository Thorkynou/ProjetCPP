
CPP = g++
FLAG = -Wall -Wextra -c

banque.out: livretepargne.o comptebloque.o pel.o ecompte.o client.o comptecourant.o date.o testclient.cpp
	$(CPP) livretepargne.o comptebloque.o pel.o ecompte.o client.o comptecourant.o date.o testclient.cpp -o banque.out

#testclient.out: testclient.cpp date.o client.o comptecourant.o pel.o livretepargne.o ecompte.o
#	$(CPP) testclient.cpp date.o client.o comptecourant.o pel.o livretepargne.o ecompte.o -o testclient.out

client.o: client.cpp client.h
	$(CPP) $(FLAG) client.cpp

comptecourant.o: comptecourant.cpp comptecourant.h
	$(CPP) $(FLAG) comptecourant.cpp

date.o: date.cpp date.h
	$(CPP) $(FLAG) date.cpp

livretepargne.o: livretepargne.cpp livretepargne.h
	$(CPP) $(FLAG) $*.cpp

comptebloque.o: comptebloque.cpp comptebloque.h
	$(CPP) $(FLAG) $*.cpp

pel.o: pel.cpp pel.h
	$(CPP) $(FLAG) pel.cpp

ecompte.o: ecompte.cpp ecompte.h
	$(CPP) $(FLAG) $*.cpp

clean:
	rm *.o

#Mettre a jour
touch:
	#Met a jour les fichier
	@touch *.cpp
