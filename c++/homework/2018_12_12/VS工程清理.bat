��a
cls
title VS��Ŀ���� BY CR28 QHR
color 0A
mode con: cols=35 lines=10
@echo VS��Ŀ���� BY CR28 QHR
@echo ��������......
@echo ��ȴ�������ɣ�
@echo off
rd ".vs" /s /q >nul 2>nul
rd ".git" /s /q >nul 2>nul
rd "ipch" /s /q >nul 2>nul
for /f "delims=" %%i  in ('dir /b/a:d/s .\')  do (
rd "%%i\.vs" /s /q >nul 2>nul
rd "%%i\.git" /s /q >nul 2>nul
rd "%%i\ipch" /s /q >nul 2>nul
)
::del *.exe  *.dll /s >nul 2>nul
attrib -s -h -r *.opensdf /s >nul 2>nul
del *.db *.opensdf *.opendb /s >nul 2>nul
del *.sdf *.log *.user *.ipch *.aps /s >nul 2>nul
del *.suo /s /a h >nul 2>nul
del *.ilk *.exp *.pdb *.ipdb *.iobj *.tlog *.res *.lastbuildstate /s >nul 2>nul
del *.plg *.opt /s >nul 2>nul
del *.obj *.pch *.idb/s >nul 2>nul
del *.gitignore *.gitattributes /s >nul 2>nul
del ReadMe.txt /s >nul 2>nul
del UpgradeLog.htm /s >nul 2>nul
@echo �������!
echo ^^o^^ 
@echo ��������ر�! 
pause