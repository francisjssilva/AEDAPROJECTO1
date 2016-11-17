/*
 * algorithm

 *
 *  Created on: 10/11/2016
 *      Author: FranciscoSilva
 */
#pragma once
#include <vector>
using namespace std;

template <class Comparable>
int sequentialSearch(const vector<Comparable> &v, Comparable x)
{
    for (unsigned int i = 0; i < v.size(); i++)
        if (v[i] == x)
           return i;   // encontrou
    return -1;     // n�o encontrou
}

 /* ALGORITHM_ */
