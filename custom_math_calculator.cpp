/*
	Author : oltyx
	It was written using Gedit 3.18.3.
	This source code works compiled with g++ or gcc compiler.
	This program is made to work as binary executed from a terminal/console after it is properly compiled.
	Compiled with g++ and tested on Ubuntu 16.04.
*/
#include <iostream>
#include <cmath>
using namespace std;
unsigned short int ind; // This variable is used as an index, whenever is needed in the entire program.

bool primality_test(unsigned long int nr)	
{
    /*
        This function verifies if a given number 'nr' is prime.
    */
	if (nr == 0 || nr == 1)
		return 0; // 0 and 1 are not prime numbers
	else
	{
		unsigned short int divisor;
		for (divisor = 2; divisor <= sqrt(nr); divisor++)
		{
			if (nr % divisor == 0)
				return 0;
		}
		return 1;
	}
}

void generating_prime_numbers(unsigned long int nr)
{   
    /*
        This function is generating prime numbers for a value smaller or equal to 'nr' and outputs it to the standard output.
    */
	for ( ind = 2; ind <= nr; ind++ )
	{
		if ( primality_test ( ind ) )
			cout << ind << " ";
	}
}

void prime_factorization(unsigned long int nr)	
{
    /*
        This function is printing to standard output the prime factorization of a given number 'nr' using exponential notation.
    */
	unsigned short int power = 0, copy = nr;
    ind = 2;
	while ( (ind <= copy/2) && ( nr != 1 ) )
	{
		if (nr % ind == 0 )
		{
			nr /= ind;
			power++;
		}
		else
		{
			if (power != 0)
			{
				cout << ind << '^' << power << " * ";
				power = 0;
			}
			ind++;
		}
	}
	if (power != 0)
		cout << ind << '^' << power;
	else
		cout << copy << "^1";
}

unsigned long int gcd_2_nrs ( unsigned long int nr1 , long int nr2)
{
    /*
        This function returns the Greatest Common Divisor of two numbers. (works also for negative numbers)
    */
	if ( nr2 != 0)
	        return gcd_2_nrs ( fabs(nr2) , nr1 % nr2 );
	else
	        return (fabs(nr1));
}

long int gcd ( unsigned short int num , long int list[] )
{
    /*
        This function returns the greatest common divisor for N numbers. 
    */
     long int gcd_var, val1,val2 ;
     val1 = list[0];
     val2 = list[1];
     if (num==2)
             return gcd_2_nrs ( val1, val2 );
     else
     {
           for ( ind=2 ; ind < num  ; ind++)
           {
             	gcd_var = gcd_2_nrs ( val1, val2 );
     	        val1 = gcd_var;
             	val2 = list[ind];
            }
     }
     return gcd_2_nrs(val1,val2);
}

void ext_euclid ( long int a, long int b, long int &x, long int &y, long int &t) 
{
	/* 
	    This function computes the extended euclidean algorithm and the values are retained in x , y and t (they use the memory address)
	*/
	long int x1,x2,y1,y2,q,r;
   	if ( b==0)
 	{
		t = a;
    	x = 1;
		y = 0;
	}
	else
	{
		 x2 = 1 ; x1 = 0 ; y2 = 0 ; y1 = 1;
   		 while ( b > 0)
		 {		
				q = a / b ; r = a % b ; x = x2 - q*x1 ; y = y2 - q*y1 ;
       			 a = b ; b = r ; x2 = x1 ; x1 = x ; y2 = y1 ; y1 = y;		
		 }
		 t = a;
    	 x = x2;
		 y = y2;
	}
   
}

void proper_divisors ( long int nr, long int div[] , long int &nr_of_elem) 
{	
    /*
        This function returns the proper divisors of a number and retains them along the program in the one-dimensional array 'div'.
    */
	nr_of_elem = 0;
	for ( ind = 2 ; ind<= nr/2 ; ind++ )
	{
		if ( nr % ind == 0 )
		{
			div[nr_of_elem] = ind;
			nr_of_elem++;
		}
	}
}

long int conv_to_base_X ( long int num , unsigned short int base) 

{
	/* 
	    This function converts a decimal number to a base smaller or equal to 10.
	*/
	long int pow , new_repr;
	pow = 1;
	new_repr = 0;
	while ( num != 0 )
	{
		new_repr += (num % base) * pow;
		pow *= 10;
		num /= base;
	}
	return new_repr;
}

unsigned short int num_of_digits ( long int num) 
{
    /* 
        This function returns the number of digits for a number.
    */    
	ind = 0;
	while ( num != 0)
	{
		ind ++;
		num /= 10;
	}
	return ind;
}

long int effic_expon_mod_n ( long int x, long int y, long int n) 

{
	/* 
	    This is the efficient exponentiation modulo n algorithm.
	*/
	long int r , b , bin ;
	unsigned short int nr_of_dig;
	bin = conv_to_base_X ( y , 2) ;
	nr_of_dig = num_of_digits ( bin );
	long int bin_list [ nr_of_dig ];
	ind = 0;	
	while ( bin != 0 )
	{
		bin_list [ind] = bin % 10;
		bin /= 10;
		ind ++;
	}	
	r = 1 ;
	b = x ;
	for ( ind = 0 ; ind < nr_of_dig ; ind++)
	{
		if ( bin_list[ind] == 1 )
		{
			r = (r*b) % n;
		}
		b = (b*b) % n;
	}
	return r;
}

int main()
{
    /* 
        This is the main subroutine (function).
    */
	char task;
	unsigned long int nr;
	cout << "1.Verify the primality of a number.\n";
	cout << "2.Generating prime numbers until a value X.\n";
    cout << "3.Prime factorization for a chosen number.\n";
	cout << "4.Greatest Common Divisor for multiple numbers.\n";
	cout << "5.The Extended Euclidean algorithm.\n";
	cout << "6.Proper divisors for a number.\n";
	cout << "7.Convert a number to a base smaller or equal to base 10.\n";
	cout << "8.Efficient exponentiation modulo n (x^y mod n):\n";
	while (1)
	{
		cout << "Type the corresponding number for the operation you want to execute:";
		cin >> task;
		switch (task)
		{
		case '1':
			{
				cout << "Number to be verified:";
				cin >> nr;
				primality_test(nr) ? cout << nr << " is a prime number.\n" : cout << nr <<" is not a prime number.\n";
				cout<<"\n"<<endl;
				break;
			}
		case '2':
			{
				cout << "The last value until you want to generate prime numbers:";
				cin >> nr;
				generating_prime_numbers(nr);
				cout <<"\n"<<endl;
				break;
			}
		case '3':
			{
				cout << "The number that needs to be factorized.";
				cin >> nr;
				prime_factorization(nr);
				cout << "\n" << endl;
				break; 
			}
		case '4':
		    {
		    	cout << "Enter the amount of numbers:";
		    	cin >> nr;
		    	cout << "Please type in the numbers:";
		    	long int list[nr];
		    	for ( ind = 0 ; ind < nr ; ind++)
		    	{
		    		cin	>> list[ind];
		    	}
		    	cout << "The GCD for these numbers is :"	<< gcd ( nr , list)	<<"\n"<<endl;
		    	break;
		    }
		case '5':
			{
				long int nr1 , nr2 , x, y ,gcd;
				cout << "Insert the first value:\n";
				cin >> nr1;
				cout << "Insert the second value:\n";
				cin >> nr2;
				ext_euclid ( nr1, nr2, x , y, gcd);
                cout << "The ecuation becomes: " << nr1 << " * " << x << " + " << nr2 << " * " << y << " = " << gcd << "\n" <<endl;
				break;
			}
		case '6':
			{				
				long int val , nr_of_elem=0;				
				cout << "Input the number:";
				cin	>> val;
			    long int div [ val / 2 ];	
				proper_divisors ( val , div , nr_of_elem );
				cout << "The proper divisors of the number are:";
				for (ind = 0 ; ind < nr_of_elem ; ind++ )
				{
					cout << div[ind] << ' ';
				}
				cout <<"\n"<< endl;
				break;
			}
		case '7':
			{
				long int num;
				unsigned short int base;				
				cout << "Input the number that you want to convert:"; cin >> num;
				cout << "Input the base in which you want to convert this number:"; cin >> base;
				cout << "This is the representation in base " << base << ":  " << conv_to_base_X ( num , base ) << "\n" << endl ;
				break;
			}
		case '8':
			{
                long int base , exp , mod ;				
				cout << "Input the base x:" ; cin >> base;
				cout << "Input the exponent y:" ; cin >> exp;
				cout << "Input the n:" ; cin >> mod;
				cout << "The result of: " << base << "^" << exp << " modulo " << mod << " is: " << effic_expon_mod_n ( base , exp , mod ) << "\n" << endl;
                break;
			}
		default:
           {
				cout << "You didn't introduce a correct number!\n";
		   }	
		}
	}
	return 1;
}
