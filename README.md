# TextWiz

## Introduction
TextWiz is a C++ module that extends the functionality of file processing. The author is a student.

## Features
The most basic file line processing functions.

A class named TextWiz is defined in TextWiz.cpp. The public members are as follows:
```cpp
class TextWiz
{
public:
	// About Files
	void open(string filename);
	void close();
	string get_whole_content();
	void save();
	void exit();

	// Lines
	string getbyline(int line);
	void delline(int line);
	void addatline(int line, string text);
	~TextWiz();
};
```

It can

- Get the text in a line by line number.
- to delete a specific line for which you give the line number.
- Adds text on a specific line, pushing down the original content of the line and the content below it.



## License

The code is licensed under GPL v2.0. For more details, read the [LICENSE](./LICENSE) file.

