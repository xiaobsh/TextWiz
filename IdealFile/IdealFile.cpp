#include <string>
#include <fstream>
#include <vector>

using namespace std;

class IdealFile
{
public:
	// About Files
	void open(string filename);
	void close(); // 不使用析构函数是为了便于再次打开其他的文件。close 不会自动保存，exit 实现了保存退出。
	string getcontent();
	void save();
	void exit();

	// Lines
	string getbyline(int line);
	void delline(int line);
	void addatline(int line, string text);

private:
	fstream cufile;
	string fname; // 方便重载

	// 使用 vector 是为了处理不定长、不定行的文本；
	// 这里的 cufile 仅读取一次，随后闲置等待写入；
	// 
	// 不定长的 vector 放在 class 的最后。
	vector<string> content;
};


void IdealFile::open(string filename)
{
	cufile.open(filename, ios::in);
	fname = filename;
	content.clear();

	// 预读取
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


