@ECHO OFF
SET /p args=<pos_%~1_args.txt
IF "%1"=="" ECHO & GOTO :END
..\app.exe %args% > out.txt
IF %ERRORLEVEL% EQU 0 ECHO POS TEST %~1 !PASSED! & GOTO :END
:END