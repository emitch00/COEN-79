//
//  sequence1.cpp
//  Lab3
//
//  Created by michael joseph canniffe on 4/23/18.
//  Copyright © 2018 SCU. All rights reserved.
//

#include "sequence1.h"
#include <assert.h>
using namespace coen79_lab3;

namespace coen79_lab3{
    void sequence::start(){
        current_index = 0;
    }
    void sequence::end(){
        current_index = used-1;
    }
    void sequence::last(){
    current_index = CAPACITY - 1;
    }
    sequence::value_type sequence::current() const{
        assert(is_item());
        return data[current_index];
        
    }
    void sequence::advance(){
         if (is_item()&&(current_index!=used)) {
             current_index++;
         }
    }
    void sequence::retreat(){
         if (is_item()&&(current_index!=0)) {
             current_index--;
         }
    }


    void sequence::insert(const value_type& entry){
        if (size() < CAPACITY) {
            if (!is_item()) {
                current_index=0;
            }
            for (size_type i =used; i>current_index; i--) {
                data[i] = data[i-1];
            }
            data[current_index] = entry;
            used++;
        }
    }
    void sequence::attach(const value_type& entry){
        if (size() < CAPACITY) {
            if (!is_item()) {
                data[used] = entry;
                current_index = used;
                used++;
            }
            else{
                for(size_type i =used; i>current_index; i--) {
                    data[i] = data[i-1];
                }
                data[current_index + 1] = entry;
                current_index++;
                used++;
            }

        }
    }
    void sequence::remove_current(){
        if(is_item()){
            for (size_type i =current_index; i < used-1; i++) {
                data[i] = data[i+1];
            }
            used--;
        }
    }
    void sequence::insert_front(const value_type& entry){
        if (size() < CAPACITY) {
            for (size_type i =used; i>0; i--) {
                data[i+1] = data[i];
            }
            data[0] = entry;
            used++;
        }

    }
    void sequence::attach_back(const value_type& entry){
        if (size() < CAPACITY) {
            data[used] = entry;
            current_index = used;
            used++;
            
        }
       
    }
    void sequence::remove_front(){
        if (is_item()) {
            for (size_type i =0; i < used; i++) {
                data[i] = data[i+1];
            }
            data[used] = 0;
            used--;
        }

    }

    
    sequence::value_type sequence::operator[](int index) const{
        assert(index < used);
            return data[index];
        
    }
    
    
    void sequence::operator +=(const sequence& rhs){
        assert(size() + rhs.size() <CAPACITY);
        std::copy(rhs.data, rhs.data + rhs.used, data + used);
        used += rhs.used;
        current_index = used-1;
        
    }
    sequence operator +(const sequence& lhs, const sequence& rhs){
        sequence total;
        assert(lhs.size()+rhs.size()<sequence::CAPACITY);
        total+=rhs;
        total+=lhs;
        return total;
        
    }
     sequence::sequence(){
        used = 0;
        current_index = 0;
         for(int i = 0; i<CAPACITY; i++){
              data[i] = 0;
         }
        
    }

    sequence::size_type sequence::size() const{
        return used;
    }
    bool sequence::is_item( ) const{
        if (current_index<used){
            return true;
        }
        else{
            return false;
        }
    }
    

}





