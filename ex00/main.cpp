#include "./include/ScalarConverter.hpp"

int main(int argc, char **argv)
{
    ScalarConverter sc;

    std::cout << "argv test" << std::endl;
    std::cout << "-------------------" << std::endl;
    if (argc == 2){
        sc.convert(argv[1]);
    }
    else{
        std::cout << "Usage: ./convert [value]" << std::endl;
    }

    std::cout << "Hardcoded test" << std::endl;
    std::cout << "-------------------" << std::endl;

    //convert int
    sc.convert("0");
    sc.convert("42");
    sc.convert("-42");

    //convert char
    sc.convert("a");
    sc.convert("z");

    //convert float
    sc.convert("0.0f");
    sc.convert("-4,2f");
    sc.convert("4.2f");

}