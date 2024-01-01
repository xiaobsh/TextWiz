#include <string>
#include <fstream>
#include <vector>

using namespace std;


class xFile
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

	// Ϊ�˶Ա��кţ�[0] Ϊ���У�
	// ʹ�� vector ��Ϊ�˴��������������е��ı���
	// ����� cufile ����ȡһ�Σ�������õȴ�д�룻
	// 
	// ��������������� class �����
	vector<string> content;
};


void xFile::open(string filename)
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

void xFile::close()
{
	cufile.close();
}

string xFile::getcontent()
{
	string s;
	for (int i = 0; i < content.size(); ++i)
	{
		s += content[i] + "\n";
	}
	return s;
}


string xFile::getbyline(int line)
{
	return content[line];
}

void xFile :: delline(int line)
{
	content.erase(content.begin() + line - 1);
}

void xFile :: addatline(int line, string text)
{
	content.insert(content.begin() + line - 1, text);
}


void xFile :: save()
{
	cufile << getcontent();
}

void xFile :: exit()
{
	save();
	close();
}

