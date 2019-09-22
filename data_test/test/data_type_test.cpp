#include <iostream>
#include <climits>

#define ZERO 0      // makes ZERO symbol for 0 value

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    /*整型数据的位数*/
    int n_int = INT_MAX;        // initialize n_int to max int value
    short n_short = SHRT_MAX;   // symbols defined in climits file
    long n_long = LONG_MAX;
	long long n_llong = LLONG_MAX;

    // sizeof operator yields size of type or of variable
    cout << "int is " << sizeof (int) << " bytes." << endl;
    cout << "short is " << sizeof n_short << " bytes." << endl;
    cout << "long is " << sizeof n_long << " bytes." << endl;
    cout << "long long is " << sizeof n_llong << " bytes." << endl;
    cout << endl;

    cout << "Maximum values:" << endl;
    cout << "int: " << n_int << endl;
    cout << "short: " << n_short << endl;
    cout << "long: " << n_long << endl;
    cout << "long long: " << n_llong << endl << endl;

    cout << "Minimum int value = " << INT_MIN << endl;
    cout << "Minimum long value = " << LONG_MIN << endl;
    cout << "Bits per byte = " << CHAR_BIT << endl;
	// cin.get();

    cout << endl << endl;
    /*无符号数*/
    short sam = SHRT_MAX;     // initialize a variable to max value
    unsigned short sue = sam;// okay if variable sam already defined

    cout << "Sam has " << sam << " dollars and Sue has " << sue;
    cout << " dollars deposited." << endl
         << "Add $1 to each account." << endl << "Now ";
    sam = sam + 1;
    sue = sue + 1; 
    cout << "Sam has " << sam << " dollars and Sue has " << sue;
    cout << " dollars deposited.\nPoor Sam!" << endl;
    sam = ZERO;
    sue = ZERO;
    cout << "Sam has " << sam << " dollars and Sue has " << sue;
    cout << " dollars deposited." << endl;
    cout << "Take $1 from each account." << endl << "Now ";
    sam = sam - 1;
    sue = sue - 1;
    cout << "Sam has " << sam << " dollars and Sue has " << sue;
    cout << " dollars deposited." << endl << "Lucky Sue!" << endl;
	// cin.get();

    cout << endl << endl;
    /*整型的显示格式*/
    int chest = 42;     // decimal integer literal
    int waist = 0x42;   // hexadecimal integer literal
    int inseam = 042;   // octal integer literal

    cout << "Monsieur cuts a striking figure!\n";
    cout << "chest = " << chest << " (42 in decimal)\n";
    cout << "waist = " << waist << " (0x42 in hex)\n";
    cout << "inseam = " << inseam << " (042 in octal)\n";
	// cin.get();

    int chest2 = 42;
    int waist2 = 42; 
    int inseam2 = 42;

    cout << "Monsieur cuts a striking figure!"  << endl;
    cout << "chest2 = " << chest2 << " (decimal for 42)" << endl;
    cout << std::hex;      // manipulator for changing number base
    cout << "waist2 = " << waist2 << " (hexadecimal for 42)" << endl;
    cout << std::oct;      // manipulator for changing number base
    cout << "inseam2 = " << inseam2 << " (octal for 42)" << endl;
    cout << std::dec;
    // cin.get();

    cout << endl << endl;
    /*char类型*/
    char ch = 'M';       // assign ASCII code for M to ch
    int i = ch;          // store same code in an int
    cout << "The ASCII code for " << ch << " is " << i << endl;

    cout << "Add one to the character code:" << endl;
    ch = ch + 1;          // change character code in ch
    i = ch;               // save new character code in i
    cout << "The ASCII code for " << ch << " is " << i << endl;

    // using the cout.put() member function to display a char
    cout << "Displaying char ch using cout.put(ch): ";
    cout.put(ch);

    // using cout.put() to display a char constant
    cout.put('!');

    cout << endl << "Done" << endl;
	// cin.get();

    /*转义序列的使用*/
    cout << "\aOperation \"HyperHype\" is now activated!\n";
    cout << "Enter your agent code:________\b\b\b\b\b\b\b\b";
    long code1;
    cin >> code1;
    cout << "\aYou entered " << (long) code1 << "...\n";
    cout << "\aCode verified! Proceed with Plan Z3!\n";
    cout << "\ta\"bc\'d\vasd\\fg\?gh\n";
    cout << std::oct << "\247" << "  " << "\248" << "  " << "\812" << "  \n";
    cout << std::hex << "\x247" << "  " << "\x24" << "  " << "\x24FFFF FFFFFFFFFFFF" << "  \n";
    cout << std::dec;

    return 0;
}