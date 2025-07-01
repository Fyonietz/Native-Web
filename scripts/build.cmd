cd ..
"C:\Program Files\CMake\bin\cmake.exe" -S . -B build -G "Visual Studio 17 2022"
cd build
"C:\Program Files\CMake\bin\cmake.exe" --build . --config Release
cd ..
.\NWeb.exe
