set PROGRAM=%~1

%PROGRAM% 0 > "%TEMP%\zero.txt"
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\zero.txt" zero.txt
if ERRORLEVEL 1 goto err

%PROGRAM% 0 > "%TEMP%\zero.txt"
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\zero.txt" zero.txt
if ERRORLEVEL 1 goto err

%PROGRAM% 255 > "%TEMP%\result255.txt"
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\result255.txt" result255.txt
if ERRORLEVEL 1 goto err

%PROGRAM% 6 > "%TEMP%\result6_96.txt"
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\result6_96.txt" result6_96.txt
if ERRORLEVEL 1 goto err

%PROGRAM% 131 > "%TEMP%\result131_193.txt"
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\result131_193.txt" result131_193.txt
if ERRORLEVEL 1 goto err

echo Program testing succeded
exit 0

:err
echo Program testing failed
exit 1