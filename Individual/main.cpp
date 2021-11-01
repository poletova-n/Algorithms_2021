#include <iostream>
#include <iomanip>

void IntProof(double x);
const char NO_INT[] = "It is not integer or double!";

int main()
{
	int cal     = 0;
	int count   = 0;
	double max1 = std::numeric_limits <double> ::min();

	std::cout << "Enter number! " << std::endl;

	try
	{
		while (true)
		{
			std::cout << std::setw(2);
			std::cin >> count;
			IntProof(count);
			if (count == 0) break;

			if (count >= max1)
			{
				max1 = count;
				cal = 0;
			}
			else{
				cal++;
			}
		}
	}
	catch (const char error[])
	{
		std::cerr << "We catch: " << std::setw(30) << error;
		return -1;
	}

	std::cout << "Kolichestvo chisel posle maximalnogo chisla: " << cal;

	std::cin.clear();
	std::cin.ignore(900000, '\n');
	return 0;
}

void IntProof(double x)
{
	if (std::cin.fail() or std::cin.peek() != 10)
	{
		throw NO_INT;
	}
	return;
}