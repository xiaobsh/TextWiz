#include <iostream>
#include ".\..\Main\IdealFile.cpp"

using namespace std;

int main()
{
	IdealFile F;
	F.open("hosts");
	cout << F.getbyline(2) << endl;
	cout << F.getcontent() << "###@EOF1" << endl;
	F.addatline(2, "Testing!!!");
	cout << F.getbyline(2) << endl;
	F.delline(3);
	cout << "--------------------" << endl << F.getcontent() << "###@EOF2" << endl;
	F.save();
	F.close();
	system("pause");
	return 0;
}
