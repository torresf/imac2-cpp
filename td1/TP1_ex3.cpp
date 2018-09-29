#include <iostream>

int main(int argc, char const *argv[])
{
	std::cout << "Veuillez entrer une chaine de caractères :" << std::endl;
	std::string str;
	std::cin >> str;

	std::cout << "String size : " << str.size() << std::endl << "Last element : " << str.back() << std::endl;
	str.pop_back();

	str.insert(0, "IMAC");
	std::cout << str << std::endl;

	return 0;
}