#include <stdio.h>
#include<math.h>
#include <stdbool.h>

//Function prototypes

bool is_palindrome();
bool is_prime(int n);
int reversed(int n);
bool reversible(int n);

int main()
{
	int count=0;
	int rps,lhs,rhs,ps;
	printf("Program to generate the first 10 reversible primes that are not palindromes: \n");
	for(rps=0;rps>=0;rps++)                                    
	{
		int ps = reversed(rps);

        if(reversible(rps) == true && reversible(ps) == true)
        {
			lhs = sqrt(rps);
            rhs = sqrt(ps);
			
            if(is_prime(lhs) == 1 && is_prime(rhs))
            {
				if(is_palindrome(rps))
                {
					printf("%d \n",rps);
                    count++;
                    if(count==10)
                    {
						break;
					}
                }

            }
        }
			
	}	
	return 0;
}

//Function definitions
bool is_prime(int n)
{
	int i;
	bool check_prime=true;
	
	if(n==0 || n==1 )
	{
		check_prime=false;
	}
	
	for(i=2;i<=(n)/2;i++)
	{
		if(n%i == 0)
		{
			check_prime=false;
			break;
		}
		
	}
	return check_prime;
}

int reversed(int n)
{
	int digit;
	int reversed=0;
	while(n!=0)
	{
		digit=n%10;
		reversed= (reversed*10)+digit;
		n=n/10;
	}
	return reversed;
}

bool is_palindrome(int n)
{
	bool palindrome_check=true;
	if(reversed(n)==n)
	{
		palindrome_check = false;
	}
	return palindrome_check;
}

bool reversible(int n)
{
	int i;
    for(i=1; i * i <= n; i++ )
    {
        if((n % i == 0) && (n / i == i))
        {
            return true;
        }
    }
    return false;
}

