#pragma once

#ifndef __TEXTWIZ_INCLUDED_BY_XIAOBSH
#define __TEXTWIZ_INCLUDED_BY_XIAOBSH

#include <string>
#include <fstream>
#include <vector>


class TextWiz
{
public:
	TextWiz() {};
	TextWiz(std::string FileName);
	~TextWiz();

	// Data
	struct TextWiz_Position;
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
	bool SearchText(std::string TextToSearch, std::vector<TextWiz_Position>& VectorToSaveResults); // You can define the variable to save results by using `std::vector<TextWiz::TextWiz_Position> VectorToSaveResults`

private:
	std::fstream cuFile;
	std::string fName; // make it easier to overload

	std::vector<std::string> content;
};


std::string TextWiz_GetTime(const char* FormatStr);

#endif
