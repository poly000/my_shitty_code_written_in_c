for a in `ls ..`
do "C:\Program Files (x86)\Dev-Cpp\MinGW64\bin\gcc.exe" "$a" -o "${a%%.c}-x86_64.exe" -m64 -std=gnu99 -O3 -pipe -I "C:\Program Files (x86)\Dev-Cpp\MinGW64\include" -I "C:\Program Files (x86)\Dev-Cpp\MinGW64\x86_64-w64-mingw32\include" -I "C:\Program Files (x86)\Dev-Cpp\MinGW64\lib\gcc\x86_64-w64-mingw32\4.9.2\include" -L "C:\Program Files (x86)\Dev-Cpp\MinGW64\lib" -L "C:\Program Files (x86)\Dev-Cpp\MinGW64\x86_64-w64-mingw32\lib" -static-libgcc -m64
done