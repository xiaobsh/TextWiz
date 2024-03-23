#include "TextWiz.h"
#include "pch.hpp"
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <algorithm>

TextWiz::TextWiz(std::string FileName) { open(FileName); }

void TextWiz::open(std::string FileName)
{
	cuFile.open(FileName, std::ios::out | std::ios::in);
	fName = FileName;
	content.clear();

	// Pre-load
	std::string s;
	while (getline(cuFile, s))
	{
		if (s.size() > 1)
		{
			s = s.substr(0, s.find_last_not_of('\r') + 1);
			content.push_back(s);
		}
		else content.push_back("");
	}
	cuFile.close();
}

void TextWiz::close() { cuFile.close(); }

std::string TextWiz::GetCurrentContent() const
{
	std::string s;
	for (auto&& i : content) s += i + "\n";
	return s;
}

std::string TextWiz::GetByLine(int Line) const
{
	if (Line < 1 || Line > size()) return "";
	else return content[Line - 1];
}

void TextWiz::DelLine(int Line)
{
	if (Line > 0 && Line < size()) content.erase(content.begin() + (Line - 1));
}

void TextWiz::AddAtLine(int Line, std::string Text)
{
	if (Line > 0 && Line < size()) content.insert(content.begin() + (Line - 1), Text);
}

void TextWiz::clear()
{
	cuFile.clear();
}

void TextWiz::SwapLines(int Line_1, int Line_2)
{
	std::iter_swap(content.begin() + (Line_1 - 1), content.begin() + (Line_2 - 1));
}

int TextWiz::size() const
{
	return content.size();
}

void TextWiz::append(std::string text)
{
	content.push_back(text);
}

void TextWiz::save()
{
	cuFile.open(fName, std::ios::out | std::ios::trunc);
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
	localtime_r(&p_time, &p_tm);
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
		LONG_INTEGER t_tmp = curTime.tv_sec;
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

int TextWiz::FindTextInEachLine(std::string Text, std::vector<TextWiz_Position>& VectorToSaveResults) const
{
	VectorToSaveResults.clear();
	int count = 0;
	TextWiz_Position pos(0, 0);
	size_t line = 0, column = 0;
	for (line = 0; line < content.size(); line++)
	{
		column = 0;
		while ((column = content[line].find(Text, column)) != std::string::npos)
		{
			pos.fill(line + 1, column + 1);
			VectorToSaveResults.push_back(pos);
			column += Text.length();
			count++;
		}
	}
	return count;
}

int TextWiz::ReplaceTextInEachLine(std::string TextToFind, std::string Subtext, std::vector<TextWiz::TextWiz_Position>& VectorToSaveResults)
{
	VectorToSaveResults.clear();
	int count = 0;
	TextWiz_Position pos(0, 0);
	size_t line = 0, column = 0;
	for (line = 0; line < content.size(); line++)
	{
		column = 0;
		while ((column = content[line].find(TextToFind, column)) != std::string::npos)
		{
			content[line].replace(column, TextToFind.length(), Subtext);
			pos.fill(line + 1, column + 1);
			VectorToSaveResults.push_back(pos);
			column += TextToFind.length();
			count++;
		}
	}
	return count;
}

int TextWiz::ReplaceTextInEachLine(std::string TextToFind, std::string Subtext)
{
	int count = 0;
	size_t line = 0, column = 0;
	for (line = 0; line < content.size(); line++)
	{
		column = 0;
		while ((column = content[line].find(TextToFind, column)) != std::string::npos)
		{
			content[line].replace(column, TextToFind.length(), Subtext);
			column += TextToFind.length();
			count++;
		}
	}
	return count;
}

const void TextWiz::operator=(const TextWiz& b)
{
	fName = b.fName;
	content.clear();
	content.insert(content.begin(), b.content.begin(), b.content.end());
}

const bool TextWiz::operator==(const TextWiz& b) const
{
	return(content == b.content);
}

const bool TextWiz::operator!=(const TextWiz& b) const
{
	return(!(content == b.content));
}

TextWiz::~TextWiz() { cuFile.close(); }


TextWiz_Logger::TextWiz_Logger(std::string FileName) { open(FileName); }
void TextWiz_Logger::open(std::string FileName) { cuFile.open(FileName, std::ios::app); }
void TextWiz_Logger::append(std::string Text) { cuFile << Text; }
void TextWiz_Logger::close() { cuFile.close(); }

