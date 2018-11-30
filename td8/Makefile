EXE = output
LDFLAGS = 
CFLAGS  = -Wall -std=c++11
all: ${EXE}

${EXE}: main.o Point3D.hpp Tableau.hpp Error.o
	@echo linking ${EXE} 
	@g++ ${LDFLAGS} -o ${EXE} $^

main.o: main.cpp
	@echo compiling $@ 
	@g++ ${CFLAGS} -c $< -o $@

# Point3D.o: Point3D.hpp
# 	@echo compiling $@ 
# 	@g++ ${CFLAGS} -c $< -o $@

# Tableau.o: Tableau.hpp
# 	@echo compiling $@ 
# 	@g++ ${CFLAGS} -c $< -o $@

Error.o: Error.cpp Error.hpp
	@echo compiling $@ 
	@g++ ${CFLAGS} -c $< -o $@

.PHONY: clean

clean :
	@echo cleaning
	@rm -Rf *.o
