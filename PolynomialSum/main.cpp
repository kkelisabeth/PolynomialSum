/*
* Creator:    Kozlova Elizabeth Paula
*
* Title:      Polynomial Sum 
*
* Description:
*             This program accepts from the user two polynomials, calculates the sum of them, and then displays the result.
*/


#include <iostream> 
using namespace std;

//function prototypes 
bool SignOfPolynomial(char, bool);
double Coefficient(bool, double);
bool PolynomialValidation(char, bool);
bool ExponentValidation(int, bool);
/**
* Function <code>main</code> is the driver of the program, which accepts two polynomials and sums them up.
* <BR>
* @param polinomial1 Array containing coefficients of the first polynomial.
* @param polynomial2 Array containing coefficients of the second polynomial.
* @param sum Array containing sum of coefficients of two polynomials.
* @param c Character used to read the c-strings.
* @param coefficient Coefficient of elements of the polynomials.
* @param power Power of X of the polynomials.
* @param NextPower Bool value, which is used to check whether the character we are getting is after x or not.
* @param signOfPolynomial Bool value, which is used to determine whether the coefficient is positive or negative.
* @param checker Bool value, which is used in polynomial validation.
* @param exponentVal Bool value, which is used in exponent validation.
*/
int main()
{
	//initializing both arrays for polynomials with zeros
	double polynomial1[10] = {};
	double polynomial2[10] = {};

	//initializing necessary variables 
	char c;
	double coefficient = 0;
	int power = 0;
	bool NextPower = false;
	bool signOfPolynomial = false;
	bool checker = true;
	bool exponentVal = true;

	//accepts first polynomial
	cout << "Enter first polynomial: ";
	while (c = cin.get(), c != '\n')
	{
		//polynomial validation  - checks if the polynomial contains unallowed characters
		if (!PolynomialValidation(c, checker))
		{
			cout << "Invalid Polynomial." << endl;
			break;
		}
		else
		{
			if (c == '+' || c == '-')
			{
				//determines whether the coefficient is positive or negative
				signOfPolynomial = SignOfPolynomial(c, signOfPolynomial);
				//power == 1 && coefficient == 0
				if (coefficient && NextPower == NULL)
				{
					polynomial1[0] = 1;
					NextPower = false;
				}
				//power == 1 && coefficient != 0
				else if (NextPower && coefficient != NULL)
				{
					polynomial1[1] += coefficient;
					NextPower = false;
				}
				//power == 0 && coefficient !- 0 
				else if (!NextPower && coefficient != NULL)
				{
					polynomial1[0] += coefficient;
					NextPower = false;
				}
				coefficient = NULL;
			}
			else if (c == 'x' || c == 'X')
			{
				//coefficient == 0
				if (coefficient == NULL)
				{
					if (signOfPolynomial)
						coefficient = -1;
					else
						coefficient = 1;
				}
				NextPower = true;
			}
			else if (c >= '0' && c <= '9')
			{
				cin.unget();
				if (NextPower)
				{
					cin >> power;
					//exponent validation - checks if there are exponents that extend the limit [0, 9] 
					if (!ExponentValidation(power, exponentVal))
					{
						cout << "Invalid exponent. This won't be included in the result. " << endl;
					}
					//sums coefficients with same powers and adds them to the array 
					if (polynomial1[power] != 0)
					{
						polynomial1[power] += coefficient;
					}
					//adds new coefficients to the array
					else
						polynomial1[power] = coefficient;

					NextPower = false;
					coefficient = NULL;
				}
				else
				{
					cin >> coefficient;
					//change the coefficient according to its sign (positive or negative)
					coefficient = Coefficient(signOfPolynomial, coefficient);
				}
			}
		}
	}
	if (c == '\n' && coefficient != NULL)
	{
		if (NextPower)
			polynomial1[1] += coefficient;
		else
			polynomial1[0] += coefficient;
	}

	//displays the coefficients and powers of the first polynomial
	/*for (int i = 9; i >= 0; i--)
	{
		if (polynomial1[i] != 0)
			cout << "coefficient = " << polynomial1[i] << "	power = " << i << endl;
	}
	*/

	//initializes all variables, used for polynomial1 to zero 
	coefficient = 0;
	power = 0;
	NextPower = false;
	signOfPolynomial = false;
	checker = true;

	//accepts second polynomial
	cout << "Enter second polynomial: ";
	while (c = cin.get(), c != '\n')
	{
		//polynomial validation  - checks if the polynomial contains unallowed characters
		if (!PolynomialValidation(c, checker))
		{
			cout << "Invalid Polynomial." << endl;
			break;
		}
		else
		{
			if (c == '+' || c == '-')
			{
				//determines whether the coefficient is positive or negative
				signOfPolynomial = SignOfPolynomial(c, signOfPolynomial);
				//power == 1 && coefficient == 0
				if (coefficient && NextPower == NULL)
				{
					polynomial2[0] = 1;
					NextPower = false;
				}
				//power == 1 && coefficient != 0
				else if (NextPower && coefficient != NULL)
				{
					polynomial2[1] += coefficient;
					NextPower = false;
				}
				//power = 0 && coefficient != 0
				else if (!NextPower && coefficient != NULL)
				{
					polynomial2[0] += coefficient;
					NextPower = false;
				}
				coefficient = NULL;
			}
			else if (c == 'x' || c == 'X')
			{
				//coefficient == 0
				if (coefficient == NULL)
				{
					if (signOfPolynomial)
						coefficient = -1;
					else
						coefficient = 1;
				}
				NextPower = true;
			}
			else if (c >= '0' && c <= '9')
			{
				cin.unget();
				if (NextPower)
				{
					cin >> power;
					//exponent validation - checks if there are exponents that extend the limit [0, 9] 
					if (!ExponentValidation(power, exponentVal))
					{
						cout << "Invalid exponent. This won't be included in the result. " << endl;
					}
					//sums coefficients with same powers and adds them to the array 
					if (polynomial2[power] != 0)
					{
						polynomial2[power] += coefficient;
					}
					//adds new coefficients to the array
					else
						polynomial2[power] = coefficient;

					NextPower = false;
					coefficient = NULL;
				}
				else
				{
					cin >> coefficient;
					//change the coefficient according to its sign (positive or negative)
					coefficient = Coefficient(signOfPolynomial, coefficient);
				}
			}
		}
	}


	if (c == '\n' && coefficient != NULL)
	{
		if (NextPower)
			polynomial2[1] += coefficient;
		else
			polynomial2[0] += coefficient;
	}
	//displays the coefficients and powers of the first polynomial
	/*for (int i = 9; i >= 0; i--)
	{
		if (polynomial2[i] != 0)
			cout << "coefficient = " << polynomial2[i] << "	power = " << i << endl;
	}
	*/

	//initialize new array that will be used for the sum of two polynomials
	double sum[10] = {};

	//for loop which adds and displays the sum of two polynomials
	for (int i = 0; i < 10; i++)
	{
		sum[i] = polynomial1[i] + polynomial2[i];
		if (sum[i] > 0)
			cout << "+" << sum[i] << "x" << i;
		else if (sum[i] < 0)
			cout << sum[i] << "x" << i;
	}
	return 0;
}
/**
* Function <code>SignOfPolynomial</code> determines whether the entered coefficient is positive or negative.
* <BR>
* @param c Character which represents the sign in front of the coefficient.
* @param signOfPolynomial Bool value, which shows whether coefficient is positive or negative.
* @return Returns <code>true</code> if the coefficient is positive, and <code>false</code> otherwise.
*/
bool SignOfPolynomial(char c, bool signOfPolynomial)
{
	if (c == '-')
		signOfPolynomial = true;
	else if (c == '+')
		signOfPolynomial = false;
	return signOfPolynomial;
}
/**
* Function <code>Coefficient</code> changes the coefficient from positive to negative according to the sign of coefficient.
* <BR>
* @param signOfPolynomial Allows to understand whether the coefficient should be changed or not.
* @param coefficient Coefficient to be changed.
* @return Returns coefficient.
*/
double Coefficient(bool signOfPolynomial, double coefficient)
{
	if (signOfPolynomial)
		coefficient *= -1;

	return coefficient;
}
/**
* Function <code>PolynomialValidation</code> determines whether the entered polynomial has unallowed characters or not
* <BR>
* @param c Represents the character to be checked.
* @param checker Bool value, which shows whether polynomial is correct or not.
* @return Returns <code>true</code> if the polynomial is correct, and <code>false</code> otherwise.
*/
bool PolynomialValidation(char c, bool checker)
{
	switch (c)
	{
	case '+':
	case '-':
	case 'x':
	case 'X':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case ' ':
		checker = true;
		break;
	default:
		checker = false;
		break;
	}

	return checker;
}
/**
* Function <code>ExponentValidation</code> determines whether the entered exponent extends the allowed range [0, 9] or not.
* <BR>
* @param power Represents the exponent to be checked.
* @param exponentVal Bool value, which shows whether exponent is correct ot not.
* @return Returns <code>true</code> if the exponent is correct, and <code>false</code> otherwise.
*/
bool ExponentValidation(int power, bool exponentVal)
{
	if (power <= 9 && power >= 0)
		exponentVal = true;
	else exponentVal = false;

	return exponentVal;
}