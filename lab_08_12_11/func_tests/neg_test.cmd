@ECHO OFF
SET args=<neg_%~1_args.txt
IF "%1"=="" ECHO & GOTO :END
..\app.exe %args% > out.txt
IF %ERRORLEVEL% GTR 0 ECHO NEG TEST %~1 !PASSED! & GOTO :END
:END