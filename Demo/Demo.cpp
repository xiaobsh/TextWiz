#include "./../TextWiz/TextWiz.h"
#include <iostream>

using namespace std;

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined(WINNT) || defined(__WINNT) || defined(__WINNT__) || defined(__WIN64) || defined(_WIN64)
#include <conio.h>
char getChar()
{
	char c;
	c = _getch();
	cout << c << endl;
	return c;
}
#elif defined(__linux__) || defined(__gnu_linux__) || defined(linux) || defined(__linux)
char getChar()
{
	char c;
	system("stty -icanon");
	// system("stty -echo");
	c = getchar();
	system("stty icanon");
	// system("stty echo");
	// cout << c << endl;
	return c;
}
#endif

string operator+(string v1, int v2) { return v1 + to_string(v2); }
string operator+(int v1, string v2) { return to_string(v1) + v2; }


int main()
{
	TextWiz testFile;
	TextWiz_Logger logger(TextWiz_GetTime("%F") + ".log");
	testFile.open("hosts");
	logger.append("[" + TextWiz_GetTime_Milliseconds() + "] " + "Operation: Open file 'hosts'" + "\n");
	
	char choice;
	cout << "Test Program for TextWiz by xiaobsh" << endl <<endl;
	cout << "Time: " << TextWiz_GetTime("%F %T") << endl;
	cout << "0 Exit\t\t1 Get content\t2 Get by line\r\n3 Add a line\t4 Delete a line\t5 Save to file\r\n6 Search text\t7 Replace text\t8 Swap lines" << endl << "Please enter your choice: ";
	choice = getChar();
	logger.append("[" + TextWiz_GetTime_Milliseconds() + "] " + "Operation: User entered '" + to_string(choice) + "'\n");

	while (choice != '0')
	{
		switch (choice)
		{
		case '1':
		{
			logger.append("[" + TextWiz_GetTime_Milliseconds() + "] Operation: Output current content\n");
			cout << "================================Beginning================================" << endl;
			cout << testFile.GetCurrentContent() << endl;
			cout << "==================================Ending==================================" << endl;
			break;
		}
		case '2':
		{
			int line;
			string s;
			cout << "Please enter the line number: ";
			cin >> line;
			cout << "================================Beginning================================" << endl;
			cout << testFile.GetByLine(line) << endl;
			cout << "==================================Ending==================================" << endl;
			logger.append("[" + TextWiz_GetTime_Milliseconds() + "] " + "Operation: Get text of Line " + to_string(line) + "\n");
			break;
		}
		case '3':
		{
			int line;
			string s;
			cout << "Please enter the line number: ";
			cin >> line;
			cout << "To add: ";
			cin >> s;
			testFile.AddAtLine(line, s);
			logger.append("[" + TextWiz_GetTime_Milliseconds() + "] " + "Operation: Insert a new line '" + s + " before Line " + to_string(line) + "\n");
			break;
		}
		case '4':
		{
			int line;
			cout << "Please enter the line number: ";
			cin >> line;
			testFile.DelLine(line);
			logger.append("[" + TextWiz_GetTime_Milliseconds() + "] " + "Operation: Delete Line" + line + "\n");
			break;
		}
		case '5': testFile.save(); logger.append("[" + TextWiz_GetTime_Milliseconds() + "] " + "Operation: Save file 'hosts'\n"); break;
		case '6':
		{
			string s;
			cout << "Find: ";
			cin >> s;
			std::vector<TextWiz::TextWiz_Position> VectorToSaveResults;
			testFile.FindTextInEachLine(s, VectorToSaveResults);
			cout << endl << "Results:" << endl;
			for (auto i : VectorToSaveResults)
			{
				cout << "Line: " << i.line << " Column: " << i.column << endl;
			}
			logger.append("[" + TextWiz_GetTime_Milliseconds() + "] " + "Operation: Find text '" + s + "'\n");
			break;
		}
		case '7':
		{
			string s, subs;
			cout << "Find: ";
			cin >> s;
			cout << "Substr: ";
			cin >> subs;
			std::vector<TextWiz::TextWiz_Position> VectorToSaveResults;
			testFile.ReplaceTextInEachLine(s, subs, VectorToSaveResults);
			cout << endl << "Results:" << endl;
			for (auto i : VectorToSaveResults)
			{
				cout << "Line: " << i.line << " Column: " << i.column << endl;
			}
			logger.append("[" + TextWiz_GetTime_Milliseconds() + "] " + "Operation: Replace '" + s + "' with '" + subs + "' Count: " + to_string(VectorToSaveResults.size()) + "\n");
			break;
		}
		case '8':
		{
			int a, b;
			cout << "Lines(a b): ";
			cin >> a >> b;
			testFile.SwapLines(a, b);
			logger.append("[" + TextWiz_GetTime_Milliseconds() + "] " + "Operation: Swap Line " + a + " and Line " + b + "\n");
			break;
		}
		default: cout << "Wrong order!" << endl; break;
		}
		cout << endl << "Demo Program for TextWiz by xiaobsh" << endl;
		cout << "0 Exit\t\t1 Get content\t2 Get by line\r\n3 Add a line\t4 Delete a line\t5 Save to file\r\n6 Search text\t7 Replace text\t8 Swap lines" << endl << "Please enter your choice: ";
		choice = getChar();
		logger.append("[" + TextWiz_GetTime_Milliseconds() + "] " + "Operation: User entered '" + choice + "'\n");
	}

	testFile.close();
	logger.append("[" + TextWiz_GetTime_Milliseconds() + "] " + "Operation: Closed file 'hosts'" + "\n");
	logger.close();

	return 0;
}


