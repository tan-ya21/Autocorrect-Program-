#include<iostream>
#include<string.h>

using namespace std;
int const l = 200;

int main()
{
    cout<<"Enter the sequence you want to fix or check the grammar of: ";
    int d1=0, d2=0;
    char a[l];
    cin.getline(a,l);
    int d = strlen(a);
    for(int i=0; i<d; i++)
    {
        if(a[i] == '.')
            a[i+1] = toupper(a[i+1]);
        if(a[i] == '(')
            d1 = 1;
        if(a[i] == ')')
            d2 = 1;
        if(a[i] == '.' && a[i+1] != ' ')
        {
            d++;
            for(int j=d-1; j>i; j--)
                a[j] = a[j-1];
            a[i+1] = ' ';
        }
        if(a[i] == ',' && a[i+1] != ' ')
        {
            d++;
            for(int j=d-1; j>i; j--)
                a[j] = a[j-1];
            a[i+1] = ' ';
        }
        if(a[i] == '?' && a[i+1] == ' ')
        {
            d++;
            for(int j=d-1; j>i; j--)
                a[j] = a[j-1];
            a[i+1] = ' ';
        }
        bool p = !(a[i] == ' ' && a[i+1] == ' ');
        bool r = !(ispunct(a[i]) && ispunct(a[i+1]));
        if(a[i-1] != ' ' && a[i+1] != ' ' && isupper(a[i]))
            a[i] = tolower(a[i]);
        a[0] = toupper(a[0]);
        if(p && r)
            cout<<a[i];
    }
    if(a[d-2] != '.')
        cout<<'.';
    if(d1 == 1 && d2 == 0)
    cout<<"\nThe sentence has an unclosed bracket";
    if(d1 == 0 && d2 == 1)
    cout<<"\nThe sentence has an unopened bracket";
    return 0;
}