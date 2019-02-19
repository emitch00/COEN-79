//
//  random.cpp
//  Lab2
//
//  Created by michael joseph canniffe on 4/16/18.
//  Copyright © 2018 SCU. All rights reserved.
//

#include "random.h"

namespace coen79_lab2{

    //this function takes in 4 numbers and assigns them to the 4 variables so that the can be used to find a random variable
    rand_gen::rand_gen(int s, int m, int i, int mod){
         multiplier = m;
         seed =s;
         increment = i;
         modulus = mod;
    }
    
    //finds the next value of the seed
    double rand_gen::next(){
        
        seed = (multiplier * seed + increment) % modulus;
        return seed;
    }
    //sets the new value of the seed
    void rand_gen::set_seed(double x){
        seed = x;
        
    }
    //prints out the value of the 4 variables after each loop
    void rand_gen::print_info(){
        cout<< "seed:"<< rand_gen::seed << endl;
        cout<< "Multiplier:"<< rand_gen::multiplier << endl;
        cout<< "Increment:"<< rand_gen::increment << endl;
        cout<< "Modulus:"<< rand_gen::modulus << endl;


        
    }


}