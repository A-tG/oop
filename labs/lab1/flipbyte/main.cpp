#include <iostream>
#include <string>

using namespace std;

bool IsNumericNonNegativeInt(const string & numberStr)
{
	for (char ch : numberStr)
	{
		if (!isdigit(ch))
		{
			return false;
		}
	}
	return true;
}

unsigned char FlipByte(unsigned char number)
{
	unsigned char result;
	result = (number >> 4) | (number << 4);
	result = ((result >> 2) & 0x33) | ((result << 2) & 0xCC);
	result = ((result >> 1) & 0x55) | ((result << 1) & 0xAA);
	return result;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: flipbyte.exe <number(byte)>\n";
		return 1;
	}
	string numberStr(argv[1]);
	if (!IsNumericNonNegativeInt(numberStr))
	{
		cout << "First argument must be non-negative number\n";
		return 1;
	}
	int number = stoi(numberStr);
	if ((number < 0) && (number > 255))
	{
		cout << "Number must be 0-255\n";
		return 1;
	}
	unsigned char byte = number;
	cout << "Original " << static_cast<int>(byte) << '\n' 
		<< "Flipped " << static_cast<int>(FlipByte(byte)) << '\n';
	return 0;
}