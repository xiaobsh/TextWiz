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
	struct TextWiz_Position
	{
		unsigned int line, column;
		TextWiz_Position(unsigned int line, unsigned int column) : line(line), column(column) { }
	};
	std::vector<TextWiz_Position> SearchResult;

	// Files
	void open(std::string FileName);
	void close();
	std::string GetCurrentContent();
	void save();
	void exit();

	// Lines
	std::string GetByLine(int line);
	void DelLine(int line);
	void AddAtLine(int line, std::string text);

	// Text
	int SearchText(std::string TextToSearch, std::vector<TextWiz_Position>& VectorToSaveResults); // You can define the variable to save results by using `std::vector<TextWiz::TextWiz_Position> VectorToSaveResults`

private:
	std::fstream cuFile;
	std::string fName; // make it easier to overload

	std::vector<std::string> content;
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

std::string TextWiz_GetTime(const char* FormatStr);
std::string TextWiz_GetTime_Milliseconds();

#endif
