#pragma once

#ifndef __TEXTWIZ_INCLUDED_BY_XIAOBSH
#define __TEXTWIZ_INCLUDED_BY_XIAOBSH

#include <string>
#include <fstream>
#include <vector>


class TextWiz
{
public:
	TextWiz() {}
	TextWiz(std::string FileName);
	~TextWiz();

	// Data
	std::vector<std::string> content;
	// You could define a variable to save results by using `std::vector<TextWiz::TextWiz_Position> variableName`
	struct TextWiz_Position
	{
		size_t line, column;
		TextWiz_Position(size_t line, size_t column) : line(line), column(column) { }
		void fill(size_t Line, size_t Column)
		{
			line = Line; column = Column;
		}
	};

	// Files
	void open(std::string FileName);
	void close();
	std::string GetCurrentContent() const;
	void save();
	void exit();

	// Lines
	std::string GetByLine(int line) const;
	void DelLine(int line);
	void AddAtLine(int line, std::string text);
	void clear();
	void SwapLines(int Line_1, int Line_2);
	int size() const;
	void append(std::string text);

	// Line text
	int FindTextInEachLine(std::string TextToFind, std::vector<TextWiz_Position>& VectorToSaveResults) const;
	int ReplaceTextInEachLine(std::string TextToFind, std::string Subtext, std::vector<TextWiz_Position>& VectorToSaveResults);
	int ReplaceTextInEachLine(std::string TextToFind, std::string Subtext);

	// Operator
	const void operator=(const TextWiz& b);
	const bool operator==(const TextWiz& b) const;
	const bool operator!=(const TextWiz& b) const;

private:
	std::fstream cuFile;
	std::string fName; // make it easier to overload
};

class TextWiz_Logger
{
public:
	TextWiz_Logger() {}
	TextWiz_Logger(std::string FileName);
	~TextWiz_Logger() { close(); }
	void open(std::string FileName);
	void append(std::string Text);
	void close();
private:
	std::fstream cuFile;
};

std::string TextWiz_GetTime(const char* FormatStr = "%F %T");
std::string TextWiz_GetTime_Milliseconds();

#endif
