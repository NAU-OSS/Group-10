#include <stdio.h>
#include <math.h>

bool characteristic( char numString[], int& c);
bool mantissa( char numString[], int& numerator, int& denominator );

char number[] = "123.456";
int c, n , d;

const char NULL_TERM = '\0'

// main driver function, checks if the number array has a
// charactertistic and mantissa
int main( int argc, const char* argv[] )
{
  //if the conversion from C strin got integers can take place
  if( characteristic(number, c) && mantissa(number, n, d) )
  {
    //do some math with c, n, and d
  }
  else
  {
    //hande the error on input
  }
}

//numstring may include leading or trailing spaces, unary plus or minus signs, integers, or real numbers.
bool characteristic( char numstring[], int& c )
{
  int numStart, characterEnd, diff, i = 0;
  bool unarySign = false;

  //set c to 0 just in case theres garbage passed into it.
  c = 0;


  //remove the leading white space, ensure valid first char
  do
  {
    if( !checkValid(numString[numStart]) )
    {
      return false;
    }
    numStart++;
  }
  while( numString[numStart] == ' ' );

  //check if first char is unary sign
  if( numString[numStart] == '+' || numString[numStart] == '-' )
  {
    unarySign = true;
    numStart++;
  }

  characterEnd = numStart; //set counter to start of number for speed

  //find the end of the characteristic, or end of string, whichever first, ensuring string is valid number
  while( numString[characterEnd] != '.' || numString[characterEnd] != NULL_TERM )
  {
    if( !checkValid(numString[characterEnd]) && ( numString[characterEnd] != '.' || numString[characterEnd] != NULL_TERM)
    {
      return false;
    }
    characterEnd++;
  }

  //calc diff, this funcitons as the exponent of the first digit in the number
  diff = characterEnd - numStart;
  i = numStart;

  //create the actual number
  while( diff >= 0 && i > characterEnd )
  {
    c += calcNum( numString[i], diff );
    i++;
    diff--;
  }

  //if the number is negative make the final number negative
  if(unarySign && numString[numStart-1] == '-')
  {
    c *= -1;
  }

  return true;
}

// converts the mantissa into a numerator and denominator
// and reports whether or not it succeeds
bool mantissa( char numString[], int& numerator, int& denominator )
{
  // declaring integer variables
  int numStart, mantEnd, diff, i, expval, value = 0;

  // loops while the start of the character array numString has not
  // reached the decimal point or NULL
  while( numString[numStart] != '.' || numString[numStart] != NULL_TERM )
  {

    // checks if the start of the character array numString is valid
    // and does not start with a space or a decimal point
    if( !checkValid(numString[numStart]) && numString[numStart] != ' ' || numString[numStart] != '.')
    {
      return false;
    }

    // increment numStart to get to the next value in the character array numString
    numStart++;

  }

  // initialize the end of the mantissa as the last checked numStart int + 1
  mantEnd = numStart + 1;

  // loops while the mantissa hasn't reached a NULL and is valid
  while( numString[mantEnd] != NULL_TERM || checkValid( numString[numStart] ) )
  {
    // increment the end of the mantissa as long as 
    mantEnd++;
  }

  // initialize the difference of how long the non-mantissa digits
  // are from the mantissa digits
  diff = mantEnd - numStart;

  // initialize exponent value as the difference calculated beforehand
  expval = diff

  // initialize i as the start of hte mantissa
  i = numStart;

  // loop from the beginning to the end of the mantissa
  while( expval > 0 && i > mantEnd )
  {
    // add to the value variable using the calcNum helper function
    value += calcNum( numString[i], expval );

    // increment i to go to the next mantissa digit
    i++;

    // decrement the exponent value when going to the next digit
    expval--;
  }

  // set the numerator as the calculated value above
  numerator = value;

  // calculate the denominator using the difference
  denominator = calcNum( '1', diff );

  return true;

}

// converts the character of an integer into the integer
int calcNum( char number, int exp )
{
  int i = exp;
  int place = 1;
  //make sure char is actually a number
  if( number >= '0' && number <= '9' )
  {
    //create multiple of 10 to get correct value of number
    while( i > 0 )
    {
      place*=10;
      i--;
    }
    return (int) (number - '0')*place;
  }
  else
  {
    return -1;
  }
}

//ensures char is valid
bool checkValid( char value )
{
  if(value == NULL_TERM || (value != ' ' && value != '-' && value != '+' &&
     value < '0' && value > '9' && value != '.')
  {
    return false;
  }
  return true;
}
