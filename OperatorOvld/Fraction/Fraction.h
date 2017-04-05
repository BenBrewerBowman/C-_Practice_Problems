#ifndef FRACTION_H
#define FRACTION_H

class Fraction{
private:
  int m_numerator;
  int m_denominator;
public:
  Fraction(int numerator =0, int denominator =1);
  void print() const;
  friend Fraction operator*(const Fraction &f1, const Fraction &f2);
  friend Fraction operator*(const Fraction &f1, int number);
  friend Fraction operator*(int number, const Fraction &f2);
};

#endif
