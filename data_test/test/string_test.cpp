#include <iostream>
#include <string>
#include <cstring>

int main(int argc, char **argv)
{
     using namespace std;
     string s1 = "penguin";
     string s2, s3;
     string str;

     cout << s2.size() << endl;
     cout << "Enter one line of text:\n";
     getline(cin, str); // cin now an argument; no length specifier
     cout << "You entered: " << str << endl;
     cout << "Length of string in str after input: "
          << str.size() << endl;

     cout << "Enter a kind of feline: ";
     cin >> s2; // use cin for input
     cout << "s1: " << s1 << ", s2: " << s2 << endl;

     cout << "You can assign one string object to another: s3 = s1\n";
     s3 = s1;
     cout << "s3: " << s3 << endl;

     cout << "You can concatenate strings: s3 = s1 + s2\n";
     s3 = s1 + s2;
     cout << "s3: " << s3 << endl;

     cout << "You can append strings.\n";
     s1 += s2;
     cout << "s1 += s2 yields s1 = " << s1 << endl;
     s2 += " for a day";
     cout << "s2 += \" for a day\" yields s2 = " << s2 << endl;

     char charr1[20];
     char charr2[20] = "jaguar";
     string str1;
     string str2 = "panther";

     // assignment for string objects and character arrays
     str1 = str2;            // copy str2 to str1
     strcpy(charr1, charr2); // copy charr2 to charr1

     // appending for string objects and character arrays
     str1 += " paste";         // add paste to end of str1
     strcat(charr1, " juice"); // add juice to end of charr1

     // finding the length of a string object and a C-style string
     int len1 = str1.size();    // obtain length of str1
     int len2 = strlen(charr1); // obtain length of charr1

     cout << "The string " << str1 << " contains "
          << len1 << " characters.\n";
     cout << "The string " << charr1 << " contains "
          << len2 << " characters.\n";
     // cin.get();

     char charr3[] = "abaabaaba";       //9 char
     int char_length = sizeof(charr3) / sizeof(charr3[0]);
     cout << char_length << endl;

     return 0;
}