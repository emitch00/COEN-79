//
//  mystring.cpp
//  Lab5
//
//  Created by michael joseph canniffe on 5/7/18.
//  Copyright © 2018 SCU. All rights reserved.
//

#include "mystring.h"
#include <assert.h>
#include <stdio.h>

using namespace std;
using namespace coen79_lab5;

namespace coen79_lab5 {
    
    string::string(const char str[]){
        current_length = strlen(str);
        allocated = current_length+1;
        characters = new char[allocated];
        strncpy(characters, str,strlen(str));
        
    }
    
    string::string(char c){
        current_length = 1;
        allocated = 2;
        characters = new char[2];
        characters[0] = c;
        characters[1] = '\0';
    }
    
    string::string(const string& source){
        current_length = source.current_length;
        allocated = source.allocated;
        characters = new char[source.length()+1];
        strncpy(characters, source.characters,source.length());
    }
    
    string::~string(){
        current_length = 0;
        allocated = 0;
        delete[] characters;
    }
    
    void string::reserve(size_t n){
        if (n <=allocated) {
            return;
        }
        else{
            char *tmp_characters = new char [n];
            strncpy(tmp_characters,characters,length());
            characters=NULL;
            allocated = n;
            characters = tmp_characters;
        }
    }
 
    std::istream& operator >> (std::istream& ins, string& target){
        while(ins.eof() == false && isspace(ins.peek())){
            
            ins.ignore();
        }
        char next;
        while (ins.eof() == false && !isspace(ins.peek())) {
            ins >> next;
            target += next;
        }
        
        return ins;
    }
    
    
    string& string::operator =(const string& source){
       reserve(source.length()+1);
       current_length = source.length();
        
        strncpy(characters, source.characters, strlen(source.characters));
        return  *this;
    }
    
    void string::insert(const string& source, unsigned int position){
        assert(position<=length());
        reserve(source.length());
        current_length += source.length();
        for (size_t i =length(); i>position; i--) {
            characters[source.length()+i] = characters[i];
        }
        for (int j = 0; j>source.length(); j++) {
            characters[position+j] = source[j];
        }
    }
    
    
    void string::dlt(unsigned int position, unsigned int num){
        assert((position + num) <= length( ));
        int j = position;
        size_t size = num;
        for (int i =position+num; i<current_length; i++) {
            characters[j]=characters[i];
            j++;
        }
        current_length = current_length-size;
    }
    
    void string::replace(char c, unsigned int position){
        assert(position < length());
        characters[position] = c;
        
    }
    void string::replace(const string& source, unsigned int position){
        assert((position + source.length()) <= length());
        for (int i = position; i<source.length(); ++i) {
            characters[position+1] = source[i];
        }
        
    }

    char string::operator [ ](size_t position) const{
        assert(position<length());
        return characters[position];
    }

        
    int string::search(char c) const{
        for (int i = 0; i<length(); ++i) {
            if (characters[i]== c) {
                return i;
            }
        }
        return -1;
    }
    int string::search(const string& substring) const{
        int i =0;
        while (characters[i] != '\0') {
            if (characters[i] == substring[0]) {
                bool flag = true;
                for (size_t j =0; j<substring.length(); j++) {
                    if (characters[i+j] != substring[j]) {
                        flag = false;
                        j=substring.length();
                    }
                }
                if (flag==true) {
                    return i;
                }
            }
            i++;
        }
        return -1;
        
    }
    unsigned int string::count(char c) const{
        int i = 0;
        int counter =0;
        while (characters[i] != '\0') {
            if (characters[i] == c) {
                counter++;
            }
            i++;
        }
        return counter;
    }

    
    
    void string::operator +=(const string& addend){
       
        reserve(length() +addend.length()+1);
        strncat(characters, addend.characters, strlen(addend.characters));
        current_length = current_length + addend.length();
        
    }
    void string::operator +=(const char addend[ ]){
        
        assert(addend[strlen(addend)]=='\0');
        
        size_t addLen = strlen(addend);
        reserve(length()+addLen +1);
        current_length = current_length + strlen(addend);
        strncat(characters, addend, strlen(addend));

        
    }
    void string::operator +=(char addend){
        reserve(length()+1);
        size_t i =length();
        characters[i]=addend;
        current_length += 1;
        
    }

    
    string operator +(const string& s1, const string& s2){
        string tmp;
        tmp+=s1;
        tmp+=s2;
        return tmp;
    }
    
    string operator +(const string& s1, const char addend[ ]){
        string tmp;
        tmp+=s1;
        tmp+=addend;
        return tmp;
    }

    
    
    
    
    
    
    std::ostream& operator <<(std::ostream& outs, const string& source){
        outs << source.characters;
        return outs;
    }
    

    bool operator ==(const string& s1, const string& s2){
        return (strcmp(s1.characters, s2.characters)==0);
    }
    bool operator !=(const string& s1, const string& s2){
        return (strcmp(s1.characters, s2.characters)!=0);
    }
    bool operator > (const string& s1, const string& s2){
        if (strcmp(s1.characters, s2.characters)==1) {
            return 1;
        }
        return 0;
    }
    bool operator < (const string& s1, const string& s2){
        if (strcmp(s1.characters, s2.characters)== -1) {
            return 1;
        }
        return 0;
    }
    bool operator >=(const string& s1, const string& s2){
        if (strcmp(s1.characters, s2.characters)== -1) {
            return 0;
        }
        return 1;
    }
    bool operator <=(const string& s1, const string& s2){
        if (strcmp(s1.characters, s2.characters)==1) {
            return 0;
        }
        return 1;

    }

    
    
    
    
    
    
    
    
    
    
    
    
}