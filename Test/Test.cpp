#include "./../TextWiz/TextWiz.h"
#include <iostream>

using namespace std;

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined(WINNT) || defined(__WINNT) || defined(__WINNT__) || defined(__WIN64) || defined(_WIN64)
#elif defined(__linux__) || defined(__gnu_linux__) || defined(linux) || defined(__linux)
#endif

string operator+(string v1, size_t v2) { return v1 + to_string(v2); }
string operator+(size_t v1, string v2) { return to_string(v1) + v2; }

int main()
{
	try
	{
		TextWiz testFile("ORIGIN"), Expectation("RESULT");
		TextWiz_Logger logger;
		cout << "Test Program for TextWiz by xiaobsh\n\n";
		cout << "Time: " << TextWiz_GetTime("%F %T") << "\n";

		testFile.AddAtLine(5, "Text to be added to Line 5");
		testFile.AddAtLine(42, "Text to be added to Line 42");
		testFile.AddAtLine(55, "Text to be added to Line 55");
		testFile.AddAtLine(71, testFile.GetByLine(71));
		testFile.AddAtLine(103, "Text to be added to Line 103");
		testFile.AddAtLine(137, testFile.GetCurrentContent());
		testFile.save();

		std::vector<TextWiz::TextWiz_Position> VectorToSaveResults;
		testFile.FindTextInEachLine("license", VectorToSaveResults);
		for (TextWiz::TextWiz_Position i : VectorToSaveResults)
		{
			testFile.AddAtLine(150, "Line: " + to_string(i.line) + " Column: " + to_string(i.column) + " ");
		}
		testFile.AddAtLine(1, "Replacement Counts: " + to_string(testFile.ReplaceTextInEachLine("the", "tthhee")));
		testFile.FindTextInEachLine("software", VectorToSaveResults);
		for (TextWiz::TextWiz_Position i : VectorToSaveResults)
		{
			testFile.append(to_string(i.line * i.column));
			// testFile.DelLine(i.column); // Max: 199
			testFile.DelLine(i.line);
		}
		// testFile.DelLine(5);
		testFile.exit();
		logger.open("ORIGIN");
		logger.append("Going to exit!\n");
		logger.close();
		testFile.open("ORIGIN");
		Expectation.exit();
		Expectation.open("RESULT"); // To avoid the influence from CRLF...
		if (testFile.content != Expectation.content) throw 2;
		testFile.close();
	}
	catch (const int errorNum)
	{
		printf("\033[0m\033[1;31m%s\033[0m", "[  FAILED  ]");
		cout << " Error Code: " + to_string(errorNum) << "\n";
		return errorNum;
	}
	catch (const std::exception&)
	{
		printf("\033[0m\033[1;31m%s\033[0m", "[  FAILED  ]");
		cout << " Internal Error!\n";
		return 1;
	}
	printf("\033[0m\033[1;32m%s\033[0m", "[  PASSED  ]");
	cout << "\n";
	return 0;
}


