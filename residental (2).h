/*#define RESIDENTAL_H_INCLUDED
#ifndef RESIDENTAL_H_INCLUDED
*/
#ifndef RESIDENTAL_H_INCLUDED
#define RESIDENTAL_H_INCLUDED

#include<iostream>
#include<vector>
using namespace std;
#include"node.h"

class residential{
    
    
     
     public:
    static int availableWorkers;
    void updated(vector<node> arr[],node** input,int i);
};
#endif