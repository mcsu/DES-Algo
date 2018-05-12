//
// Created by 苏浩 on 2017/11/27.
//

#include <iostream>

using namespace std;

void displayBitTable(char *table, long tabsize)
{
    for(long i=0; i < tabsize;i++)
    {
        cout << (int)table[i];

        if(((i+1)%4)==0)
        {
            cout << " ";
        }
    }
    cout << endl;
}

void displayAsHex(char *table, long tabsize)
{
    long hexsize = tabsize/4;

    char hexcodes[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

    for (long i=0; i < hexsize;i++)
    {
        long value=0;

        for(long j=0; j <4; j++)
        {
            value = (2*value)+table[4*i+j];
        }

        cout << hexcodes[value];

        if(((i+1)%4)==0)
        {
            cout << " ";
        }
    }

    cout << endl;
}

