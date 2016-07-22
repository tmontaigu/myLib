#include "MathUtilities.hpp"

#include <iostream>
#include <vector>
#include <map>

#include <stddef.h>

using namespace std;
using namespace MathUtilities;

typedef struct x {
    int member_a;
    double member_b;
} x;

int main(int argc, char **argv) {
    
    int valueInt[4] = {4,4,4,4};
    int meanInt;
    meanInt = ComputeMean(valueInt, 4);
    cout << "Computed Meand: " << meanInt << endl;

    vector<double> a;
    a.push_back(2.2);
    a.push_back(2.2);

    cout << "Computed Mean Vector(2.2,2.2) " << ComputeMean(a) << endl;
    cout << "Computed MeanDeviation Vector(2.2,2.2) " << ComputeMeanDeviation(a) << endl;
    cout << "Computed StandardDeviation Vector(2.2,2.2) " << ComputeStandardDeviation(a) << endl;



    typedef map<int, x> hh;
    
    hh h;
    
    x xx = { 11,2.2 };
    x yy = { 33,2.2 };

    h[1] = xx;
    h[2] = yy;


    //test_test(h);
    
    //test_test2(h,xx, xx.member_a);
    x zz;
    double mean  = ComputeMean(h, zz.member_b, offsetof(x, member_b));
    double  meanDev  = ComputeMeanDeviation(h, zz.member_b, offsetof(x, member_b));
    double  stdDev  = ComputeStandardDeviation(h, zz.member_b, offsetof(x, member_b));
    cout << " mean : " << mean << endl;
    cout << " mean deviation " << meanDev << endl;
    cout << " standard deviation " << stdDev << endl;

}
