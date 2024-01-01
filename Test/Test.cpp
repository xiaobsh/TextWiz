#include <iostream>
#include ".\..\TextWiz\TextWiz.cpp"
#include <conio.h>

using namespace std;

TextWiz* p_tw;

void exitfunc(void)
{
	// (*Arg).close();
	p_tw -> close();
}


int main()
{
	TextWiz F;
	p_tw = &F;
	F.open("hosts");
	atexit(exitfunc);

	int choice;
	cout << "Test Program for TextWiz by xiaobsh" << endl;
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
			cout << F.get_current_content() << endl;
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
			cout << F.getbyline(line) << endl;
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
			F.addatline(line, s);
			break;
		}
		case 4:
		{
			int line;
			string s;
			cout << "Please enter the line number: ";
			cin >> line;
			F.delline(line);
			break;
		}
		case 5: F.save(); break;
		default: cout << "Wrong order!" << endl; break;
		}
		cout << endl << "Test Program for TextWiz by xiaobsh" << endl;
		cout << "0 Exit\t\t1 Get content\t2 Get by line\n3 Add a line\t4 Delete a line\t5 Save to file" << endl << "Please enter your choice: ";
		// cin >> choice;
		choice = _getch(); cout << choice - '0' << endl;
	}

	// F.exit();
	// system("pause");
	return 0;
}
