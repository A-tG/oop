#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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
	if (0 == strToSearch.length())
	{
		cout << "Empty search string\n";
		return 1;
	}
	string strToReplace = argv[4];
	if (0 == strToReplace.length())
	{
		cout << "Empty replace string\n";
		return 1;
	}
	string ln;
	while (getline(input, ln))
	{
		size_t foundAt = 0;
		string lnTemp = "";
		while (foundAt != string::npos)
		{
			size_t startPos = foundAt;
			foundAt = ln.find(strToSearch, foundAt);
			if (foundAt != string::npos)
			{
				lnTemp += ln.substr(startPos, foundAt - startPos);
				lnTemp += strToReplace;
				foundAt += strToSearch.length();
			}
			else
			{
				lnTemp += ln.substr(startPos, ln.length() - startPos);
			}
		}
		lnTemp += '\n';
		if (!(output << lnTemp))
		{
			cout << "Failed to save data on disk";
			return 1;
		}
	}
	if (!output.flush())
	{
		cout << "Failed to save data on disk";
	}
	return 0;
}