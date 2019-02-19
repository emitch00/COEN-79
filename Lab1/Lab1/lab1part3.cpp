//
//  main.cpp
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
#include <fstream>

using namespace std;


//traverses a file twice, the first time it removes all the punctuation,
//the second time it capitlaizes all the letters in any string longer than 9 and prints out those words
void gettysburg(char * argv){
    int i = 0;
    ifstream myfile;
    string temp;
    myfile.open(argv);

    while(myfile >> temp){
        //removing punctuation
        for(i=0;i<temp.length();i++){
            if(ispunct(temp[i])){
                temp.erase(i,1);
            }
        }
        if(temp.length()>9){
            //capitalizing
            for(i=0;i<temp.length();i++){
                temp[i]= toupper(temp[i]);
            }
            //returning outputs
            cout << temp << endl;
        }
    }
}




int main(int argc,  char * argv[]) {
    // insert code here...
    if(argc !=2){
        cout << "need 2 arguments" << endl;
    
        return 0;
    }
    gettysburg(argv[1]);

    
    return 0;
}

