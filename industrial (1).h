/*#define INDUSTRIAL_H_INCLUDED
#ifndef INDUSTRIAL_H_INCLUDED
*/
#ifndef INDUSTRIAL_H_INCLUDED
#define INDUSTRIAL_H_INCLUDED
#include<iostream>
#include<vector>
using namespace std;
#include"node.h"
#include"residental.h"

class industrial{
    
    public:
        residential r;
       static int availableGoods;
        void updated(vector<node> arr[],node** input,int i);
};
#endif