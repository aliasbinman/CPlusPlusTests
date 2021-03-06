// CPlusPlusTests.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include "TestBase.h"

// Declarations for functions in the tests

extern int Double(int a);
extern bool IsNegative(int a);
extern bool IsPrime(int a);
extern int GCD(int a, int b);


// Test1
int REF_Double(int a)
{
	return a*2;
}

//Test2
bool REF_IsNegative(int a)
{
	return a<0;
}

//Test3
bool REF_IsPrime(int a)
{
	if(a <2 )
		return false;


	for(int i=2; i <=a/2; i++)
	{
		int v = a/i;
		if( (v*i) == a)
			return false;
	}

	return true;
}


//Test3
bool GoesInto(int a, int b)
{
	if( ((b/a)*a) ==b )
		return true;

	return false;
}

int REF_GCD(int a, int b)
{
	int min = a<b ? a : b;

	for(int i=min; i>0; i--)
	{
		if( GoesInto(i,a) && GoesInto(i,b))
			return i;
	}

	return 1;
}



void Test1()
{
#if TEST==1
	int num,t1,t2;
	    
	cout << "\nThis test will ask for a number and tell you what the number is doubled\n";

	while(1)
	{
		cout << "\nEnter a number (or 0 to exit)\n";
		cin >> num;
		if(num==0) break;

		t1 = Double(num);
		t2 = REF_Double(num);

		if(t1==t2)
		{
			cout << "\nCORRECT the answer is " << t1 << "\n";
		} 
		else
		{
			cout << "\nINCORRECT the answer is " <<t2 << ",  your answer was " << t1 << "\n";
		}
	}
#endif
}

void Test2() 
{
#if TEST==2
	int num;
	
	bool t1,t2;
	cout << "\nThis test will ask for a number and tell you if the number is negative or not\n";

	while(1)
	{
		cout << "\nEnter a number (or 0 to exit)\n";
		cin >> num;
		if(num==0) break;

		t1 = IsNegative(num);
		t2 = REF_IsNegative(num);

		if(t1==t2)
		{
			cout << "\nCORRECT the answer is " <<  (t1 ? "true" : "false") << "\n";
		} 
		else
		{
			cout << "\nINCORRECT the answer is " << (t2 ? "true" : "false")  << ",  your answer was " << (t1 ? "true" : "false")  << "\n";
		}
	}
#endif
}

void Test3()
{
#if TEST==3
	int num;
	
	bool t1,t2;
	cout << "\nThis test will ask for a number and tell you if the number is prime or not\n";

	while(1)
	{
		cout << "\nEnter a number (or 0 to exit)\n";
		cin >> num;
		if(num==0) break;

		if((num >0) && (num <0x7fffffff))
		{
			t1 = IsPrime(num);
			t2 = REF_IsPrime(num);

			if(t1==t2)
			{
				cout << "\nCORRECT the answer is " <<  (t1 ? "true" : "false") << "\n";
			} 
			else
			{
				cout << "\nINCORRECT the answer is " << (t2 ? "true" : "false")  << ",  your answer was " << (t1 ? "true" : "false")  << "\n";
			}
		}
		else
		{
				cout << "\nNumber out of range,  Try again \n";
		
		}

	}
#endif
}


void Test4()
{
#if TEST==4
	int num1, num2;
	
	int t1,t2;
	cout << "\nThis test will ask for two numbers and tell you the Greates Common Divisor\n";

	while(1)
	{
		cout << "\nEnter a number (or 0 to exit)\n";
		cin >> num1;
		if(num1==0) break;

		cout << "\nEnter another number\n";
		cin >> num2;

		t1 = GCD(num1,num2);
		t2 = REF_GCD(num1,num2);

		if(t1==t2)
		{
			cout << "\nCORRECT the answer is " <<  t1 << "\n";
		} 
		else
		{
			cout << "\nINCORRECT the answer is " << t2  << ",  your answer was " << t1  << "\n";
		}

	}
#endif
}



void Test5() { }
void Test6() { }
void Test7() { }
void Test8() { }
void Test9() { }








int main()
{
	printf("Test %d\n\n", TEST);

	switch (TEST)
	{
	case 1:
		Test1();
		break;
	case 2:
		Test2();
		break;
	case 3:
		Test3();
		break;
	case 4:
		Test4();
		break;
	case 5:
		Test5();
		break;
	case 6:
		Test6();
		break;
	case 7:
		Test7();
		break;
	case 8:
		Test8();
		break;
	case 9:
		Test9();
		break;

	default:
		printf("Unknown Test %d\n\n", TEST);
		break;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
