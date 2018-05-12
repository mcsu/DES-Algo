#include "permutations.h"
#include "string.h"
#include "data_tables.h"
#include "bit_tables.h"
#include <iostream>
#include <Math.h>
#include <bitset>
using namespace std;
//
// Created by 苏浩 on 2017/11/27.
//

char* permute(char *table, char *perm_table, long tabsize)
{
    char *result = new char[tabsize];

    for(int i=0; i <tabsize;i++)
    {
        result[i]=table[(int)perm_table[i]-1];
    }

    return result;
}

char* convert(int fdata) {
    char *result = new char[4];
    int c[4] = {0}, count;
    count = 0;
    for(int i = 0; fdata > 0; i++){
        c[i] = fdata%2;
        fdata = fdata/2;
        count++;
    }
    for(int j = count; j > 0; j--) {
        result[4-j] = c[j-1];
    }
    return  result;
}

char* makeLR0(char *table, long tabsize,int type)//偶数代表L，奇数代表R
{
    char *result = new char[tabsize];
    int i;
    if(type%2==0)
    {
        for (i = 0; i < tabsize; ++i) {
            result[i]=table[i];
        }
    }
    else
    {
        for (i = tabsize-1; i < tabsize + tabsize-1; ++i) {
            result[i-tabsize+1]=table[i+1];
        }
    }
    return result;
}

char* expand(char *table, char *E,int tableSize)
{
    char *result = new char[tableSize];

    for(int i=0; i <tableSize;i++)
    {
        result[i]=table[(int)E[i]-1];
    }

    return result;
}

char* f(char *data,char *k,int fois)//一个32位的数据区块和一个48位的秘钥区块Kn 特别难
{
    char *exData = new char[48];
    exData = expand(data,expansion_table,48);
    char *xorData = new char[48];
    xorData = xOR(exData,k,48);



//s-box addr
    char *addr1 = new char[16];
    char *addr2 = new char[32];

    for(long i=0; i < 48;i++)
    {
        if(i%6==0)
        {
            addr1[i/3] = (int)*(xorData+i);
        }
        else if((i+1)%6==0)
        {
            addr1[(i-5)/3+1] = (int)*(xorData+i);
        }
        else
        {
            addr2[(i/6)*4+i%6-1] = (int)*(xorData+i);
        }
    }
    char *sBoxData = new char[32];
    for (int i = 0; i <8 ; ++i) {
        int result;
       result = s_boxes[i][    (addr1[i*2]*2+addr1[i*2+1])*16+   addr2[i*4]*8+   addr2[i*4+1]*4+  addr2[i*4+2]*2+  addr2[i*4+3]       ];
     //correct

        for (int j = 0; j <4 ; ++j) {
            sBoxData[i*4+j]= (int)convert(result)[j];

        }
        //dele
    }


    char* finalResult = permute(sBoxData,permut_32,32);
    delete[]sBoxData;


    return  finalResult;
    //cout<<(int)*(xorData+2);




}

char* key_shift(char *table, int tableSize, int keyshift)
{
    char *result = new char[tableSize+keyshift];//新建字符串

    memcpy(result,table,tableSize);//复制字符串


    for(int i=0; i <keyshift;i++)//复制头部
    {
        result[i+tableSize] = result[i];
    }

    for(int i=0; i <tableSize;i++)//移位
    {
        result[i] = result[i+keyshift];
    }
    return  result;
}
char* xOR(char *table1,char *table2,int tableSize)
{
    char *result = new char[tableSize];
    for (int i = 0; i < tableSize; ++i) {
        result[i]=table1[i]^table2[i];
    }
    return  result;
}

char** generateSubKey(char *table)
{

    char *keyPlus = new char[56];
    keyPlus = permute(table,pc_1,56);

    char *l0 = new char[28];
    char *r0 = new char[28];
    l0 = makeLR0(keyPlus,28,0);
    r0 = makeLR0(keyPlus,28,1);

    //创建二维
    char **subKeys=new char *[56];//释放delete[]p[i];
    for (int i = 0; i <16 ; ++i) {
        subKeys[i]=new char[28];
        subKeys[i]=key_shift(l0,28,keyshift[i]);
        for (int j = 0; j <28 ; ++j) {
            subKeys[i][j + 28] = key_shift(r0, 28, keyshift[i])[j];//correct
        }
    }

    char **kn=new char *[48];//释放delete[]p[i];
    for (int i = 0; i <16 ; ++i) {
        kn[i]=new char[i];
        kn[i]=permute(subKeys[i],pc_2,48);//subKey pour 16 fois
        delete[]subKeys[i];

    }
    //这都能写出来 真牛逼

    return kn;
}

char* reserve(char *he,char *her,int tabsize)
{
    char *result = new char[tabsize*2];
    for (int i = 0; i <tabsize ; ++i) {
        result[i] = her[i];

    }
    for (int i = 0; i <tabsize ; ++i) {
        result[i+tabsize] = he[i];
    }

    return  result;
}
