#include <iostream>

using namespace std;

class cat
{
private:
    /* data */
public:
    cat(/* args */);
    cat( cat &);
    ~cat();

};

cat::cat()
{
    cout << "cat constructor ... \n";
}
cat::cat( cat &)
{
    cout << "cat copy constructor ... \n";
}
cat::~cat()
{
    cout << "cat destructor ... \n";
}

cat FunOne(cat theCat)
{
    cout << "FunOne ...\n";
    return theCat;
}

cat* FunTwo(cat *theCat)
{
    cout << "FunTwo ...\n";
    return theCat;
}

cat& FunThree(cat &theCat)
{
    cout << "FunThree ...\n";
    return theCat;
}

int main(int argc, char const *argv[])
{
    cout << "making a cat ...\n";
    cat Kitty;
    cout << "calling FunOne ...\n";
    FunOne(Kitty);
    cout << "calling FunTwo ...\n";
    FunTwo(&Kitty);
    cout << "calling FunThree ...\n";
    FunThree(Kitty);

    return 0;
}

