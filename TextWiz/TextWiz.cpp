#include <string>
#include <fstream>
#include <vector>
#include <ctime>

// using namespace std;

class TextWiz
{
public:
	// About Files
	void open(std::string filename); // r + w ��д
	void close(); // ��ʹ������������Ϊ�˱����ٴδ��������ļ���close �����Զ����棬exit ʵ���˱����˳���
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
	std::string fname; // ��������

	// ʹ�� vector ��Ϊ�˴��������������е��ı���
	// ����� cufile ����ȡһ�Σ�������õȴ�д�룻
	// 
	// �������� vector ���� class �����
	std::vector<std::string> content;
};


void TextWiz::open(std::string filename)
{
	cufile.open(filename, std::ios::in);
	fname = filename;
	content.clear();

	// Ԥ��ȡ
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

