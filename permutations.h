//
// Created by 苏浩 on 2017/11/27.
//

#ifndef DES_ALGORI_PERMUTATIONS_H
#define DES_ALGORI_PERMUTATIONS_H
char* permute(char *, char *, long);
char* makeLR0(char *table, long tabsize,int type);
char* expand(char *table, char *E,int tableSize);
char* f(char *data,char *k,int fois);//一个32位的数据区块和一个48位的秘钥区块Kn
char* key_shift(char *table, int keyshift, int tableSize);
char* testF(char *table);
char* xOR(char *table1,char *table2,int tableSize);
char** generateSubKey(char *table);
char* reserve(char *he,char *her,int tabsize);

#endif //DES_ALGORI_PERMUTATIONS_H
