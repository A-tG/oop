set PROGRAM=%~1

rem �஢��塞 ������ � ���⮬ 䠩��
%PROGRAM% empty.txt "%TEMP%\empty.txt" find replace
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\empty.txt" empty.txt
if ERRORLEVEL 1 goto err

rem �஢��塞 ������ � 䠩�� � ����� ��ப��
%PROGRAM% oneline.txt "%TEMP%\oneline.txt" ma mom
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\oneline.txt" oneline_replaced.txt
if ERRORLEVEL 1 goto err

rem �஢��塞 ������ � 䠩�� � ��᪮�쪨�� ��ப���
%PROGRAM% multiline.txt "%TEMP%\multiline.txt" hello hi
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\multiline.txt" multiline_replaced.txt
if ERRORLEVEL 1 goto err

echo Program testing succeded
exit 0

:err
echo Program testing failed
exit 1