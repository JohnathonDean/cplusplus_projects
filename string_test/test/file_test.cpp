#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

int main(int argc, char **argv)
{
    std::string a = "asfg";
    std::string b = "sfgg";

    std::ofstream outfile;
    outfile.open("/home/johnathon/mytest.txt", std::ios::app);

    outfile << a << std::endl;

    outfile.close();

    return 1;
}