
#include<iostream>
#include<cmath>
class Fraction
{
private:
    int numerator, denominator;
 public:
    Fraction()
    {
        numerator = 1;
        denominator = 1;
    }
    Fraction(int n, int d)
    {
        if(d==0){
            numerator=0;
            denominator=0;  
            throw "ERROR: ATTEMPTING TO DIVIDE BY ZERO";
        }
        else
        {
            numerator = n;
            denominator =d;
        }
    }
    Fraction Sum(Fraction otherFraction)
    {
        int n = numerator * otherFraction.denominator + otherFraction.numerator * denominator;
        int d = denominator * otherFraction.denominator;
        int tmp=gcd(n,d); return Fraction(n / tmp,d/tmp);
    }
    Fraction Difference(Fraction otherFraction)
    {
        int n = numerator * otherFraction.denominator - otherFraction.numerator * denominator;
        int d = denominator * otherFraction.denominator;
        int tmp=gcd(n,d); return Fraction(n / tmp,d/tmp);
    }
    Fraction multiplication(Fraction otherFraction)
    {
        int n = numerator * otherFraction.numerator;
        int d = denominator * otherFraction.denominator;
        int tmp=gcd(n,d); return Fraction(n / tmp,d/tmp);
    }
    Fraction Division(Fraction otherFraction)
    {
        int n = numerator * otherFraction.denominator;
        int d = denominator * otherFraction.numerator;
        int tmp=gcd(n,d); return Fraction(n / tmp,d/tmp);
    }
  
    Fraction NOD(Fraction otherFraction)
    
        {
        int n = numerator * otherFraction.denominator;
        int d = denominator * otherFraction.numerator;
        
            int remainder;
            while (d != 0)
            {
                remainder = n % d;
                n = d;
                d = remainder;
            }
            
        
        return Fraction(  gcd_1(n, d),  gcd_1(n, d));
    }
    
    int gcd_1(int n, int d) {
        return n ;
    }

    int gcd(int n, int d)
    {
        if (n<1){
            n =-n;
        }
         if (d<1){
            d =-d;
        } 
        
        
        int remainder;
        while (d != 0)
        {
            remainder = n % d;
            n = d;
            d = remainder;
        }
        return n;
    }
    void show()
    {
        if (denominator == 1)
            std::cout << numerator << std::endl;
        else
            std::cout << numerator << "/" << denominator << std::endl;
    }
};

int main()
{
    try
    {
        Fraction a(2, 3);
        Fraction b(1, 4);
        Fraction c;
        Fraction d(4, 6);
        Fraction f(1, 1);
        a.show(); // Result: 2/3
        c = a.Sum(b);  // Result: 11/12
        c.show();
        c = a.Difference(b);
        c = c.multiplication(a.Sum(b));
        c = c.Division(a.Sum(b)); // Result: 5/12
        c.show();
        d = d.Division(f); // Result: 2/3
        d.show();
    }
    catch(const char* str)
    {
        std::cout<<str<<std::endl;
    }

    
   
    return 0;
}