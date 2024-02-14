//#include "TextWiz.h"
#include <string>
#include <fstream>
#include <vector>
#include <ctime>


class TextWiz
{
public:
	TextWiz() {};
	TextWiz(std::string FileName) { open(FileName); };
	~TextWiz();

	// Data
	struct TextWiz_Position
	{
		uint32_t line, column;
	};
	std::vector<TextWiz_Position> SearchResult;

	// Files
	void open(std::string FileName); // r + w
	void close(); // 不使用析构函数是为了便于再次打开其他的文件。close 不会自动保存，exit 实现了保存退出。
	std::string GetCurrentContent();
	void save();
	void exit();

	// Lines
	std::string GetByLine(int line);
	void DelLine(int line);
	void AddAtLine(int line, std::string text);

	// Text
	bool SearchText(std::string TextToSearch, std::vector<TextWiz_Position>& VectorToSaveResults); // You can define the variable to save results by using `std::vector<TextWiz::TextWiz_Position> VectorToSaveResults`

private:
	std::fstream cuFile;
	std::string fName; // make it easier to overload

	// 不定长的 vector 放在 class 的最后。
	std::vector<std::string> content;
};


void TextWiz::open(std::string FileName)
{
	cuFile.open(FileName, std::ios::in);
	fName = FileName;
	content.clear();

	// 预读取
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
	content.erase(content.begin() + (Line - 1));
}

void TextWiz::AddAtLine(int Line, std::string Text)
{
	content.insert(content.begin() + (Line - 1), Text);
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


std::string TextWiz_GetTime(const char* FormatStr)
{
	time_t p_time;
	tm p_tm;
	time(&p_time);
	char tmp[256];
	localtime_s(&p_tm, &p_time);
	strftime(tmp, sizeof(tmp), FormatStr, &p_tm); // "%Y-%m-%d %H:%M:%S"
	std::string s = tmp;
	return tmp;
}

bool TextWiz::SearchText(std::string TextToSearch, std::vector<TextWiz_Position>& VectorToSaveResults)
{
	return false;
}


TextWiz::~TextWiz()
{
	cuFile.close();
}

