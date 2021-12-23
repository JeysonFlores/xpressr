echo "-Formatting Daemon src folder..."
cd daemon && cd src && clang-format -i -style=WebKit *.cpp
echo "*Done"

echo "-Formatting Daemon Adaptors folder..."
cd Adaptors && clang-format -i -style=WebKit *.h && cd ..
echo "*Done"

echo "-Formatting Interfaces Adaptors folder..."
cd Interfaces && clang-format -i -style=WebKit *.cpp *.h && cd ..
echo "*Done"


echo "-Formatting Utils Adaptors folder..."
cd Utils && clang-format -i -style=WebKit *.h && cd ..
echo "*Done"