#include <string>
#include <fstream>
#include <vector>
#include <ctime>

// using namespace std;

class TextWiz
{
public:
	// About Files
	void open(std::string filename); // r + w 读写
	void close(); // 不使用析构函数是为了便于再次打开其他的文件。close 不会自动保存，exit 实现了保存退出。
	std::string get_current_content();
	void save();
	void exit();

	// Lines
	std::string getbyline(int line);
	void delline(int line);
	void addatline(int line, std::string text);
	~TextWiz();

private:
	std::fstream cufile;
	std::string fname; // 方便重载

	// 使用 vector 是为了处理不定长、不定行的文本；
	// 这里的 cufile 仅读取一次，随后闲置等待写入；
	// 
	// 不定长的 vector 放在 class 的最后。
	std::vector<std::string> content;
};


void TextWiz::open(std::string filename)
{
	cufile.open(filename, std::ios::in);
	fname = filename;
	content.clear();

	// 预读取
	std::string s;
	while (getline(cufile, s))
	{
		content.push_back(s);
	}
	cufile.close();
}

void TextWiz::close()
{
	cufile.close();
}

std::string TextWiz::get_current_content()
{
	std::string s;
	for (int i = 0; i < content.size(); ++i)
	{
		s += content[i] + "\n";
	}
	return s;
}


std::string TextWiz::getbyline(int line)
{
	return content[line - 1];
}

void TextWiz::delline(int line)
{
	content.erase(content.begin() + line - 1);
}

void TextWiz::addatline(int line, std::string text)
{
	content.insert(content.begin() + line - 1, text);
}


void TextWiz::save()
{
	cufile.open(fname, std::ios::out | std::ios::in);
	cufile << get_current_content();
	cufile.close();
}

void TextWiz :: exit()
{
	save();
	close();
}


char* getTime()
{
	time_t p_time;
	tm p_tm;
	time(&p_time);
	char tmp[256];
	localtime_s(&p_tm, &p_time);
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", &p_tm);
	return tmp;
}


TextWiz::~TextWiz()
{
	cufile.close();
}

