#ifndef ZIGZAG_H
#define ZIGZAG_H

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

typedef unsigned char byte;


int zigzag(int n)
{
    return (n << 1)^(n >> 31);
}

int unzigzag(int n)
{
    return ((unsigned int)n >> 1)^(-(n & 1));
}

// compress
void compressInt(int num, vector<byte> &des)
{
    num = zigzag(num);
    while(1){
        if(num & ~(0x7f)){ // there is still data at hight bits
            des.push_back((byte)((num & 0x7f) | 0x80));
            num = (unsigned int)num >> 7;
        }else{
            des.push_back(num & 0x7f);
            break;
        }
    }
}

void compressInt(vector<int> &src, vector<byte> &des)
{
    for(int i=0; i<src.size(); ++i){
        int num = src[i];
        compressInt(num, des);
    }

}


// decompress
int decompressInt(int &k, vector<byte> &src)
{
    int ret = 0;
    int c = 0;
    while(1){
        ret = ret | ((src[k] & 0x7f) << 7*c);
        if((src[k] & 0x80) == 0){
            ++ k;
            break;
        }
        ++ k;
        ++ c;
    }
    return unzigzag(ret);
}

void decompressInt(vector<byte> &src, vector<int> &des)
{
    int n = src.size();
    int k = 0;
    while(k < n){
        int r = decompressInt(k, src);
        des.push_back(r);
    }
}


#endif
