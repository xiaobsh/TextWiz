@echo on
set dir=%cd%
mkdir Out
g++ Test.cpp ..\TextWiz\TextWiz.cpp ..\TextWiz\pch.hpp -o .\Out\Test.exe
copy /b ORIGIN .\Out\ORIGIN
copy /b RESULT .\Out\RESULT
cd Out
.\Test.exe
cd %dir%
