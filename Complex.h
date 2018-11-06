#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED
#include <iostream>

//using namespace std;

class complex
{
private:
    double a, b;
public:
    double getReal();
    double getImg() ;
    void setReal(double Re);
    void setImg(double Im);
    complex(const complex& c);
    complex(double v=0, double i=0): a(v),b(i) {}
    void read();
    void print();
    //friend complex string operator(complex c);
    friend complex operator+(const complex& z);
    friend complex operator-(const complex& z);
    friend complex operator+(const complex& z,const complex& c);
    friend complex operator-(const complex& z,const complex& c);
    friend complex operator+(const complex& z,const double c);
    friend complex operator+(const double z,const complex& c);
    friend complex operator-(const complex& z,const double c);
    friend complex operator-(const double z,const complex& c);
    friend complex operator*(const complex& z,const complex& c);
    friend complex operator*(const complex& z,const double c);
    friend complex operator*(const double z,const complex&c);
    friend complex operator/(const complex&z,const complex&c);
    friend complex operator/(const complex& z,const double c);
    friend complex operator/(const double z,const complex&c);
    friend complex operator^(complex&z, int n);
    friend complex operator!=(const complex& z, const complex& c);
    friend complex operator!=(const complex& z, double c);
    friend complex operator ==(const complex& z, const complex& c);
//    complex operator =(const complex& z,const complex& c);
    friend complex operator+=( const complex& z,const complex& c);
    friend complex operator+=(complex& z, const double c);
    friend complex operator-=(const complex& z, const complex& c);
    friend complex operator-=(complex& z, const double c);
    friend complex operator *=(const complex& z, const complex&c);
    friend complex operator *=(const complex& z, const double c);
    friend complex operator /=(const complex& z,const complex& c);
    friend complex operator /=(const double& z,const complex& c);
    friend std::istream& operator>>(std::istream& stream,complex &z_complex);
    friend std::ostream& operator<<(std::ostream& stream,const complex& z_complex);
    friend double abs(complex& z_complex);
    complex Conj(const complex& z_complex);
    friend std::string ToString(const complex&z_complex);
    //friend string str(complex& z);
    //string ToString();
};
#endif // COMPLEX_H_INCLUDED
