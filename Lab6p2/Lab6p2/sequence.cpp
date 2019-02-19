//FILE: sequence.cpp
//CLASS IMPLEMENTED: sequence (see sequence.h for documentation)
//
//
//  COEN 79
//  --- Behnam Dezfouli, COEN, SCU ---
//
//
//INVARIANT for the sequence class
//  1. The number of items in the sequence is stored in the member variable "many_nodes"
//
//  2. For an empty sequence, we do not care what is stored in any of data and head_ptr
//      and tail_ptr point to NULL; for a non-empty sequence, the items stored in the
//      sequence can be accessed using head_ptr and tail_ptr and we don't care what is
//      stored in the rest of the data.
//
//  3. If there is a current item, then it lies in *cursor; if there is no
//     current item, then cursor* equals NULL.
//
//  4. If there is a previous item, then it lies in precursor*.  If there is no previous
//       item, then precursor equals NULL.


#include <iostream>
#include <algorithm> //provides copy function
#include <cassert> //for assert function
#include "sequence.h" //header file for class
#include "node.h" // provides node class

using namespace std; //For copy function

namespace coen79_lab6
{
    // Default private member variable initialization function.
    void sequence::init()
    {
        //Initializing pointers to NULL
        head_ptr = NULL;
        tail_ptr = NULL;
        cursor = NULL;
        precursor = NULL;
        //Initializiing many_nodes (or our counter) to 0
        many_nodes = 0;
    }
    
    //CONSTRUCTOR IMPLEMENTATION for default constructor
    sequence :: sequence ()
    {
        init();
    }
    
    //Copy Constructor
    sequence :: sequence(const sequence& source)
    {
        init();
        *this = source;
    }
    
    //Destructor
    sequence::~sequence()
    {
        if(head_ptr != NULL)
            delete head_ptr;
        if(cursor != NULL)
            delete cursor;
            }
    
    void sequence::start()
    {
        if(head_ptr != NULL)
        {
            cursor = head_ptr;
            precursor = head_ptr;
        }
    }
    
    void sequence::end()
    {
        while(cursor->link() != NULL)
        {
            advance();
        }
        
    }
    
    
    void sequence::advance()
    {
        assert(is_item() == true);
        precursor = cursor;
        cursor = cursor->link();
    }
    
    
    void sequence::insert(const value_type& entry)
    {
        if(precursor == NULL ||is_item() == false)
        {
            list_head_insert(head_ptr, entry);
            cursor = head_ptr;
            precursor = NULL;
            if(is_item() == false)
            {
                tail_ptr = head_ptr;
            }
        }
        else
        {
            list_insert(precursor, entry);
            precursor = cursor;
            cursor = cursor->link();
        }
        many_nodes++;
    }
    
    
    void sequence::attach(const value_type& entry)
    {
        if(is_item()==false)
        {
            if(head_ptr == NULL && tail_ptr == NULL)
            {
                list_head_insert(head_ptr, entry);
                cursor = head_ptr;
                precursor = NULL;
                tail_ptr = head_ptr;
                many_nodes++;
                return;
            }
            else{
                list_insert(precursor, entry);
                cursor = precursor->link();
                //tail_ptr = tail_ptr->link();
                many_nodes++;
                return;
                }
        }
        if(cursor->link() == NULL){
                precursor=cursor;
                list_insert(precursor, entry);
                cursor=cursor->link();
                tail_ptr =cursor;
                many_nodes++;
                return;
            }
        precursor=cursor;
                list_insert(precursor, entry);
                cursor=cursor->link();
        
    }
    
    
    void coen79_lab6::sequence::operator =(const sequence& source){
        if(this == &source)
        {
            return;
        }
        list_clear(head_ptr);
        init();
        if(source.head_ptr == NULL)
        {
            list_copy(source.head_ptr, head_ptr, tail_ptr);
            head_ptr = NULL;
            tail_ptr = NULL;
        }
        if(source.many_nodes == 1 || source.cursor == source.head_ptr)
        {
            list_copy(source.head_ptr, head_ptr, tail_ptr);
            if(source.cursor == source.head_ptr)
            {
                cursor = head_ptr;
                precursor = NULL;
            }
            else if (source.many_nodes > 1)
            {
                list_piece(head_ptr, precursor, head_ptr, tail_ptr);
                if(source.cursor != NULL)
                {
                    list_piece(cursor, tail_ptr, head_ptr, tail_ptr);
                    precursor->set_link(cursor);
                }
                many_nodes = source.many_nodes;
            }
        }
    }
    coen79_lab6::sequence::size_type coen79_lab6::sequence::size( ) const{
        return many_nodes;
    }

    void coen79_lab6::sequence::remove_current()
    {
        assert(is_item() == true);
        list_remove(precursor);
    }
    
    //size() implemented as an inline function
    
    bool coen79_lab6::sequence::is_item( ) const
    {
        if(cursor != NULL)
        {
            return true;
        }
        else
            return false;
        
    }
    
    coen79_lab6::sequence::value_type coen79_lab6::sequence::current( ) const
    {
        assert(is_item() == true);
        return cursor->data();
    }
}
