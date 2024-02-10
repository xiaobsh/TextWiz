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
	void open(std::string filename);
	void close();
	std::string GetCurrentContent();
	void save();
	void exit();

	// Lines
	std::string GetByLine(int line);
	void DelLine(int line);
	void AddAtLine(int line, std::string text);
	~TextWiz();
};
```

It can

- Get the text in a line by line number.
- to delete a specific line for which you give the line number.
- Adds text on a specific line, pushing down the original content of the line and the content below it.
- Get the formatted time string by using `TextWiz_GetTime("%Y-%m-%d %H:%M:%S")`. Please refer to the strftime() function for the available format control strings.


## License

The code is licensed under GPL v2.0. For more details, read the [LICENSE](./LICENSE) file.

