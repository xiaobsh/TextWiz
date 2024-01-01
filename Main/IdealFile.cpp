#include <string>
#include <fstream>
#include <vector>

using namespace std;

class IdealFile
{
public:
	// About Files
	void open(string filename);
	void close(); // ��ʹ������������Ϊ�˱����ٴδ��������ļ���close �����Զ����棬exit ʵ���˱����˳���
	string getcontent();
	void save();
	void exit();

	// Lines
	string getbyline(int line);
	void delline(int line);
	void addatline(int line, string text);

private:
	fstream cufile;
	string fname; // ��������

	// ʹ�� vector ��Ϊ�˴��������������е��ı���
	// ����� cufile ����ȡһ�Σ�������õȴ�д�룻
	// 
	// �������� vector ���� class �����
	vector<string> content;
};


void IdealFile::open(string filename)
{
	cufile.open(filename, ios::in);
	fname = filename;
	content.clear();

	// Ԥ��ȡ
	string s;
	while (getline(cufile, s))
	{
		content.push_back(s);
	}
	cufile.close();
	cufile.open(filename, ios::out | ios::in);
}

void IdealFile::close()
{
	cufile.close();
}

string IdealFile::getcontent()
{
	string s;
	for (int i = 0; i < content.size(); ++i)
	{
		s += content[i] + "\n";
	}
	return s;
}


string IdealFile::getbyline(int line)
{
	return content[line];
}

void IdealFile :: delline(int line)
{
	content.erase(content.begin() + line - 1);
}

void IdealFile :: addatline(int line, string text)
{
	content.insert(content.begin() + line - 1, text);
}


void IdealFile :: save()
{
	cufile << getcontent();
}

void IdealFile :: exit()
{
	save();
	close();
}


