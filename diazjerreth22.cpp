#include <iostream>
#include <cmath>
using namespace std;
/**
 * Building off of what was made in a previous assignment
 * implement overloaded operators to the Complex class.
 *
 *@author Diaz,Jerreth
 *@assignment ICS 212 Assignment 22
 *@date 4/21/2022
 */
 
class Complex {
private:
  //initalizing variables only accessable through the class
  double real; 
  double imaginary;
public:
  
  /**
   * Constructor #1.
   * the default Constructor setting variables to zero
   */
  Complex() {
    real = 0;
    imaginary = 0;
  }
  
  /**
   * Constructor #2.
   * Constructs a complex object given the real and imaginary number
   *
   * @param realParam the real number
   * @param imaginaryParam the imaginary number.
   */
  Complex(double realParam, double imaginaryParam){
    set(realParam, imaginaryParam);
  }
  /**
   * Copy constructor.
   * Makes a copy of the complex number.
   *
   * @param &copyComplex the complex object to be copied.
   */
  Complex(const Complex &copyComplex){
    set(copyComplex.real, copyComplex.imaginary);
  }
  //destructor
  ~Complex(){
    // if the imaginary num is pos
    if (imaginary >= 0){
      cout << "destructor for:" << "(" << real << " + " << imaginary << "i)" << endl; 
    }
    //if imaginary num is neg
    else{
      cout << "destructor for:" << "(" << real << " - " << -1 * imaginary << "i)" << endl;
    }
  }
  
  //mutator method 
  void set(double r, double i){
    real = r;
    imaginary = i;
  }

  //accessor methods
  double getReal() const {
    return real;
  }
  double getImaginary() const {
    return imaginary;
  }
  /**
   * prints the complex problem
   */ 
  void print() const{
    // if the imaginary num is pos
    if (imaginary >= 0){
      cout << "(" << real << " + " << imaginary << "i)" << endl; 
    }
    //if imaginary num is neg
    else{
      cout << "(" << real << " - " << -1 * imaginary << "i)" << endl;
    }
  }
  /**
   * Adds another complex object to this one and returns it.
   *
   * @param &addComplex the complex object to be added.
   * @return complex3 a Complex object the sum two complex numbers.
   */
  Complex add(const Complex &addComplex) const{
    //calculate the new numbers
    double real3 = (real + addComplex.real); 
    double imaginary3 = (imaginary + addComplex.imaginary);
    //create the new complex number
    Complex complex3(real3, imaginary3);
    return complex3;
  }
  /**
   * subtract another complex object to this one and returns it.
   *
   * @param &subtractComplex the complex object to be subtrected.
   * @return complex3 a Complex object the difference two complex numbers.
   */
  Complex subtract(const Complex &subtractComplex) const {
    //calculate the new numbers
    double real3 = (real - subtractComplex.real); 
    double imaginary3 = (imaginary - subtractComplex.imaginary);
    //create the new complex number
    Complex complex3(real3, imaginary3);
    return complex3;
  }
  /**
   * multiplies another complex object to this one and returns it.
   *
   * @param &multiplyComplex the complex object to be muliplyed.
   * @return complex3 a Complex object the product two complex numbers.
   */
  Complex multiply(const Complex &multiplyComplex) const{
    //calculate the new numbers
    double real3 = (real*multiplyComplex.real - imaginary*multiplyComplex.imaginary);
    double imaginary3 = (imaginary*multiplyComplex.real + real*multiplyComplex.imaginary);
    //create the new complex number
    Complex complex3(real3, imaginary3);
    return complex3;
  }
  /**
   * divides another complex object to this one and returns it.
   *
   * @param &multiplyComplex the complex object to be divided.
   * @return complex3 a Complex object the quotient two complex numbers.
   */
  Complex divide(const Complex &divideComplex) const{
    //calculate the new numbers
    double real3 = ((real*divideComplex.real + imaginary*divideComplex.imaginary) / (divideComplex.real*divideComplex.real + divideComplex.imaginary*divideComplex.imaginary));
    double imaginary3 = ((imaginary*divideComplex.real - real*divideComplex.imaginary) / (divideComplex.real*divideComplex.real + divideComplex.imaginary*divideComplex.imaginary));
    //create the new complex number
    Complex complex3(real3, imaginary3);
    return complex3;
  }
  /**
   * Overload the >> to create Complex objects with cin >>.
   * User should type in the format: integer, followed by another integer, followed by an i
   *   a+bi
   *   a-bi
   * Where a and b are integers.
   * For simplicity this overloaded >> only reads in integer real and integer imaginary parts.
   *
   * This function does not enforce the i to be an i.
   *
   * @return in The cleared input stream. The Complex object c was set.
   */
  friend istream &operator>>(istream &in, Complex &c) {
    // Used to store the letter 'i' from the input.
    char letter_i = 'i';

    // Used to temporarily store the real and imaginary parts entered by the user.
    int tempReal = 0;
    int tempImaginary = 0;

    // Read input a+bi and store the real and imaginary parts.
    in >> tempReal >> tempImaginary >> letter_i;
 
    // Use the set function for error checking.
    c.set(tempReal, tempImaginary);
       
    // Clear the input stream.
    in.clear();
    return in;
  }
  /**
   * Overload the << to directly output a complex object.
   * Output format: (a+bi) or (a-bi)
   *
   * @return output How this complex object will be output.
   */
  friend ostream &operator<<(ostream &out, const Complex &complexParam){
    //if imaginary num is pos
    if (complexParam.imaginary >= 0){
      out << "(" << complexParam.real << " + " << complexParam.imaginary << "i)"; 
    }
    //if imaginary num is neg
    else{
      cout << "(" << complexParam.real << complexParam.imaginary << "i)";
      
    }
    return out;  
  }
  /**
   * Overload the plus (+) operator for adding Complex objects.
   * Adds two Complex objects and returns it.
   * Similar to the add() function but allows the usage of + for complex numbers.
     *
     * @param &complex1 The complex number on the right of the + operator.
     * @param &complex2 The complex number on the left of the + operator
     * @return complex3 the new complex number
     */
  friend Complex operator+(const Complex &complex1, const Complex &complex2){
    //calculate the new numbers
    double real3 = (complex1.real + complex2.real); 
    double imaginary3 = (complex1.imaginary + complex2.imaginary);
    //create the new complex number
    Complex complex3(real3, imaginary3);
    return complex3;  
  }
  /**
   * Overload the plus (-) operator for subtracting Complex objects.
   * minuses two Complex objects and returns it.
   * Similar to the subtract() function but allows the usage of - for complex numbers.
   *
   * @param complexParam one of the refrenced complex numbers.
   * @return complex3 the new complex number
   */
  Complex operator-(const Complex &complexParam) const {
    //calculate the new numbers
    double real3 = (real - complexParam.real); 
    double imaginary3 = (imaginary - complexParam.imaginary);
    //create the new complex number
    Complex complex3(real3, imaginary3);
    return complex3;  
  }
  /**
   * Overload the plus (*) operator for subtracting Complex objects.
   * multiplies two Complex objects and returns it.
   * Similar to the multiply() function but allows the usage of * for complex numbers.
   *
   * @param complexParam one of the refrenced complex numbers.
   * @return complex3 the new complex number
   */
  Complex operator*(const Complex &complexParam) const {
    //calculate the new numbers
    double real3 = (real*complexParam.real - imaginary*complexParam.imaginary);
    double imaginary3 = (imaginary*complexParam.real + real*complexParam.imaginary);
    //create the new complex number
    Complex complex3(real3, imaginary3);
    return complex3;  
  }
  /**
   * Overload the plus (/) operator for subtracting Complex objects.
   * divides two Complex objects and returns it.
   * Similar to the divide() function but allows the usage of / for complex numbers.
   *
   * @param complexParam one of the refrenced complex numbers.
   * @return complex3 the new complex number
   */
  Complex operator/(const Complex &complexParam) const {
    //calculate the new numbers
    double real3 = ((real*complexParam.real + imaginary*complexParam.imaginary) / (complexParam.real*complexParam.real + complexParam.imaginary*complexParam.imaginary));
    double imaginary3 = ((imaginary*complexParam.real - real*complexParam.imaginary) / (complexParam.real*complexParam.real + complexParam.imaginary*complexParam.imaginary));
    //create the new complex number
    Complex complex3(real3, imaginary3);
    return complex3;  
  }
  /**
   * Compares two objects usinging the bool operator == to see if they match 
   * 
   * @param complex1 the first complex number.
   * @param complex2 the second complex number.
   * @return true if they match
   * @return false if they dont
     */
  friend bool operator==(const Complex &complex1, const Complex &complex2){
    if (complex1.real == complex2.real && complex1.imaginary == complex2.imaginary){
      return true;
    }
    else{
      return false;
    }
  }
  /**
   * Compares two objects usinging the bool operator == to see if they dont match 
   * 
   * @param complex1 the first complex number.
   * @param complex2 the second complex number.
   * @return the reverse of the == operator 
   */
  friend bool operator!=(const Complex &complex1, const Complex &complex2){
    return !(complex1 == complex2);
  }
    
};

int main(){
  // Used to store the two Complex objects from user input.
  Complex complex1;
  Complex complex2;
  // A blank Complex object used to store the results of the Complex arithmetic.
  Complex complex3;

  // Get 2 Complex objects from the user.
  cout << "Enter a Complex number in the form 'a+bi': ";
  cin >> complex1;
  cout << "Enter another Complex number in the form 'a+bi': ";
  cin >> complex2;
  
  cout << endl;
  
  // Test the + overloaded operator.
  cout << "Test the + operator:" << endl;
  complex3 = complex1 + complex2;
  cout << complex1 << " + " << complex2 << " = " << complex3 << endl;

  cout << "\n";
  
  // Test the - overloaded operator.
  cout << "Test the - operator:" << endl;
  complex3 = complex1 - complex2;
  cout << complex1 << " - " << complex2 << " = " << complex3 << endl;

  cout << "\n";
  
  // Test the * overloaded operator.
  cout << "Test the * operator:" << endl;
  complex3 = complex1 * complex2;
  cout << complex1 << " * " << complex2 << " = " << complex3 << endl;

  cout << "\n";

  // Test the / overloaded operator.
  cout << "Test the / operator:" << endl;
  complex3 = complex1 / complex2;
  cout << complex1 << " / " << complex2 << " = " << complex3 << endl;

  cout << "\n";
  
  // Test the == overloaded operator.
  cout << "Test the == operator:" << endl;
  // Turn on boolalpha to actually print true or false instead of 1 or 0.
  cout << complex1 << " == " << complex2 << " = " << boolalpha << (complex1 == complex2) << endl;

  cout << "\n";
  
  // Test the != overloaded operator.
  cout << "Test the != operator:" << endl;
  cout << complex1 << " != " << complex2 << " = " << (complex1 != complex2) << endl;

  cout << "\n";
  
  return 0;
}
