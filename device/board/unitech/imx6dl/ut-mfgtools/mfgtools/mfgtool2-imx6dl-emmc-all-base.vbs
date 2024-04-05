Set wshShell = CreateObject("WScript.shell")
wshShell.run "mfgtool2.exe -c ""linux"" -l ""eMMC-all-base"" -s ""board=sabresd"" -s ""sxdtb=sdb"" -s ""mmc=2"" "
Set wshShell = Nothing
