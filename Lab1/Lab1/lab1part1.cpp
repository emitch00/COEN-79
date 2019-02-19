//
//  test.cpp
//  Lab1
//
//  Created by michael joseph canniffe on 4/9/18.
//  Copyright © 2018 SCU. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <iomanip>

using namespace std;


//this function counts the number of the alphanumeric characters and non alphanumeric characters in the users input
void counter(){
    int alpha =0;
    int notAlpha =0;
    int i;
    
    printf("Please enter a phrase or word:\n>");
    std::string input;
    getline(std::cin,input);
    
    int j= input.length();
    for(i=0;i<j;i++){
        if(isalnum(input[i])){
            alpha++;
        }
        else if(isalnum(input[i])==0 && input[i] !=' '){
            notAlpha++;
        }
    }
    std::cout << "the inputed string has" << alpha << " alphanumeric characters and "<< notAlpha << " non alphanumeric characters\n";
}

