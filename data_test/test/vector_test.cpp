#include <iostream>
#include <string>
#include <vector>
#include <cstring>


void test()
{
    std::vector<int8_t> a;
    std::cout << "max_size" << a.max_size() << std::endl;


    long m,n;
    m = 80000 + rand() % (120000 - 80000 +1);
    n = 80000 + rand() % (120000 - 80000 +1);
    std::cout << "[" << m << "," << n << "]" << m*n << std::endl;

    a.resize(m * n);

}

int main(int argc, char **argv)
{

    while (1)
    {
        test();
    }

    return 0;
}