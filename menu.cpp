#include "hw09.h"

void LargeInt::menu(){
	
	
	/*LargeInt a("-3");
	LargeInt b("-5");
	LargeInt sum = b - a;	
	cout << "a.sign: " << a.sign << '\n';
	cout << "b.sign: " << b.sign << '\n';
	cout << a.compareTo(b) << "\n\n";
	cout << sum.getVal() << '\n';*/

	int choice;

	bool doMenu = true;
	string one;
	string two;

	do
	{
		
		cout << "Options:\n";
		cout << "1.  Multiply\n";
		cout << "2.  Add\n";
		cout << "3.  Subtract\n";
		cout << "4.  Exit\n";
		
		cout << "Your choice: ";
		cin >> choice;	

		switch(choice)
		{
			case 1:
			{
				cin.ignore(1000, '\n');
				cin.clear();
				
				cout << "\nNum one: ";
				getline(cin, one);
				LargeInt numOne(one);
				
				cout << "Num two: ";
				getline(cin, two);
				LargeInt numTwo(two);
				
				cout << "Num one * Num two = " << 
				numOne.getVal() << " * " << numTwo.getVal() << " = ";
				
				LargeInt product = numOne * numTwo;
				cout << product.getVal() << '\n';
				break;
			}
		
			case 2:
			{
				cin.ignore(1000, '\n');
				cin.clear();
				
				cout << "\nNum one: ";
				getline(cin, one);
				LargeInt numOne(one);

				cout << "Num two: ";
				getline(cin, two);
				LargeInt numTwo(two);
				
				cout << "Num one + Num two = " << 
				numOne.getVal() << " + " << numTwo.getVal() << " = ";
				
				LargeInt sum = numOne + numTwo;
				cout << sum.getVal() << '\n';
				break;
			}

			case 3:
			{

				cin.ignore(1000, '\n');
				cin.clear();
				
				cout << "\nNum one: ";
				getline(cin, one);
				LargeInt numOne(one);

				cout << "Num two: ";
				getline(cin, two);
				LargeInt numTwo(two);
				
				cout << "Num one - Num two = " << 
				numOne.getVal() << " - " << numTwo.getVal() << " = ";
				
				LargeInt dif = numOne - numTwo;
				cout << dif.getVal() << '\n';
				break;
			}

			case 4:
			{
				doMenu = false;
				break;
			}

		}
	} while(doMenu);
}
