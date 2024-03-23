cd ..
mkdir ./Test/Out
g++ ./Test/Test.cpp ./TextWiz/TextWiz.cpp ./TextWiz/pch.hpp -o ./Test/Out/Test.out
cp ./Test/ORIGIN ./Test/Out/ORIGIN
cp ./Test/RESULT ./Test/Out/RESULT
cd ./Test/Out
./Test.out
