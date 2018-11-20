#include <iostream>
#include <cstdlib>
#include <string>


void plop_ok(const int number)
{
    int *tab = new int[number];

    tab[number/2] = 42;

    delete[] tab;
}


void plop_not_ok(const int number)
{
    int *tab = new int[number];

    tab[number/2] = 42;
}


void plop_seg_fault()
{
    int *tab = 0;

    std::cout << "plop" << tab[100000000] << std::endl;
}


int main(int argc, char** argv) {

    if(argc != 2){
        std::cout << "usage: " << argv[0] << " number" << std::endl;
        return EXIT_FAILURE;
    }

    const int myNumber = std::stoi(argv[1]);
    std::cout << "number : " << myNumber << std::endl;

    plop_ok(myNumber);

    // plop_not_ok(myNumber);

    plop_seg_fault();

    return EXIT_SUCCESS;
}

// valgrind: compile with -g
// > valgrind --leak-check=yes ./plop 10

// debugger: compile with -g
// > gdb ./plop
// > r 10
// > bt
