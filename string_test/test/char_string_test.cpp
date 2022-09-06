#include <iostream>
#include <string>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    char dog[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', '\0'};
    char cat[8] {'a', 'b', 'c', 'd', '\0', 'e', 'f', '\0'};
    char pig[] = "Bubbles";
    std::string cat1 = cat;
    cout << dog << "   " << strlen(dog) << "   sizeof dog  " << sizeof dog << endl;
    cout << cat << "   " << strlen(cat) << "   sizeof cat  " << sizeof cat << endl;
    cout << "sizeof(cat1)" << sizeof cat1 << "   size"   << "    " << cat1.size() << endl;
    cout << "sizeof(pig)" << sizeof pig << "   size"   << "    " << strlen(pig) << endl;

    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];
    cout << "Enter your name:\n";
    cin.getline(name, ArSize);  // reads through newline
    cout << "Enter your favorite dessert:\n";
    cin.getline(dessert, ArSize);
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";

    char name1[ArSize];
    char dessert1[ArSize];
    cout << "Enter your name:\n";
    cin.get(name1, ArSize);    // read string, newline
    cin.get();
    cout << "Enter your favorite dessert:\n";
    cin.get(dessert1, ArSize).get();
    cout << "I have some delicious " << dessert1;
    cout << " for you, " << name1 << ".\n";

    cout << "What year was your house built?\n";
    int year;
    cin >> year;
    cin.get();      //or    (cin >> year).get();
    cout << "What is its street address?\n";
    char address[80];
    cin.getline(address, 80);
    cout << "Year built: " << year << endl;
    cout << "Address: " << address << endl;
    cout << "Done!\n";
    // cin.get();


    return 0;
}