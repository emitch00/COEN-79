// FILE: bagtest.cpp
// Behnam Dezfouli, COEN, SCU
//
// An interactive test program for the new Bag class, implemented with
// a binary search tree.

#include <cctype>     // Provides toupper
#include <iostream>   // Provides cout, cin
#include <cstdlib>    // Provides EXIT_SUCCESS, size_t
#include "bag_bst.h"  // Provides the bag<double> class (with Item as a double)

using namespace std;
using namespace coen79_lab9;


// PROTOTYPES for the functions used in this test program.
void print_menu( );
// Postcondition: A menu of choices for this program has been written to cout.

char get_user_command( );
// Postcondition: The user has been prompted to enter a one character command.
// A line of input (with at least one character) has been read, and the first
// character of the input line is returned.

void display_bags(const bag<double>& b1, const bag<double>& b2);
// Postcondition: The function has tested whether the numbers 0..9 are in
// the two bags, and printed the results to standard output.

bag<double> copybag(bag<double> b);
// Postcondition: The return value is a copy of b.

double get_number( );
// Postcondition: The user has been prompted to enter a double number. The
// number has been read, echoed to the screen, and returned by the function.
void test1()
{
    bag<double> b1, b2;
    cout<<"Testing insert and the constant member functions"<<endl;
    cout<<"A. Testing size and count for an empty bag."<<endl;
    
    if(b1.size() == 0 && b1.count(1) == 0)
    {
        cout<<"Test passed."<<endl;
    }
    else
    {
        cout<<"Test failed."<<endl;
        return;
    }
    
    cout<<"B. Adding the number 4 to the bag, and then testing size and count."<<endl;
    b1.insert(4);
    
    if(b1.size() == 1 && b1.count(4) == 1)
    {
        cout<<"Test passed."<<endl;
    }
    else
    {
        cout<<"Test failed."<<endl;
        return;
    }

    cout<<"C. Inserting the number 2 into the bag, and then testing size and count."<<endl;
    b1.insert(2);
    
    if(b1.size() == 2 && b1.count(2) == 1)
    {
        cout<<"Test passed."<<endl;
    }
    else
    {
        cout<<"Test failed."<<endl;
        return;
    }

    cout<<"D. Inserting the number 1 into the bag, and then testing size and count."<<endl;
    b1.insert(1);
    
    if(b1.size() == 3 && b1.count(1) == 1)
    {
        cout<<"Test passed."<<endl;
    }
    else
    {
        cout<<"Test failed."<<endl;
        return;
    }

    cout<<"E. Inserting the number 3 into the bag, and then testing size and count."<<endl;
    b1.insert(3);
    
    if(b1.size() == 4 && b1.count(3) == 1)
    {
        cout<<"Test passed."<<endl;
    }
    else
    {
        cout<<"Test failed."<<endl;
        return;
    }

    cout<<"F. Inserting another 2 into the bag, and then testing size and count."<<endl;
    b1.insert(2);
    
    if(b1.size() == 5 && b1.count(2) == 2)
    {
        cout<<"Test passed."<<endl;
    }
    else
    {
        cout<<"Test failed."<<endl;
        return;
    }

    
    cout<<"G. Inserting the numbers 5, 6, and 7 into the bag, and then testing size and count."<<endl;
    b1.insert(5);
    b1.insert(6);
    b1.insert(7);
    
    if(b1.size() == 8 && b1.count(7) == 1)
    {
        cout<<"Test passed."<<endl;
    }
    else
    {
        cout<<"Test failed."<<endl;
        return;
    }

    
    cout<<"H. Inserting 3000 random items between 0 and 49 and then checking size and count."<<endl;
    
    
    
    for(int j = 0; j < 3000; j++)
    {
        int i = rand()*49;
        b1.insert(i);
    }
    
    
    if(b1.size() == 3008)
    {
        cout<<"Test passed."<<endl;
    }
    else
    {
        cout<<"Test failed."<<endl;
        return;
    }

    
}


int main( )
{
    bag<double> b1, b2;  // Bags that we'll perform tests on
    char choice; // A command character entered by the user
    int num;
    cout << "I have initialized two empty bags of doubles." << endl;
    cin >> num;
    if (num==1)
    {
        test1();
    }
    else if(num==2){
        do
        {
            print_menu( );
            choice = get_user_command( );
            switch (choice)
            {
                case 'A': b1 = b2;
                    break;
                case 'a': b2 = b1;
                    break;
                case 'C': b1 = copybag(b2);
                    break;
                case 'c': b2 = copybag(b1);
                    break;
                case 'S':
                case 's': cout << "The bags' sizes are " << b1.size( );
                    cout << " and " << b2.size( ) << endl;
                    break;
                case 'I': b1.insert(get_number( ));
                    break;
                case 'i': b2.insert(get_number( ));
                    break;
                case 'O': b1.erase_one(get_number( ));
                    break;
                case 'o': b2.erase_one(get_number( ));
                    break;
                case 'E': b1.erase(get_number( ));
                    break;
                case 'e': b2.erase(get_number( ));
                    break;
                case 'D':
                case 'd': display_bags(b1, b2);
                    break;
                case 'q':
                case 'Q': cout << "Ridicule is the best test of truth." << endl;
                    break;
                default: cout << choice << " is invalid. Sorry." << endl;
            }
        }
        while ((toupper(choice) != 'Q'));
    }
    return EXIT_SUCCESS;
    
}

void print_menu( )
// Library facilties used: iostream.h
{
    cout << "The following choices are available with 2 bags: " << endl;
    cout << " A  Use the assignment operator to make b1 equal to b2" << endl;
    cout << " a  Use the assignment operator to make b2 equal to b1" << endl;
    cout << " C  Use the copy constructor to make b1 equal to b2" << endl;
    cout << " c  Use the copy constructor to make b2 equal to b1" << endl;
    cout << " I  Insert an item into b1" << endl;
    cout << " i  Insert an item into b2" << endl;
    cout << " E  Erase item from b1" << endl;
    cout << " e  Erase item from b2" << endl;
    cout << " O  Erase one item from b1" << endl;
    cout << " o  Erase one item from b2" << endl;
    cout << " D  Display a count of items 0-9 in b1 and b2" << endl;
    cout << " S  Print the result from the size( ) functions" << endl;
    cout << " Q  Quit this test program" << endl;
}

char get_user_command( )
// Library facilties used: iostream.h
{
    char command;
    
    cout << "Enter choice: ";
    cin >> command;
    
    return command;
}

void display_bags(const bag<double>& b1, const bag<double>& b2)
// Library facilties used: iostream.h
{
    int i;
    
    for (i = 0; i < 10; i++)
    {
        cout << i << " in b1? " << b1.count(i);
        cout << "            " << i << " in b2? " << b2.count(i) << endl;
    }
}

bag<double> copybag(bag<double> b)
{
    return b;
}

double get_number( )
// Library facilties used: iostream.h
{
    int result;
    
    cout << "Please enter a double number for the bag: ";
    cin  >> result;
    cout << result << " has been read." << endl;
    return result;
}
