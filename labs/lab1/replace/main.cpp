#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void ReplaceSubstrInStr(string & str, const string & strToSearch, const string & strToReplace)
{
	size_t foundAt = 0;
	string resultStr;
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
			resultStr.append(str, startPos);
		}
	}
	str = resultStr;
}

bool CopyFileWithReplacing(ifstream & input, ofstream & output, const string & strToSearch, const string & strToReplace)
{
	string str;
	while (getline(input, str))
	{
		ReplaceSubstrInStr(str, strToSearch, strToReplace);
		if (!(output << str << '\n'))
		{
			cout << "Failed to save data on disk\n";
			return false;
		}
	}
	if (!output.flush())
	{
		cout << "Failed to save data on disk\n";
		return false;
	}
	return true;
}

bool CopyFileWithReplacing(char* inputFileName, char* outputFileName, const string & strToSearch, const string & strToReplace)
{
	ifstream input(inputFileName);
	if (!input.is_open())
	{
		cout << "Failed to open " << inputFileName << " for reading\n";
		return false;
	}
	ofstream output(outputFileName);
	if (!output.is_open())
	{
		cout << "Failed to open " << outputFileName << " for writing\n";
		return false;
	}
	if (!CopyFileWithReplacing(input, output, strToSearch, strToReplace))
	{
		cout << "Failed to copy file " << inputFileName << "to " << outputFileName << '\n';
		return false;
	}
	return true;
}

int main(int argc, char* argv[])
{
	if (argc != 5)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: replace.exe <input file> <output file> <search string> <replace string>\n";
		return 1;
	}
	char* inputFileName = argv[1];
	char* outputFileName = argv[2];
	string strToSearch = argv[3];
	if (strToSearch.empty())
	{
		cout << "Empty search string\n";
		return 1;
	}
	string strToReplace = argv[4];
	if (!CopyFileWithReplacing(inputFileName, outputFileName, strToSearch, strToReplace))
	{
		cout << "Failed to replace string in file\n";
		return 1;
	}
	return 0;
}