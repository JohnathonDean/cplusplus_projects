// #include <iostream>

// class Foo {
// public:
//     static Foo* getInstance() { return &myInstance; }

//     void print();

// private:
//     Foo() { std::cout << "creat Foo" << std::endl; }
//     ~Foo() { std::cout << "~ Foo" << std::endl; }
//     Foo(Foo const &);
//     Foo &operator=(Foo const &);

//     static Foo myInstance;
// };

// // .cpp

// Foo Foo::myInstance;

// void Foo::print() {
//     std::cout << "print Foo" << std::endl;
// }

// int main(int argc, char const *argv[])
// {

//     std::cout << "main start" << std::endl;

//     Foo* sig_a = Foo::getInstance();
//     std::cout << "start print Foo" << std::endl;
//     sig_a->print();

//     return 0;
// }

#include <iostream>
// class Test
// {
// public:
//     Test() { std::cout << "Test()" << std::endl; }
//     static Test *getInstance() { return &t; }
//     static Test *getInstance1() { return new Test(); }

// private:
//     ~Test() { std::cout << "~Test()" << std::endl; }
//     static Test t;
//     static Test *t1;
// };
// Test Test::t;
// Test *t1;
// int main(int argc, const char **argv)
// {
//     t1 = new Test();
//     Test *t2 = new Test();
//     // Test  t3; // compile error
//     // delete t1;   // compile error
//     // delete t2;   // compile error
//     // delete t3;   // compile error
//     return 0;
// }

class Singleton;
class Singleton {
private:
    Singleton() = default;
    Singleton(const Singleton &);

public:
    static Singleton& GetInstance() {
        static Singleton instance;  //C++11标准下local static对象初始化在多线程条件下安全
        return instance;
    }

private:
    //class members
};

int main(int argc, const char **argv)
{
    Singleton::GetInstance();

    return 0;
}
