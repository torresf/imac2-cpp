EXE = image
LDFLAGS = 
CFLAGS  = -Wall -std=c++11
all: ${EXE}

${EXE}: main.o ImageRGBu8.o ioPPM.o Filter.o Threshold.o
	@echo linking ${EXE} 
	@g++ ${LDFLAGS} -o ${EXE} $^

main.o: main.cpp ImageRGBu8.hpp ioPPM.hpp
	@echo compiling $@ 
	@g++ ${CFLAGS} -c $< -o $@

ImageRGBu8.o: ImageRGBu8.cpp ImageRGBu8.hpp
	@echo compiling $@ 
	@g++ ${CFLAGS} -c $< -o $@

Filter.o: Filter.cpp Filter.hpp
	@echo compiling $@ 
	@g++ ${CFLAGS} -c $< -o $@

Threshold.o: Threshold.cpp Threshold.hpp Filter.hpp
	@echo compiling $@ 
	@g++ ${CFLAGS} -c $< -o $@

ioPPM.o: ioPPM.cpp ioPPM.hpp ImageRGBu8.hpp
	@echo compiling $@ 
	@g++ ${CFLAGS} -c $< -o $@

.PHONY: clean

clean :
	@echo cleaning
	@rm -Rf *.o
