#include <iostream>
#include <string>

using namespace std;
string repeat;

double check_input(string flag)
{		
	if (flag == "double")
	{
		double in_value;
		cin >> in_value;
		while ((cin.fail()) || (cin.peek() != '\n') || in_value < 0)
		{
			cin.clear();
			cin.ignore(99999999, '\n');
			cout << "Wrong type of input data, try again" << endl;
			cout << "Enter the speed in the selected units" << endl;
			cin >> in_value;
		}
		return in_value;
	}
	else if (flag == "integer")
	{
		int in_value;
		cin >> in_value;
		while ((cin.fail()) || (cin.peek() != '\n') || in_value <0)
		{
			cin.clear();
			cin.ignore(99999999, '\n');
			cout << "Wrong type of input data, try again" << endl;
			cout << "Select the number of initial speed units" << endl;
			cout << "1.m/s" << endl;
			cout << "2.km/h" << endl;
			cin >> in_value;
		}
		return in_value;
	}
}

string repeat_check()
{
	cout << "\nRepeat? (Y/N) " << endl;
	cin >> repeat;
	while (((repeat == "Y") || (repeat == "y") || (repeat == "N") || (repeat == "n")) != 1)
	{
		cout << "Unidentified operator, try again" << endl;
		cout << "Repeat? (Y/N) " << endl;
		cin >> repeat;
		cout << endl;
	}
	return repeat;
}

int main()
{
	while (repeat != "N" && repeat != "n")
	{
		cout << "Select the number of initial speed units" << endl;
		cout << "1.m/s" << endl << "2.km/h" << endl;
		int choose;
		choose = check_input("integer");
		while (choose != 1 && choose != 2)
		{
			cout << "Wrong number, try again" << endl;
			choose = check_input("integer");
		}
		double speed;
		cout << "Enter the speed in the selected units" << endl;
		speed = check_input("double");
		double output_value;
		if (choose == 1)
		{
			output_value = speed * 3.6;
			cout << "Speed in km/h = " << output_value << endl;
		}
		if (choose == 2)
		{
			output_value = speed / 3.6;
			cout << "Speed in m/s = " << output_value << endl;
		}

		repeat = repeat_check();
	}
	return 0;
}
