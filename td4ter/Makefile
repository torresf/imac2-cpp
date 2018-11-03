EXE = td4_output
LDFLAGS = 
CFLAGS  = -Wall -std=c++11
all: ${EXE}

${EXE}: main.o Rectangle.o Carre.o
	@echo linking ${EXE} 
	@g++ ${LDFLAGS} -o ${EXE} $^

main.o: main.cpp Rectangle.hpp Carre.hpp
	@echo compiling $@ 
	@g++ ${CFLAGS} -c $< -o $@

Carre.o: Carre.cpp Carre.hpp Rectangle.hpp
	@echo compiling $@ 
	@g++ ${CFLAGS} -c $< -o $@

Rectangle.o: Rectangle.cpp Rectangle.hpp
	@echo compiling $@ 
	@g++ ${CFLAGS} -c $< -o $@

.PHONY: clean

clean :
	@echo cleaning
	@rm -Rf *.o
