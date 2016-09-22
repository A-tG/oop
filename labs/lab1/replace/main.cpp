#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void ReplaceSubstrInStr(string & str, const string & strToSearch, const string & strToReplace)
{
	size_t foundAt = 0;
	string resultStr = "";
	while (foundAt != string::npos)
	{
		size_t startPos = foundAt;
		foundAt = str.find(strToSearch, foundAt);
		if (foundAt != string::npos)
		{
			resultStr.append(str, startPos, foundAt - startPos);
			resultStr.append(strToReplace);
			foundAt += strToSearch.length();
		}
		else
		{
			resultStr.append(str, startPos, str.length() - startPos);
		}
	}
	str = resultStr;
}

bool ReplaceStrInFile(ifstream & input, ofstream & output, const string & strToSearch, const string & strToReplace)
{
	string str;
	while (getline(input, str))
	{
		ReplaceSubstrInStr(str, strToSearch, strToReplace);
		str.append("\n");
		if (!(output << str))
		{
			cout << "Failed to save data on disk\n";
			return false;
		}
	}
	return true;
}

int main(int argc, char * argv[])
{
	if (argc != 5)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: replace.exe <input file> <output file> <search string> <replace string>\n";
		return 1;
	}
	ifstream input(argv[1]);
	if (!input.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}
	ofstream output(argv[2]);
	if (!output.is_open())
	{
		cout << "Failed to open " << argv[2] << " for writing\n";
		return 1;
	}
	string strToSearch = argv[3];
	if (strToSearch.empty())
	{
		cout << "Empty search string\n";
		return 1;
	}
	string strToReplace = argv[4];
	if (!ReplaceStrInFile(input, output, strToSearch, strToReplace))
	{
		cout << "Failed to replace string in file\n";
		return 1;
	}
	if (!output.flush())
	{
		cout << "Failed to save data on disk";
	}
	return 0;
}