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

bool StrToByte(const string & numberStr, uint8_t & byte)
{
	if (!IsNumericNonNegativeInt(numberStr))
	{
		return false;
	}
	try
	{
		int number = stoi(numberStr);
		if ((number < 0) || (number > 255))
		{
			return false;
		}
		byte = number;
		return true;
	}
	catch (const exception & err)
	{
		cout << err.what() << '\n';
		return false;
	}
}

uint8_t FlipByte(uint8_t number)
{
	uint8_t result;
	result = (number >> 4) | (number << 4);
	result = ((result >> 2) & 0b00110011) | ((result << 2) & 0b11001100);
	result = ((result >> 1) & 0b01010101) | ((result << 1) & 0b10101010);
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
	uint8_t byte;
	if (!StrToByte(numberStr, byte))
	{
		cout << "First argument must be integer number 0-255\n";
		return 1;
	}
	cout << "Original " << static_cast<int>(byte) << '\n' 
		<< "Flipped " << static_cast<int>(FlipByte(byte)) << '\n';
	return 0;
}