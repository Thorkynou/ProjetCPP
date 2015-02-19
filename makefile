
CPP = g++
FLAG = -c

banque.out: livretepargne.o comptebloque.o pel.o ecompte.o client.o comptecourant.o date.o main.cpp
	$(CPP) livretepargne.o comptebloque.o pel.o ecompte.o client.o comptecourant.o date.o main.cpp -o banque.out

client.o: client.cpp client.h
	$(CPP) $(FLAG) client.cpp client.h

comptecourant.o: comptecourant.cpp comptecourant.h
	$(CPP) $(FLAG) comptecourant.cpp comptecourant.h

livretepargne.o: livretepargne.cpp livretepargne.h
	$(CPP) $(FLAG) livretepargne.cpp livretepargne.h

comptebloque.o: comptebloque.cpp comptebloque.h
	$(CPP) $(FLAG) comptebloque.cpp comptebloque.h

pel.o: pel.cpp pel.h
	$(CPP) $(FLAG) pel.cpp pel.h

ecompte.o: ecompte.cpp ecompte.h
	$(CPP) $(FLAG) ecompte.cpp ecompte.h

date.o: date.cpp date.h
	$(CPP) $(FLAG) date.cpp date.h

clean:
	rm *.o *.out
