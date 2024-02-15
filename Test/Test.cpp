#include ".\..\TextWiz\TextWiz.h"
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	TextWiz testFile;
	TextWiz_Logger logger(TextWiz_GetTime("%F") + ".log");
	testFile.open("hosts");
	logger.append("[" + TextWiz_GetTime_Milliseconds() + "] " + "Operation: Opened 'hosts'" + "\n");
	// std::vector<TextWiz::TextWiz_Position> VectorToSaveResults;
	// testFile.SearchText("127.0.0.1", VectorToSaveResults);
	// cout << "Line: " << VectorToSaveResults[0].line << "Column: " << VectorToSaveResults[0].column << endl;


	int choice;
	cout << "Test Program for TextWiz by xiaobsh" << endl <<endl;
	cout << "Time: " << TextWiz_GetTime("%F %T") << endl;
	cout << "0 Exit\t\t1 Get content\t2 Get by line\n3 Add a line\t4 Delete a line\t5 Save to file" << endl << "Please enter your choice: ";
	// cin >> choice;
	choice = _getch(); cout << choice - '0' << endl;
	logger.append("[" + TextWiz_GetTime_Milliseconds() + "] " + "Operation: User entered '" + to_string(choice - '0') + "'\n");

	while (choice != '0')
	{
		switch (choice - '0')
		{
		case 1:
		{
			cout << "================================Beginning================================" << endl;
			cout << testFile.GetCurrentContent() << endl;
			cout << "==================================Ending==================================" << endl;
			break;
		}
		case 2:
		{
			int line;
			string s;
			cout << "Please enter the line number: ";
			cin >> line;
			cout << "================================Beginning================================" << endl;
			cout << testFile.GetByLine(line) << endl;
			cout << "==================================Ending==================================" << endl;
			break;
		}
		case 3:
		{
			int line;
			string s;
			cout << "Please enter the line number: ";
			cin >> line;
			cout << "To add: ";
			cin >> s;
			testFile.AddAtLine(line, s);
			break;
		}
		case 4:
		{
			int line;
			string s;
			cout << "Please enter the line number: ";
			cin >> line;
			testFile.DelLine(line);
			break;
		}
		case 5: testFile.save(); break;
		default: cout << "Wrong order!" << endl; break;
		}
		cout << endl << "Test Program for TextWiz by xiaobsh" << endl;
		cout << "0 Exit\t\t1 Get content\t2 Get by line\n3 Add a line\t4 Delete a line\t5 Save to file" << endl << "Please enter your choice: ";
		// cin >> choice;
		choice = _getch(); cout << choice - '0' << endl;
	}

	testFile.close();
	logger.append("[" + TextWiz_GetTime_Milliseconds() + "] " + "Operation: Closed 'hosts'" + "\n");
	logger.close();

	return 0;
}
