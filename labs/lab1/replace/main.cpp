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
			resultStr.append(str, startPos, str.length() - startPos);
		}
	}
	str = resultStr;
}

bool CopyFileLinesStringsReplacing(ifstream & input, ofstream & output, const string & strToSearch, const string & strToReplace)
{
	string str;
	while (getline(input, str))
	{
		ReplaceSubstrInStr(str, strToSearch, strToReplace);
		if (!(output << str << endl))
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

bool CopyFileStringReplacing(char* inputFile, char* outputFile, const string & strToSearch, const string & strToReplace)
{
	ifstream input(inputFile);
	if (!input.is_open())
	{
		cout << "Failed to open " << inputFile << " for reading\n";
		return false;
	}
	ofstream output(outputFile);
	if (!output.is_open())
	{
		cout << "Failed to open " << outputFile << " for writing\n";
		return false;
	}
	if (!CopyFileLinesStringsReplacing(input, output, strToSearch, strToReplace))
	{
		cout << "Failed to copy file " << inputFile << "to " << outputFile << endl;
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
	char* inputeFileName = argv[1];
	char* outputFileName = argv[2];
	string strToSearch = argv[3];
	if (strToSearch.empty())
	{
		cout << "Empty search string\n";
		return 1;
	}
	string strToReplace = argv[4];
	if (!CopyFileStringReplacing(inputeFileName, outputFileName, strToSearch, strToReplace))
	{
		cout << "Failed to replace string in file\n";
		return 1;
	}
	return 0;
}