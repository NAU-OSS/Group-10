#include <stdio.h>
#include <math.h>

bool characteristic( char numString[], int& c);
bool mantissa( char numString[], int& numerator, int& denominator );

char number[] = "123.456";
int c, n , d;

const char NULL_TERM = '\0'

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

bool mantissa( char numString[], int& numerator, int& denominator )
{
  int numStart, mantEnd, diff, i, expval, value = 0;

  while( numString[numStart] != '.' || numString[numStart] != NULL_TERM )
  {
    if( !checkValid(numString[numStart]) && numString[numStart] != ' ' || numString[numStart] != '.')
    {
      return false;
    }
    numStart++;
  }

  mantEnd = numStart + 1;

  while( numString[mantEnd] != NULL_TERM || checkValid( numString[numStart] ) )
  {
    mantEnd++;
  }

  diff = mantEnd - numStart;

  expval = diff
  i = numStart;
  while( expval > 0 && i > mantEnd )
  {
    value += calcNum( numString[i], expval );
    i++;
    expval--;
  }

  numerator = value;
  denominator = calcNum( '1', diff );

  return true;

}

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
