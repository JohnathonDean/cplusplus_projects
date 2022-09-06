#include <iostream>

using namespace std;


class ClassB {
public:
    ClassB();
    ~ClassB();

};

class mainClassA {
public:
    mainClassA();
    ~mainClassA();

    ClassB *b_a;

};


mainClassA::mainClassA() {
    cout << "make A" << endl;

    b_a = new ClassB;
}

mainClassA::~mainClassA() {
    cout << "destroy A" << endl;
    delete b_a;
}


ClassB::ClassB() {
    cout << "make B" << endl;

}

ClassB::~ClassB() {
    cout << "destroy B" << endl;

}

int main(int argc, char const *argv[])
{
    mainClassA a_main;

    return 0;
}
