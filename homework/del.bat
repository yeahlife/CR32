@echo off
for /r %%i in (debug,release,ipch) do rd /s /q "%%i"
for /r %%i in (*.sdf,*.opt,*.plg,*.ncb) do del /s /f /q "%%i"
pause