#ifndef RATIO_H
#define RATIO_H

#include <iostream>

namespace ds_course{

    class Ratio{
        private:
          int numerator;
          int denominator; 
          int gcd(int a , int b);
        public:
            Ratio operator+(Ratio& rhs);
            Ratio operator-(Ratio& rhs);
            Ratio operator*(Ratio& rhs);
            Ratio operator/(Ratio& rhs);
            Ratio(int nn = 0, int dd = 1);

        friend std::ostream& operator<< (std::ostream& oStream, const Ratio rat){
        oStream << "[" << rat.numerator << "/" << rat.denominator << "]";
        return oStream;
    }

    };






int Ratio::gcd(int a, int b){
    return 0;
}

Ratio::Ratio(int nn = 0, int dd = 1): numerator(nn), denominator(dd){
    int g = gcd(nn, dd);
    numerator = nn / g;
    denominator = dd / g;
    if(denominator < 0){
        numerator = -numerator;
        denominator = -denominator;
    }

}



Ratio Ratio::operator+(Ratio& rhs){
    int upside = numerator * rhs.denominator + denominator * rhs.numerator;
    int downside = denominator * rhs.denominator;
    Ratio result(upside, downside);
    return result;
}

Ratio Ratio::operator-(Ratio& rhs){
    int upside = numerator * rhs.denominator - denominator * rhs.numerator;
    int downside = denominator * rhs.denominator;
    Ratio result(upside, downside);
    return result;
}

Ratio Ratio::operator*(Ratio& rhs){
    int upside = numerator * rhs.numerator;
    int downside = denominator * rhs.denominator;
    Ratio result(upside, downside);
    return result;
}

Ratio Ratio::operator/(Ratio& rhs){
    int upside = numerator * rhs.denominator;
    int downside = denominator * rhs.denominator;
    Ratio result(upside, downside);
    return result;
}

}

#endif