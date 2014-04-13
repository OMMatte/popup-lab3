#ifndef __popup_lab3_rational_number__RationalNumber__
#define __popup_lab3_rational_number__RationalNumber__

#include <algorithm>
#include <iostream>
#include <math.h>


template <class T>
class RationalNumber {
    T p;
    T q;
public:
    RationalNumber() :p(0), q(1) {}
    RationalNumber(T p, T q) : p(p), q(q) {
       normalize();
    }
    
    RationalNumber operator+(const RationalNumber& other) {
        return add(other.p, other.q);
    }
    RationalNumber operator-(const RationalNumber& other) {
        return add(other.p, -other.q);
    }
    RationalNumber operator*(const RationalNumber& other) {
        return RationalNumber(p * other.p, q * other.q);
    }
    RationalNumber operator/(const RationalNumber& other) {
        return RationalNumber(p * other.q, q * other.p);
    }
    
    friend bool operator== (const RationalNumber &nr1, const RationalNumber &nr2) {
        return(nr1.p == nr2.p && nr1.q == nr2.q);
    }
    
    friend bool operator!= (const RationalNumber &nr1, const RationalNumber &nr2) {
        return !(nr1 == nr2);
    }
    
    friend bool operator< ( const RationalNumber &nr1, const RationalNumber &nr2) {
        if(nr1.q == nr2.q) {
            return nr1.p < nr2.p;
        } else {
            return nr1.p * nr2.q < nr2.p * nr1.q;
        }
    }
    
    friend bool operator<= (const RationalNumber &nr1, const RationalNumber &nr2) {
        return (nr1 == nr2 || nr1 < nr2);
    }
    
    friend bool operator> (const RationalNumber &nr1, const RationalNumber &nr2) {
        return !(nr1 <= nr2);
    }
    
    friend bool operator>= (const RationalNumber &nr1, const RationalNumber &nr2) {
        return (nr1 == nr2 || nr1 > nr2);
    }
    
    friend std::istream& operator>>(std::istream& input, RationalNumber& nr) {
        input >> nr.p;
        input >> nr.q;
        nr.normalize();
        return input;
    }
    
    friend std::ostream& operator<<(std::ostream& out, const RationalNumber& nr) {
        out << nr.p << " / " << nr.q;
        return out;
    }
    
private:
    
    RationalNumber add(T otherP, T otherQ) {
        if(q == otherQ) {
            return RationalNumber(p + otherP, q);
        } else {
            return RationalNumber(p * otherQ + otherP * q, q * otherQ);
        }
    }
    
    void normalize() {
        if(q == 0) {
            throw std::invalid_argument("denominator can not be zero");
        }
        T v = p;
        T u = q;
        while( v != 0) {
            T r = u % v;
            if(r < 0) {
                r = -r;
            }
            u = v;
            v = r;
        }
        p = p / u;
        q = q / u;
        
        if(q < 0) {
            q = -q;
            p = -p;
        }
    }
};

#endif
