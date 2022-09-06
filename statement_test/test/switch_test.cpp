#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int score = 95;
    if(score >= 10)
        if(score <= 90)
            cout << "Print first case1" << endl;
    else    //悬垂else与最近的一个尚未匹配的if匹配
        cout << "Print first case2" << endl;

    if(score >= 10) {
        if(score <= 90)
            cout << "Print second case1" << endl;
    } else
        cout << "Print second case2" << endl;

    unsigned aCnt = 0, bCnt = 0, cCnt = 0, dCnt = 0, eCnt = 0;
    char str[] = "abcvbzvkjbvzvcsjhdgeyekbaj";  //字符串数组末尾会加入隐藏空字符'\0'
    char *str1 = "qwer";
    str1 = str;
    char *pbeg = begin(str), *pend = end(str);
    while(pbeg != pend){
        // cout << *pbeg << endl;
        switch (*pbeg)
        {
        case 'a':
            ++aCnt;
            cout << "out of case11a" << endl;
            break;  //不加入break会导致后面的每个case都会进入执行
        case 'b':
            ++bCnt;
            cout << "out of case11b" << endl;
            break;
        case 'c':
            ++cCnt;
            cout << "out of case11c" << endl;
            break;
        case 'd':
            ++dCnt;
            cout << "out of case11d" << endl;
            break;
        case 'e':
            ++eCnt;
            cout << "out of case11e" << endl;
            break;
        default:
            // cout << *pbeg << endl;
            break;
        }
        ++pbeg;
    }
    cout << "Number of a : " << aCnt << '\n'
        << "Number of b : " << bCnt << '\n'
        << "Number of c : " << cCnt << '\n'
        << "Number of d : " << dCnt << '\n'
        << "Number of e : " << eCnt << endl;


    return 0;
}
