#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>



std::vector<int> plop_alloc(const int number)
{
    std::vector<int> tab(number);
    return tab;
}

void plop_fill(std::vector<int> &tab)
{
    for(unsigned int i=0; i<tab.size(); ++i)
        tab[i] = i;
}

void plop_print(const std::vector<int> &tab)
{
    for(unsigned int i=0; i<tab.size(); ++i)
        std::cout << tab[i] << " ";
    std::cout << std::endl;
}

void plop_loop(std::vector<int> &tab)
{
    for(unsigned int iter=0; iter<10; ++iter){
        for(unsigned int i=0; i<tab.size(); ++i){
            if(iter % 2 == 0)
                tab[i]++;
            else
                tab[i]--;
        }
    }
}

void plop_loop2(std::vector<int> &tab)
{
    for(unsigned int iter=0; iter<20; ++iter){
        for(unsigned int i=0; i<tab.size(); ++i){
            if(iter % 2 == 0)
                tab[i]++;
            else
                tab[i]--;
        }
    }
}


void plop(const int number)
{
    std::vector<int> t = plop_alloc(number);

    plop_fill(t);

    plop_loop(t);

    plop_loop2(t);

    plop_print(t);
}


int main(int argc, char** argv) {

    if(argc != 2){
        std::cout << "usage: " << argv[0] << " number" << std::endl;
        return EXIT_FAILURE;
    }

    const int myNumber = std::stoi(argv[1]);
    std::cout << "number : " << myNumber << std::endl;

    plop(myNumber);

    return EXIT_SUCCESS;
}


// sudo apt-get install valgrind kcachegrind graphviz
// > valgrind --tool=callgrind ./plop 10
// > kcachegrind callgrind.out.xxxx


