@echo off
:: VC++6 && Visual Studio �����Ľ� ����
for /d /r %%i in (Debug,Release,ipch) do rd /s /q "%%i"
for /d /r %%i in (*.sdf,*.opt,*.plg,*.ncb) do rd /s /q "%%i"
del /s *.db
pause