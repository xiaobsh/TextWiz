#include <iostream>
#include "IdealFile.cpp"

using namespace std;

int main()
{
	xFile F;
	F.open("hosts");
	cout << F.getbyline(2) << endl;
	cout << F.getcontent() << "###@EOF" <<endl;
	F.addatline(2, "Testing!!!");
	cout << F.getbyline(2) << endl;
	F.save();
	F.close();
	system("pause");
	return 0;
}

