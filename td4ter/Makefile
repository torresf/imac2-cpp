EXE = td4_output
LDFLAGS = 
CFLAGS  = -Wall -std=c++11
all: ${EXE}

${EXE}: main.o Figure.o Rectangle.o Carre.o Ellipse.o Cercle.o
	@echo linking ${EXE} 
	@g++ ${LDFLAGS} -o ${EXE} $^

main.o: main.cpp Figure.hpp Rectangle.hpp Carre.hpp Ellipse.hpp Cercle.hpp 
	@echo compiling $@ 
	@g++ ${CFLAGS} -c $< -o $@

Figure.o: Figure.cpp Figure.hpp
	@echo compiling $@ 
	@g++ ${CFLAGS} -c $< -o $@

Carre.o: Carre.cpp Carre.hpp Rectangle.hpp
	@echo compiling $@ 
	@g++ ${CFLAGS} -c $< -o $@

Rectangle.o: Rectangle.cpp Rectangle.hpp
	@echo compiling $@ 
	@g++ ${CFLAGS} -c $< -o $@

Cercle.o: Cercle.cpp Cercle.hpp Ellipse.hpp
	@echo compiling $@ 
	@g++ ${CFLAGS} -c $< -o $@

Ellipse.o: Ellipse.cpp Ellipse.hpp
	@echo compiling $@ 
	@g++ ${CFLAGS} -c $< -o $@

.PHONY: clean

clean :
	@echo cleaning
	@rm -Rf *.o
