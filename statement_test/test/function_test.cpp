#include <iostream>

using namespace std;

void t_print(const char *s1)
{
    // *s1 = 'd';
    // ++s1;
    cout << s1 << endl;
}

int main(int argc, char **argv)
{
    char s0 = 'a';
    t_print(&s0);


    return 0;
}
