EXE = output
LDFLAGS = 
CFLAGS  = -Wall -std=c++11
all: ${EXE}

${EXE}: main.o Majuscule.o AjoutSiPair.o
	@echo linking ${EXE} 
	@g++ ${LDFLAGS} -o ${EXE} $^

main.o: main.cpp
	@echo compiling $@ 
	@g++ ${CFLAGS} -c $< -o $@

Majuscule.o: Majuscule.cpp Majuscule.hpp
	@echo compiling $@ 
	@g++ ${CFLAGS} -c $< -o $@

AjoutSiPair.o: AjoutSiPair.cpp AjoutSiPair.hpp
	@echo compiling $@ 
	@g++ ${CFLAGS} -c $< -o $@

.PHONY: clean

clean :
	@echo cleaning
	@rm -Rf *.o
