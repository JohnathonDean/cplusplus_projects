#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int namein(char *nptr[])
{
    int n, num=0;
    char *p, name[100];
    char choice ='Y';
    while (choice == 'Y')
    {
        cin >> name;
        n = strlen(name);
        p = new char [n+1];
        strcpy(p,name);
        nptr[num++] = p;
        cout << "continue? (Y/N)" << endl;
        cin >> choice;
    }
    return num;
}

void sort(char *v[], int n)
{
    int i,j;
    char *t;
    for(j=1;j<n;j++)
    {
        for(i=0;i<n-j;i++)
        {
            if(strcmp(v[i], v[i+1]) > 0)
            {
                t = v[i];
                v[i] = v[i+1];
                v[i+1] =t;
            }
        }
    }
}

void nameout(char **nameptr, int n)
{
    cout << "number: " << n << endl;
    cout << "result: " << endl;
    while(--n >= 0)
    {
        cout << *nameptr++ << endl;
    }

}


int main(int argc, const char** argv) {
    int num;
    char *nameptr[200];
    num = namein(nameptr);
    sort(nameptr, num);
    nameout(nameptr, num);

    return 0;
}