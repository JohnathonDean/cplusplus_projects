#include <iostream>

using namespace std;

int main()
{
    bool a_true_ = true;
    bool a_false_ = false;

    bool a = -2;
    bool b = 0;
    bool c = 3;

    if(a == a_false_){
        cout << "a = false" << endl;
    }else{
        cout << "a = true" << endl;
    }

    if(a){
        cout << "a is true" << endl;
    }else{
        cout << "a is false" << endl;
    }
    if(b){
        cout << "b is true" << endl;
    }else{
        cout << "b is false" << endl;
    }
    if(c){
        cout << "c is true" << endl;
    }else{
        cout << "c is false" << endl;
    }

    return 1;
}
