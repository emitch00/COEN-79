//
//  poly.cpp
//  lab4part2
//
//  Created by michael joseph canniffe on 5/1/18.
//  Copyright © 2018 SCU. All rights reserved.
//

#include "poly.h"
#include <assert.h>
#include <cmath>

using namespace coen79_lab4;
namespace coen79_lab4 {
    
    polynomial::polynomial(double c, unsigned int exponent){
        assert(exponent<=MAXIMUM_DEGREE);
        for (int i=0; i<= MAXIMUM_DEGREE; ++i) {
            A[i]=0.0;
        }
         A[exponent] = c;
        current_degree = exponent;
    }
    
    void polynomial::assign_coef(double coefficient, unsigned int exponent){
        assert(exponent<=polynomial::MAXIMUM_DEGREE);
        A[exponent] = coefficient;
        update_current_degree();
    }
    
    void polynomial::add_to_coef(double amount, unsigned int exponent){
        assert(exponent<=MAXIMUM_DEGREE);
        A[exponent]+=amount;
          update_current_degree();
    }

    void polynomial::clear(){
        for (int i=0; i<=MAXIMUM_DEGREE; ++i) {
            A[i]=0.0;
        }
          update_current_degree();
    }
    
    polynomial polynomial::antiderivative( ) {
        assert( degree( ) <= polynomial::MAXIMUM_DEGREE);
        polynomial anti;
        for (int i = degree()+1; i>0; i--) {
            anti.A[i] = A[i-1]/(i);
        }
        anti.A[0]=0.0;
        anti.update_current_degree();
        return anti;
    }
    double polynomial::coefficient(unsigned int exponent) const{
        if (degree() > MAXIMUM_DEGREE) {
            return 0.0;
        }
        return A[exponent];
    }
    double polynomial::definite_integral(double x0, double x1) {
        double sum = 0.0;
        polynomial definite = antiderivative();
        sum = definite.eval(x1)-definite.eval(x0);
        return sum;
    }
  

    
    unsigned int polynomial::degree( ) const{
        int max = 0;
        for (int i=0; i<=MAXIMUM_DEGREE; ++i) {
            if (A[i]!=0) {
                max=i;
            }
        }
        return max;
    }

    polynomial polynomial::derivative( ) {
        polynomial deriv;
        for (int i=0; i<=degree(); i++) {
            deriv.A[i] = A[i+1]*(i+1);
        }
        deriv.update_current_degree();
        return deriv;

    }
    double polynomial::eval(double x) const{
        double sum = 0.0;
        for (int i=degree(); i>=0; --i) {
            sum +=coefficient(i)*(pow(x,i));
            
        }
        return sum;
    }

    bool polynomial::is_zero( ) const{
        for (int i=0; i<MAXIMUM_DEGREE; i++) {
            if (A[i]!=0) {
                return false;
            }
        }
        return true;
    }
    
    unsigned int polynomial::next_term(unsigned int e) const{
        for(int i = e; i< MAXIMUM_DEGREE;i++){
            if (A[i]!=0) {
                return i;
            }
        }
        return 0;
    }
    unsigned int polynomial::previous_term(unsigned int e) const{
        for(int i = e; i>0;i--){
            if (A[i]!=0) {
                return i;
            }
        }
        return 0;
    }
    
    polynomial operator +(const polynomial& p1, const polynomial& p2){
        polynomial plus;
        for (int i =0; i<=polynomial::MAXIMUM_DEGREE; i++) {
            plus.A[i] = p1.A[i]+p2.A[i];
        }
        return plus;
    }
    
    polynomial operator -(const polynomial& p1, const polynomial& p2){
        polynomial sub;
        for (int i =0; i<polynomial::MAXIMUM_DEGREE; i++) {
            sub.A[i] = p1.A[i]-p2.A[i];
        }
        return sub;
    }
    
    polynomial operator *(const polynomial& p1, const polynomial& p2){
        polynomial mult;
        assert(p1.degree()+p2.degree()<polynomial::MAXIMUM_DEGREE);
        for (int i =0; i<=p1.degree(); i++) {
            for(int j = 0;j<=p2.degree();j++){
                mult.add_to_coef(p1.coefficient(i)*p2.coefficient(j),i+j );
            }
        }
        return mult;
    }
    
    double polynomial::operator( ) (double x) const{
         return eval(x);
    }
    
    void polynomial::update_current_degree(){
        current_degree = 0;
        for (int i=0; i<MAXIMUM_DEGREE; i++) {
             if (A[i]!=0) {
                 current_degree = i;
             }
        }
    }
    std::ostream& operator << (std::ostream& out, const polynomial& p){
        for (int i=p.degree(); i>=0; --i) {
            if (p.coefficient(i)>0) {
                 out<<"+"<<p.coefficient(i)<<"x^"<<i<<" ";
            }
            else if (p.coefficient(i)==0){
                 out<< " ";
            }
            else{
                out<< "-"<<p.coefficient(i)<<"x^"<<i<<" ";

            }
        }
        return out;
    }
    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}