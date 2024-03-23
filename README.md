# TextWiz

## Introduction
TextWiz is a C++ module that extends the functionality of file processing. The author is a student.

## Features
The most basic file line processing functions.

All public interfaces of the module are as follows:

```cpp

class TextWiz
{
public:
	TextWiz();
	TextWiz(std::string FileName);
	~TextWiz();

	// Data
	std::vector<std::string> content;
	// You could define a variable to save results by using `std::vector<TextWiz::TextWiz_Position> variableName`
	struct TextWiz_Position
	{
		size_t line, column;
		TextWiz_Position(size_t line, size_t column) : line(line), column(column) { }
		void fill(size_t Line, size_t Column);
	};

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
	void clear();
	void SwapLines(int Line_1, int Line_2);

	// Line text
	int FindTextInEachLine(std::string TextToFind, std::vector<TextWiz_Position>& VectorToSaveResults);
	int ReplaceTextInEachLine(std::string TextToFind, std::string Subtext, std::vector<TextWiz_Position>& VectorToSaveResults);
	int ReplaceTextInEachLine(std::string TextToFind, std::string Subtext); 
};
```

```cpp
class TextWiz_Logger
{
public:
	TextWiz_Logger();
	TextWiz_Logger(std::string FileName);
	~TextWiz_Logger();
	void open(std::string FileName);
	void append(std::string Text);
	void close();
};
```

```cpp
std::string TextWiz_GetTime(const char* FormatStr = "%F %T");
std::string TextWiz_GetTime_Milliseconds();

```

It can

- Get the text in a line by line number.
- to delete a specific line for which you give the line number.
- Adds text on a specific line, pushing down the original content of the line and the content below it.
- Get the formatted time string by using `TextWiz_GetTime("%F %T")`. Please refer to the strftime() function for the available format control strings.
- Customize a logger to write a journal.


## Compile Demo Project

### Windows
Open `TextWiz.sln` in Visual Studio and it's easy to compile the demo project. I have used `TestFile.txt` as the test file, but you can use any txt file for testing. Don't forget to rename your file to `TestFile.txt` if you haven't changed the code.

### Linux
Leave the .sln file aside. It has nothing to do with you. You can just run `g++ Demo/Demo.cpp TextWiz/TextWiz.cpp TextWiz/pch.hpp -o {TargetName}` to compile it. It uses the `TestFile.txt` file as well.


## License

The code is licensed under Apache-2.0. For more details, read the [LICENSE](./LICENSE) file.

