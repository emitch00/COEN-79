//
//  statistician.h
//  Lab2
//
//  Created by michael joseph canniffe on 4/16/18.
//  Copyright © 2018 SCU. All rights reserved.
//

#ifndef statistician_h
#define statistician_h

#include <stdio.h>
namespace coen79_lab2{
    
class statistician{
    
public:
    statistician();
    void next(double x);
    int length();
    double sum();
    double mean();
    double maximum();
    double minimum();
    void reset();
    friend statistician operator + (statistician, statistician);
    friend statistician operator * (double, statistician);
    private:
    int seqLen = 0;
    double seqSum = 0.0;
    double seqMin = 0.0;
    double seqMax = 0.0;
    
    
};
bool operator == ( statistician &a, statistician &b);
    


}

#endif /* statistician_h */




