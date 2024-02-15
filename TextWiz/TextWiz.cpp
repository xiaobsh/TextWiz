#include "TextWiz.h"
#include "pch.hpp"
#include <string>
#include <fstream>
#include <vector>
#include <ctime>

TextWiz::TextWiz(std::string FileName) { open(FileName); }

void TextWiz::open(std::string FileName)
{
	cuFile.open(FileName, std::ios::in);
	fName = FileName;
	content.clear();

	// ‘§∂¡»°
	std::string s;
	while (getline(cuFile, s)) content.push_back(s);
	cuFile.close();
}

void TextWiz::close() { cuFile.close(); }

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
	if (Line > 0) content.erase(content.begin() + (Line - 1));
}

void TextWiz::AddAtLine(int Line, std::string Text)
{
	if (Line > 0) content.insert(content.begin() + (Line - 1), Text);
}


void TextWiz::save()
{
	cuFile.open(fName, std::ios::out | std::ios::in);
	cuFile << GetCurrentContent();
	cuFile.close();
}

void TextWiz::exit()
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

std::string TextWiz_GetTime_Milliseconds()
{
	try
	{
		struct timeval curTime;
		gettimeofday(&curTime, NULL);
		int milli = curTime.tv_usec / 1000;

		char buffer[80] = { 0 };
		struct tm nowTime;
		long long t_tmp = curTime.tv_sec;
		localtime_r(&t_tmp, &nowTime);
		strftime(buffer, sizeof(buffer), "%F %T", &nowTime);

		char currentTime[84] = { 0 };
		snprintf(currentTime, sizeof(currentTime), "%s.%03d", buffer, milli);

		return currentTime;
	}
	catch (...)
	{
		return "";
	}
}


int TextWiz::SearchText(std::string TextToSearch, std::vector<TextWiz_Position>& VectorToSaveResults)
{
	VectorToSaveResults.clear();
	int count = 0;
	TextWiz_Position pos(0, 0);
	size_t line = 0, column = 0;
	for (line = 0; line < content.size(); line++)
	{
		column = 0;
		while (column < content[line].length())
		{
			if ((column = content[line].find(TextToSearch, column)) == std::string::npos) break;
			pos.fill(line + 1, column);
			VectorToSaveResults.push_back(pos);
			count++;
			column++;
		}
		/*while
			((pos.column < content[pos.line].length() - 2)
			&&
			((pos.column = content[pos.line].find(TextToSearch, pos.column)) != std::string::npos))
		{
			VectorToSaveResults.push_back(pos);
			count++;
			pos.column++;
		}*/
	}
	return count;
}


TextWiz::~TextWiz() { cuFile.close(); }


TextWiz_Logger::TextWiz_Logger(std::string FileName) { open(FileName); }
void TextWiz_Logger::open(std::string FileName) { cuFile.open(FileName, std::ios::app); }
void TextWiz_Logger::append(std::string Text) { cuFile << Text; }
void TextWiz_Logger::close() { cuFile.close(); }

