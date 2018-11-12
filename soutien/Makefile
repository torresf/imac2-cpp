EXE = output
LDFLAGS = 
CFLAGS  = -Wall -std=c++11
all: ${EXE}

${EXE}: main.o Personnage.o Guerrier.o Mage.o
	@echo linking ${EXE} 
	@g++ ${LDFLAGS} -o ${EXE} $^

main.o: main.cpp
	@echo compiling $@ 
	@g++ ${CFLAGS} -c $< -o $@

Personnage.o: Personnage.cpp Personnage.hpp
	@echo compiling $@ 
	@g++ ${CFLAGS} -c $< -o $@

Guerrier.o: Guerrier.cpp Guerrier.hpp Personnage.hpp
	@echo compiling $@ 
	@g++ ${CFLAGS} -c $< -o $@

Mage.o: Mage.cpp Mage.hpp Personnage.hpp
	@echo compiling $@ 
	@g++ ${CFLAGS} -c $< -o $@

.PHONY: clean

clean :
	@echo cleaning
	@rm -Rf *.o
