#pragma once
#include <iostream>

using namespace std;

template <class T>
class ComplexNumber{
public:
    int x;
    int y;
public:
    ComplexNumber(){
        x = 0;
        y = 0;
    }

    ComplexNumber(T x1, T y1){
        x = x1;
        y = y1;
    }
};

template <typename T>
ComplexNumber<T> operator + (ComplexNumber<T> n1, ComplexNumber<T> n2){
    //ComplexNumber<T> number = new ComplexNumber<T>;
    ComplexNumber<T>* number = (ComplexNumber<T>*) malloc(sizeof(ComplexNumber<T>));
    number->x = n1.x + n2.x;
    number->y = n1.y + n2.y;
    return *number;
}

template <typename T>
ComplexNumber<T> operator - (ComplexNumber<T> n1, ComplexNumber<T> n2){
    //ComplexNumber<T> number = new ComplexNumber<T>;
    ComplexNumber<T>* number = (ComplexNumber<T>*) malloc(sizeof(ComplexNumber<T>));
    number->x = n1.x - n2.x;
    number->y = n1.y - n2.y;
    return *number;
}

template <typename T>
ComplexNumber<T> operator * (ComplexNumber<T> n1, ComplexNumber<T> n2){
    //ComplexNumber<T> number = new ComplexNumber<T>;
    ComplexNumber<T>* number = (ComplexNumber<T>*) malloc(sizeof(ComplexNumber<T>));
    number->x = n1.x * n2.x - n1.y * n2.y;
    number->y = n1.x * n2.y + n2.x * n1.y;
    return *number;
}

template <typename T>
int operator == (ComplexNumber<T> n1, ComplexNumber<T> n2){
   if (n1.x == n2.x && n1.y == n2.y){
       return 1;
   }
   return 0;
}

template <typename T>
ComplexNumber<T> operator * (float n1, ComplexNumber<T> n2){
    //ComplexNumber<T> number = new ComplexNumber<T>;
    ComplexNumber<T>* number = (ComplexNumber<T>*) malloc(sizeof(ComplexNumber<T>));
    number->x = n2.x * n1;
    number->y = n2.y * n1;
    return *number;
}

template <typename T>
std::ostream& operator<< (std::ostream &out, const ComplexNumber<T> &number)
{
    out << "(" << number.x << ", " << number.y << ")";
    return out;
}

template <typename T>
std::istream& operator>> (std::istream &in, ComplexNumber<T> &number)
{

    in >> number.x;
    in >> number.y;

    return in;
}