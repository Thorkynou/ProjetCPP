
CPP = g++
FLAG = -c

banque.out: livretepargne.o comptebloque.o pel.o ecompte.o client.o comptecourant.o main.cpp
	$(CPP) $^ main.cpp -o banque.out

client.o: client.cpp client.h
	$(CPP) $(FLAG) $*.cpp

comptecourant.o: comptecourant.cpp comptecourant.h
	$(CPP) $(FLAG) $*.cpp

livretepargne.o: livretepargne.cpp livretepargne.h
	$(CPP) $(FLAG) $*.cpp

comptebloque.o: comptebloque.cpp comptebloque.h
	$(CPP) $(FLAG) $*.cpp

pel.o: pel.cpp pel.h
	$(CPP) $(FLAG) $*.cpp

ecompte.o: ecompte.cpp ecompte.h
	$(CPP) $(FLAG) $*.cpp

clean
	rm *.o *.out