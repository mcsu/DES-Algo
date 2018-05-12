#include <iostream>
#include "data_tables.h"
#include "bit_tables.h"
#include "permutations.h"
#include "data_messages_examples.h"
using namespace std;

int main() {

    char *init= new char[64];
    init = testResult;
    displayBitTable(init,64);
    displayAsHex(init,64);
    //生成子key
    char **kn=new char *[48];
    kn = generateSubKey(testKey);


    char *firstperm;


//初始变换
    firstperm=permute(testResult,init_perm,64);

    displayBitTable(firstperm,64);
    displayAsHex(firstperm,64 );

    cout<<"========="<<endl;

//分成L0R0
    char *l0,*r0;
    cout<<"l0r0"<<endl;;
    l0=makeLR0(firstperm,32,0);
    r0=makeLR0(firstperm,32,1);


    char *r1,*l1,*r2,*l2,*r3,*l3,*r4,*l4,*r5,*l5,*r6,*l6,*r7,*l7,*r8,*l8
    ,*r9,*l9,*r10,*l10,*r11,*l11,*r12,*l12,*r13,*l13,*r14,*l14,*r15,*l15,*r16,*l16;
    l1=r0;
    r1=xOR(l0,f(r0,kn[15],0),32);
    displayBitTable(l1,32);
    displayBitTable(r1,32);


    l2=r1;
    r2=xOR(l1,f(r1,kn[14],0),32);
    l3=r2;
    r3=xOR(l2,f(r2,kn[13],0),32);
    l4=r3;
    r4=xOR(l3,f(r3,kn[12],0),32);
    l5=r4;
    r5=xOR(l4,f(r4,kn[11],0),32);
    l6=r5;
    r6=xOR(l5,f(r5,kn[10],0),32);
    l7=r6;
    r7=xOR(l6,f(r6,kn[9],0),32);
    l8=r7;
    r8=xOR(l7,f(r7,kn[8],0),32);
    l9=r8;
    r9=xOR(l8,f(r8,kn[7],0),32);
    l10=r9;
    r10=xOR(l9,f(r9,kn[6],0),32);
    l11=r10;
    r11=xOR(l10,f(r10,kn[5],0),32);
    l12=r11;
    r12=xOR(l11,f(r11,kn[4],0),32);
    l13=r12;
    r13=xOR(l12,f(r12,kn[3],0),32);
    l14=r13;
    r14=xOR(l13,f(r13,kn[2],0),32);
    l15=r14;
    r15=xOR(l14,f(r14,kn[1],0),32);
    l16=r15;
    r16=xOR(l15,f(r15,kn[0],0),32);

    cout<<"r16l16"<<endl;
    displayBitTable(l16,32);
    displayBitTable(r16,32);
    char* reser = reserve(l16,r16,32);
    cout<<"R16L16"<<endl;
    displayBitTable(reser,64);
    char *finalRe = permute(reser,reverse_perm,64);
    cout<<"final"<<endl;
    displayBitTable(finalRe,64);
    displayAsHex(finalRe,64);

    return 0;
}