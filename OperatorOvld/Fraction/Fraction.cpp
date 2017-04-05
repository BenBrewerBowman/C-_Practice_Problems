
#include <iostream>
#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator): m_numerator(numerator), m_denominator(denominator) {};

void Fraction::print() const
{
  std::cout<<m_numerator<<"/"<<m_denominator<<std::endl;
}

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
  return Fraction(f1.m_numerator*f2.m_numerator, f1.m_denominator*f2.m_denominator);
}

Fraction operator*(const Fraction &f1, int number)
{
  return Fraction(f1.m_numerator*number, f1.m_denominator);
}

Fraction operator*(int number, const Fraction &f2)
{
  return Fraction(f2.m_numerator*number, f2.m_denominator);
}
