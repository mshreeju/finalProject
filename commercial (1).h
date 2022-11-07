/*#define COMMERCIAL_H_INCLUDED
#ifndef COMMERCIAL_H_INCLUDED
*/
#include<iostream>
#include<vector>
using namespace std;
#include "residental.h"
#include"industrial.h"

class commercial{
   
    public:
    residential p;
    industrial I;
    void updated(vector<node> arr[],node** input,int i);
};
//#endif