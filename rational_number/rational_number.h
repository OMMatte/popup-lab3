//Authors: Lucas Wiener & Mathias Lindblom

#ifndef _rational_number_h_
#define _rational_number_h_

#include <algorithm>
#include <iostream>
#include <math.h>

/**
 * Class representing a rational number.
 * To work properly the generic type should be some form of mathematical Integer, such as long or int.
 * The rational number will always be normalized.
 * If the numerator is zero then the denominator will always be 1.
 * The denominator will never be negative.
 */
template <class T>
class RationalNumber {
    T p; // the numerator
    T q; // the denominator
public:
    RationalNumber() :p(0), q(1) {}
    
    /**
     * Creates a new rational number using the given values.
     * Throws exception if denominator is zero.
     */
    RationalNumber(T numerator, T denominator) : p(numerator), q(denominator) {
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
    
    friend bool operator==(const RationalNumber& nr1, const RationalNumber& nr2) {
        return(nr1.p == nr2.p && nr1.q == nr2.q);
    }
    
    friend bool operator!=(const RationalNumber& nr1, const RationalNumber& nr2) {
        return !(nr1 == nr2);
    }
    
    friend bool operator<( const RationalNumber& nr1, const RationalNumber& nr2) {
        if(nr1.q == nr2.q) {
            return nr1.p < nr2.p;
        } else {
            return nr1.p * nr2.q < nr2.p * nr1.q;
        }
    }
    
    friend bool operator<=(const RationalNumber& nr1, const RationalNumber& nr2) {
        return (nr1 == nr2 || nr1 < nr2);
    }
    
    friend bool operator>(const RationalNumber& nr1, const RationalNumber& nr2) {
        return !(nr1 <= nr2);
    }
    
    friend bool operator>=(const RationalNumber& nr1, const RationalNumber& nr2) {
        return (nr1 == nr2 || nr1 > nr2);
    }
    
    /**
     * Reads from input the numerator followed by the denominator.
     */
    friend std::istream& operator>>(std::istream& input, RationalNumber& nr) {
        input >> nr.p;
        input >> nr.q;
        nr.normalize();
        return input;
    }
    
    /**
     * Writes the rational number nr to outstream out in the form "numerator / denominator".
     */
    friend std::ostream& operator<<(std::ostream& out, const RationalNumber& nr) {
        out << nr.p << " / " << nr.q;
        return out;
    }
    
private:
    /**
     * Helper function for the addition and substraction operators
     */
    RationalNumber add(const T& otherP,const T& otherQ) {
        if(q == otherQ) {
            return RationalNumber(p + otherP, q);
        } else {
            return RationalNumber(p * otherQ + otherP * q, q * otherQ);
        }
    }
    
    /**
     * Will normalize the rational number.
     * If the numerator is zero then the denominator will always be 1.
     * Is always called when the rational number is created or changed with the exception of the default constructor.
     */
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
