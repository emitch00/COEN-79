//
//  lab1part1.cpp
//  Lab1
//
//  Created by michael joseph canniffe on 4/9/18.
//  Copyright © 2018 SCU. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <iomanip>

using namespace std;


//displays the numbers 0-9 in multiple patterns
void display_pattern(){
    std::string string1="0123456789";
    std::string string2="9876543210";
    
    std::cout << string1 << std::endl;
    std::cout << setw(string1.length()+1) << string2 << setw(string1.length()+9)<< string1<< std::endl;
    std::cout << setw(string1.length()+3) << string2 << setw(string1.length()+11)<< string1<< std::endl;
    std::cout << setw(string1.length()+5) << string2 << setw(string1.length()+13)<< string1<< std::endl;
    std::cout << setw(string1.length()+7) << string2 << setw(string1.length()+15)<< string1<< std::endl;
    std::cout << setw(string1.length()+9) << string2 << std::endl;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    display_pattern();
    
    
    
    return 0;
}




