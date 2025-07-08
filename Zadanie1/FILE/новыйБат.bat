cd C:\Users\Home\Desktop\PROGRAMMIROVANIE\Praktika1\bin\Debug
Praktika1.exe < 01input.txt > 01batOutput.txt 2>NUL
fc 01batOutput.txt 01output.txt || pause

Praktika1.exe < 02input.txt > 02batOutput.txt 2>NUL
fc 02batOutput.txt 02output.txt || pause

Praktika1.exe < 03input.txt > 03batOutput.txt 2>NUL
fc /N 03batOutput.txt 03output.txt || pause

pause