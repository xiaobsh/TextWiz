#include <string>
#include <fstream>
#include <vector>

using namespace std;


class xFile
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

	// 为了对标行号，[0] 为空行；
	// 使用 vector 是为了处理不定长、不定行的文本；
	// 这里的 cufile 仅读取一次，随后闲置等待写入；
	// 
	// 不定长的数组放在 class 的最后。
	vector<string> content;
};


void xFile::open(string filename)
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

