
CPP = g++
FLAG = -Wall -Wextra -c

banque.out: livretepargne.o comptebloque.o pel.o ecompte.o client.o comptecourant.o operation.o date.o gestion_menu.o main_menu.cpp
	$(CPP) livretepargne.o comptebloque.o pel.o ecompte.o client.o comptecourant.o operation.o date.o gestion_menu.o main_menu.cpp -o banque.out

client.o: client.cpp client.h
	$(CPP) $(FLAG) client.cpp

gestion_menu.o: gestion_menu.cpp gestion_menu.h
	$(CPP) $(FLAG) gestion_menu.cpp

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

operation.o: operation.cpp operation.h
	$(CPP) $(FLAG) operation.cpp

clean:
	rm *.o

#Mettre a jour
touch:
	#Met a jour les fichier
	@touch *.cpp
