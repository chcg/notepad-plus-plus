# @echo off

# If this batch file is called from the Microsoft Visual Studio pre-build event,
# then the current dir for this bat-file is set to Notepad++ solution/project dir.
# Because in this batch file we have to go two dir-levels higher (for finding the files
# from the external libraries) from both the solution/project dir and from the dir,
# where this batch file is located, we can run this batch file ok also manually
# and not only from that MSVS event.
$outputFile="..\..\PowerEditor\src\NppLibsVersion.h"

if( Test-Path -path $outputFile ) { del $outputFile }

# First "for" finds and extracts specific one line string like "#define VERSION_SCINTILLA "5.5.4"".
# Second "for" then uses regex to extract only the "..." version part substring from it.

$sciVerStr="N/A"
$findResults=findstr /L /C:"#define VERSION_SCINTILLA " "..\..\scintilla\win32\ScintRes.rc"
foreach( $a in $findResults ) {
	$findRegex= echo $a | findstr /R "[0-9]*\.[0-9]*\." > nul 2>&1
	echo $findRegex
	foreach( $b in ($a) ) {
			echo $b | findstr /R "[0-9]*\.[0-9]*\." > nul 2>&1 
			#&& $sciVerStr = {$b}
	}
}

$lexVerStr="N/A"
# for /F "delims=" %%a in ('findstr /L /C:"#define VERSION_LEXILLA " "..\..\lexilla\src\LexillaVersion.rc"') do (
	# for %%b in (%%a) do (
			# echo %%b | findstr /R "[0-9]*\.[0-9]*\." > nul 2>&1 && $lexVerStr=%%b
	# )
# )

$boostRegexVerStr="N/A"
# for /F "delims=" %%a in ('findstr /L /C:"#define BOOST_LIB_VERSION " "..\..\boostregex\boost\version.hpp"') do (
	# for %%b in (%%a) do (
			# echo %%b | findstr /R "[0-9]*_[0-9]*\" > nul 2>&1 && $boostRegexVerStr=%%b
	# )
# )

# At this point, we should have the quoted version strings collected:
echo "Scintilla version detected: $sciVerStr"
echo "Lexilla version detected: $lexVerStr"
echo "Boost Regex version detected: $boostRegexVerStr"

# And finally create the output file:
echo "// NppLibsVersion.h" > $outputFile
echo "// - maintained by NppLibsVersionH-generator.bat" >> $outputFile
echo "#define NPP_SCINTILLA_VERSION $sciVerStr" >> $outputFile
echo "#define NPP_LEXILLA_VERSION $lexVerStr" >> $outputFile
echo "#define NPP_BOOST_REGEX_VERSION $boostRegexVerStr" >> $outputFile
