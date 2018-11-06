#include <iostream>
#include "Complex.h"
#include <math.h>
#include <string>
#include <sstream>
//using namespace std;
double complex::getReal()
{
    return a;
}
double complex::getImg()
{
    return b;
}
void complex::setReal(double Re)
{
    a = Re;
}
void complex::setImg(double Im)
{
    b = Im;
}
complex::complex(const complex& c)
{
    a=c.a;
    b=c.b;
}
void complex::read()
{
    std::cout<<"Real: ";
    std::cin>>a;
    std::cout<<"Img: ";
    std::cin>>b;
    std::cout<<"\n";
}

void complex::print()
{
    if (a == 0)
    {
        if(b == 0)
            std::cout<<"0";
        else if(b == 1)
            std::cout<<"i";
        else if (b == -1)
            std::cout<<"-i";
        else
        {
            if(b > 0)
                std::cout<<b<<"*i";
            else
                std::cout<<b<<"*i";
        }
    }
    else if(a > 0)
    {
        if(b == 0)
            std::cout<<a;
        else if(b == 1)
            std::cout<<a<<"+i";
        else if (b == -1)
            std::cout<<a<<"-i";
        else
        {
            if(b>0)
                std::cout<<a<<"+"<<b<<"*i";
            else
                std::cout<<a<<b<<"*i";
        }
    }
    else if(a<0)
    {
        if(b == 0)
            std::cout<<a;
        else if(b == 1)
            std::cout<<a<<"+i";
        else if (b== -1)
            std::cout<<a<<"-i";
        else
        {
            if(b>0)
                std::cout<<a<<"+"<<b<<"*i";
            else
                std::cout<<a<<b<<"*i";
        }
    }
}
/*
    string str(s);
    if (z.a == 0)
    {
        if (z.b == 0)
            s+= "0";
        else if (z.b == 1)
            s+= "i";
        else if (z.b== -1)
            s+= "-i";
        else
        {
            if (z.b> 0)
                s+="i*" + to_string(z.b);
            else
                s+="-i*"+ to_string(-(z.b));
        }
    }
    else
    {
        if (z.b== 0)
            s+= to_string(z.a);
        else if (z.b == 1)
            s+= to_string(z.a) + "+i";
        else if (z.b== -1)
            s += to_string(z.a) + "-i";
        else
        {
            if (z.b> 0)
                s+= to_string(z.a) + "+i*" + to_string(z.b);
            else
                s+= to_string(z.a) + "-i*" + to_string(-(z.b));
        }
    }
    return s;
}

{
    int i=0;
    if (s[0] == 'i' || s[1] == 'i')
        z.a = 0;
    else
    {
        for (i = 1; i < s.size(); i++)
            if (s[i] == '+' || s[i] == '-')
                break;
        z.a= stod(s.substr(0, i));
    }
    if (i == s.size())
        z.b = 0;
    else if (s[i] == '-')
        z.b = -1;
    else z.b = 1;

    if (s[i] != 'i' && i+3<s.size() )
         z.b*= stod(s.substr(i + 3, s.size()));
    else if(i + 3 < s.size())
        z.b= stod(s.substr(i + 2, s.size()));
}
*/
std::string ToString(const complex&z_complex)
{
    std::string stream;
    std::stringstream convert;
    if(z_complex.a>0)
    {
        if(z_complex.b==0)
        {
            convert<<z_complex.a;
        }
        else if(z_complex.b>0)
        {
            convert<<z_complex.a<<"+i"<<z_complex.b;
        }
        else if(z_complex.b<0)
        {
            convert<<z_complex.a<<"-i"<<z_complex.b;
        }
    }
    else if(z_complex.a==0)
    {
        if(z_complex.b==0)
        {
            convert<<"Ambele sunt nule";
        }
        else if(z_complex.b>0)
        {
            convert<<z_complex.b;
        }
        else if(z_complex.b<0)
        {
            convert<<"i"<<-z_complex.b;
        }
    }
    else if(z_complex.a<0)
    {
        if(z_complex.b==0)
        {
            convert<<z_complex.a;
        }
        else if(z_complex.b>0)
        {
            convert<<z_complex.a<<"-i"<<-z_complex.b;
        }
        else if(z_complex.b<0)
        {
            convert<<z_complex.a<<"-i"<<-z_complex.b;
        }
    }
    stream=convert.str();
    return stream;
}
complex operator+(const complex& z)
{
    std::cout<<"+Complex\n";
    return complex(z.a,z.b);
}
complex operator-(const complex& z)
{
    std::cout<<"-Complex\n";
    return complex(-z.a,-z.b);
}
complex operator+(const complex&z,const complex&c)
{
    std::cout<<"Adunare:\n";
    return complex(z.a+c.a,z.b+c.b);
}
complex operator-(const complex&z,const complex&c)
{
    std::cout<<"Scadere:\n";
    return complex(z.a-c.a,z.b-c.b);
}
complex operator+(const complex&z,const double c)
{
    std::cout<<"Adunare db1:\n";
    return complex(z.a+c,z.b);
}
complex operator+(const double z,const complex& c)
{
    std::cout<<"Adunare db2:\n";
    return complex(z+c.a,c.b);
}
complex operator-(const complex& z,const double c)
{
    std::cout<<"Scadere db1:\n";
    return complex(z.a-c,z.b);
}
complex operator-(const double z,const complex& c)
{
    std::cout<<"Scadere db2:\n";
    return complex(z-c.a,c.b);
}
complex operator*(const complex& z,const complex& c)
{
    std::cout<<"Inmultire:\n";
    return complex(z.a*c.a-z.b*c.b,z.a*c.b+z.b*c.a);
}
complex operator*(const complex& z,const double c)
{
    std::cout<<"Inmultire db1:\n";
    return complex(z.a*c,z.b*c);
}
complex operator*(const double z,const complex&c)
{
    std::cout<<"Inmultire db2:\n";
    return complex(c.a*z,c.b*z);
}
complex operator/(const complex& z,const complex& c)
{
    std::cout<<"Impartire:\n";
    if(c.a==0 && c.b==0)
    {
        std::cout <<"Nu se poate";
        return 0;
    }
    return complex((z.a*c.a+z.b*c.b)/(c.a*c.a+c.b*c.b),(z.b*c.a-z.a*c.b)/(c.a*c.a+c.b*c.b));
}
complex operator/(const complex& z,const double c)
{
    std::cout<<"Impartire d1:\n";
    if(c==0)
    {
        std::cout<<"Imaprtire la 0 "<<" ";
        return 0;
    }
    return complex(z.a/c,z.b/c);
}
complex operator/(const double z,const complex&c)
{
    std::cout<<"Impartire db2:\n";
    if(c.a==0 && c.b==0)
    {
        std::cout<<"Nu se poate efectua impartirea numarului";
        return 0;
    }
    return complex((z*c.a)/(c.a*c.a+c.b*c.b),(-z*c.b)/(c.a*c.a+c.b*c.b));
}
complex operator^(complex&z, int n)
{
    int i;
    complex aux;
    aux=z;
    if(n==0)
    {
        aux.a=1;
        aux.b=0;
    }
    else
        for(i=1; i<n; i++)
            aux=z*aux;
    return aux;
}
complex operator!=(const complex &z,const complex& c)
{
    if(c.a!=z.a && c.b!=z.b)
        std::cout<<"Numere complexe diferite"<<"\n";
    else std::cout<<"Sunt egale";
    std::cout<<"\n";
}
complex operator!=(const complex&z,double c)
{
    if(c!=z.a && c!=z.b)
    std::cout<<"Numere complexe diferite"<<"\n";
    else std::cout<<"Egale";
    std::cout<<"\n";
}
complex operator==(const complex &z,const complex& c)
{
    if(c.a==z.a && c.b==z.b)
        std::cout<<"Numere complexe egale";
    else std::cout<<"Nu sunt egale";
    std::cout<<"\n";
}
complex operator+=(const complex& z,const complex& c)
{
    std::cout<<"Operator +=";
    return complex(z.a+c.a, z.b+c.b);
}

complex operator+=(complex&z,const double c)
{
    std::cout<<"Adunare db1:\n";
    return complex(z.a+c,z.b+c);
}

complex operator-=(const complex& z, const complex& c)
{
    std::cout<<"Operator -=";
    return complex(z.a-c.a,z.b-c.b);
}
complex operator-=(complex&z,const double c)
{
    std::cout<<"Scadere db4:\n";
    return complex(z.a-c,z.b-c);
}
complex operator*=(const complex& z,const complex& c)
{
    std::cout<<"Inmultire *=";
    return complex (z.a*c.a-z.b*c.b,z.a*c.b+z.b*c.a);
}

complex operator*=(const complex&z,const double c)
{
    std::cout<<"Inmultire db1:\n";
    return complex(z.a*c,z.b*c);
}
double abs(complex& z_complex)
{
    return sqrt(z_complex.a*z_complex.a+z_complex.b*z_complex.b);
}
complex operator /=(const complex& z, const complex&c)
{
    std::cout<<"Impartire /=";
    return complex((z.a*c.a+z.b*c.b)/(c.a*c.a+c.b*c.b),(z.b*c.a-z.a*c.b)/(c.a*c.a+c.b*c.b));
}
complex operator /=(const double& z, const complex&c)
{
    std::cout<<"Impartire /=";
    return complex((z*c.a)/(c.a*c.a+c.b*c.b),(-z*c.b)/(c.a*c.a+c.b*c.b));
}
complex complex::Conj(const complex& z_complex)
{
    a=z_complex.a;
    b=-z_complex.b;
    return *this;
}
std::istream& operator>>(std::istream& stream, complex& z_complex)
{
    stream>>z_complex.a>>z_complex.b;
    return stream;
}
std::ostream& operator<<(std::ostream& stream,const complex& z_complex)
{
    stream<<z_complex.a<<z_complex.b;
    return stream;
}
/*complex complex::operator =(const complex& z,const complex& c)
{
 a=z.a;
 b=z.b;
 return (*this);
}*/
