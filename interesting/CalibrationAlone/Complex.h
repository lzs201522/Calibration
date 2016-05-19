// Complex.h - declaration of Complex user-defined type
// Written by Brett Esworthy

#pragma once

#include <iostream>
using namespace std;

// User-defined type declaration
struct Complex
{
	// The fields or member variables of Complex
	float Re;
	float Im;

	// Constructor
	// 1) Constructor name has to match exactly the name of the class
	// 2) Constructor CANNOT have a return value
	Complex() // Default constructor since it does not have arguments
	{
		Re = Im = 0;
	}

	// Init constructor
	Complex(float real, float imaginary)
	{
		Re = real;
		Im = imaginary;
	}

	// Member function for computing the absolute value of this Complex number
	float Absolute()
	{
		return sqrt(Re*Re + Im*Im);
	}

	// Operator + for adding two complex numbers
	Complex operator + (/*Complex left, IMPLICIT*/Complex right)
	{
		Complex result;
		// -> is a member access operator (just like .)
		// this is a pointer; -> is used to access members on a POINTER
		// this-> is equivalent to (*this).
		result.Re = this->Re + right.Re;
		result.Im = this->Im + right.Im;
		// or Complex result(Re + right.Re, Im + right.Im);
		return result;
	}

	//Operator + for adding a float this complex number
	// 2nd OVERLOAD of the + operator
	Complex operator + (/*Complex left, IMPLICIT*/float right)
	{
		Complex result(Re + right, Im);
		return result;
		// or return Complex(Re + right, Im);
	}
	
	// Operator - for subtracting two complex numbers
	Complex operator - (Complex right)
	{
		Complex result (Re - right.Re, Im - right.Im);
		if ( result.Im < 0 )
		{
			result.Im = result.Im * -1;
		}
		return result;
	}
	
	// Operator - for subtracting a float this complex number
	// 2nd overload of the - operator
	Complex operator - (float right)
	{
		Complex result(Re - right, Im);
		return result;
	}
	
	// Operator * for multiplying two complex numbers
	Complex operator * (Complex right)
	{
		Complex result (Re * right.Re, -Im * right.Im);
		return result;
	}

	// Operator * for multiplying a float this complex number
	// 2nd overload of the * operator
	Complex operator * (float right)
	{
		Complex result (Re * right, Im);
		return result;
	}

	// Operator / for dividing two complex numbers
	Complex operator / (Complex right)
	{
		Complex result (Re / right.Re, Im / right.Im);
		return result;
	}
	
	// Operator / for dividing a float this complex number
	// 2nd overload of the / operator
	Complex operator / (float right)
	{
		Complex result (Re / right, Im);
		return result;
	}

}; // ALWAYS PUT a ; at the end of class declaration


// Stream output operator
ostream& operator << (ostream& out, Complex c)
{
	out << "Re" << c.Re << "; Im=" << c.Im;
	return out;
}
