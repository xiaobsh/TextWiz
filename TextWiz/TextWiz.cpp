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
	std::string GetCurrentContent();
	void save();
	void exit();

	// Lines
	std::string GetByLine(int line);
	void DelLine(int line);
	void AddAtLine(int line, std::string text);
	~TextWiz();

private:
	std::fstream cuFile;
	std::string fName; // ��������

	// ʹ�� vector ��Ϊ�˴��������������е��ı���
	// ����� cuFile ����ȡһ�Σ�������õȴ�д�룻
	// 
	// �������� vector ���� class �����
	std::vector<std::string> content;
};


void TextWiz::open(std::string FileName)
{
	cuFile.open(FileName, std::ios::in);
	fName = FileName;
	content.clear();

	// Ԥ��ȡ
	std::string s;
	while (getline(cuFile, s)) content.push_back(s);
	cuFile.close();
}

void TextWiz::close()
{
	cuFile.close();
}

std::string TextWiz::GetCurrentContent()
{
	std::string s;
	for (auto&& i : content) s += i + "\n";
	return s;
}


std::string TextWiz::GetByLine(int Line)
{
	if (Line < 1) return "";
	else return content[Line - 1];
}

void TextWiz::DelLine(int Line)
{
	content.erase(content.begin() + Line - 1);
}

void TextWiz::AddAtLine(int Line, std::string Text)
{
	content.insert(content.begin() + Line - 1, Text);
}


void TextWiz::save()
{
	cuFile.open(fName, std::ios::out | std::ios::in);
	cuFile << GetCurrentContent();
	cuFile.close();
}

void TextWiz :: exit()
{
	save();
	close();
}


char* TextWiz_GetTime(const char* FormatStr)
{
	time_t p_time;
	tm p_tm;
	time(&p_time);
	char tmp[256];
	localtime_s(&p_tm, &p_time);
	strftime(tmp, sizeof(tmp), FormatStr, &p_tm); // "%Y-%m-%d %H:%M:%S"
	return tmp;
}


TextWiz::~TextWiz()
{
	cuFile.close();
}

