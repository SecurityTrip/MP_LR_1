#include <iostream>
#include <string>

using namespace std;
string repeat;

double check_input(string flag)																//Проверка ввода чисел
{		
	if (flag == "double")
	{
		double in_value;																	//Объявление переменной как double для ввода скорости
		cin >> in_value;
		while ((cin.fail()) || (cin.peek() != '\n') || in_value < 0)						//Проверка не введена ли отрицательная скорость или допущена ошибка при вводе
		{
			cin.clear();																	//Очищает флаг ошибки cin
			cin.ignore(99999999, '\n');														//Очищение буфера на заданное число символов и переходит к следующей новой строке чтобы игнорировать что-либо еще в той же строке
			cout << "Wrong type of input data, try again" << endl;
			cout << "Enter the speed in the selected units" << endl;
			cin >> in_value;
		}
		return in_value;
	}
	else if (flag == "integer")
	{
		int in_value;																		//Объявление переменной как integer для ввода начальные единиц измерения скорости
		cin >> in_value;
		while ((cin.fail()) || (cin.peek() != '\n') || in_value <0)							//Проверка не допущена ли ошибка при вводе
		{
			cin.clear();																	//Очищает флаг ошибки cin
			cin.ignore(99999999, '\n');														//Очищение буфера на заданное число символов и переходит к следующей новой строке чтобы игнорировать что-либо еще в той же строке
			cout << "Wrong type of input data, try again" << endl;
			cout << "Select the number of initial speed units" << endl;
			cout << "1.m/s" << endl;
			cout << "2.km/h" << endl;
			cin >> in_value;
		}
		return in_value;
	}
}

string repeat_check()																		//Проверка повторения программы
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
	while (repeat != "N" && repeat != "n")													//Пока введена не N или n программа работает
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
		if (choose == 1)																	//Перевод из м/с в км/ч
		{
			output_value = speed * 3.6;
			cout << "Speed in km/h = " << output_value << endl;
		}
		if (choose == 2)																	//Перевод из км/ч в м/с
		{
			output_value = speed / 3.6;
			cout << "Speed in m/s = " << output_value << endl;
		}

		repeat = repeat_check();															//Вызов функции проверки продолжения программы
	}
	return 0;
}
