#include <iostream>
#include ".\..\TextWiz\TextWiz.cpp"
#include <conio.h>

using namespace std;

int main()
{
	TextWiz testFile, logger;
	testFile.open("hosts");
	std::vector<TextWiz::TextWiz_Position> VectorToSaveResults;
	testFile.SearchText("127.0.0.1", VectorToSaveResults);


	int choice;
	cout << "Test Program for TextWiz by xiaobsh" << endl <<endl;
	cout << "Time: " << TextWiz_GetTime("%Y-%m-%d %H:%M:%S") << endl;
	cout << "0 Exit\t\t1 Get content\t2 Get by line\n3 Add a line\t4 Delete a line\t5 Save to file" << endl << "Please enter your choice: ";
	// cin >> choice;
	choice = _getch(); cout << choice - '0' << endl;

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
	return 0;
}
