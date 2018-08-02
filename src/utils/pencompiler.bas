'' pencompiler.bas
'' fbc pencompiler.bas mtparser.bas 


#include "mtparser.bi"

Type LabelType
	name As String * 32
	pos As Integer
End Type

Dim As Integer fIn, fOut
Dim Shared As uByte byteCode (255)
Dim Shared As Integer byteCodeI
Dim As String tokens (15), lineFromFile, myCommand
Dim As Integer op, parm1, parm2, i, ctr, debug
Dim Shared As LabelType labels (15)
Dim Shared As Integer labelI
Dim As String curPrefix
Dim As String prefixes (63)
Dim As Integer prefixesI, totalBytes, totalbehs

Sub writeByte (b As uByte)
	byteCode (byteCodeI) = b
	If byteCodeI < 255 Then byteCodeI = byteCodeI + 1
End Sub

Sub addLabel (lname As String)
	'Print "Creating Label " & lname & " @ " & Hex (byteCodeI, 2)
	labels (labelI).name = lname
	labels (labelI).pos = bytecodeI
	labelI = labelI + 1
End Sub

Function findPos (lname As String) As Integer
	Dim As Integer res, i

	res = 0
	For i = 0 To labelI - 1
		If lname = labels (i).name Then res = labels (i).pos: Exit For
	Next i

	Return res
End Function

? "MK1 v1.0 pencompiler v0.3 ~ ";

If Len (Command (2)) = 0 Then
	Print "usage: "
	Print 
	Print "$ pencompiler.exe in.spt out.h"
	End
End If

fIn = FreeFile
Open Command (1) For Input As #fIn
fOut = FreeFile
Open Command (2) For Output As #fOut

debug = (Command (3) = "debug")

Print #fOut, "// NES MK1 v1.0"
Print #fOut, "// Copyleft Mojon Twins 2013, 2015, 2017, 2018"
Print #fOut, ""
Print #fOut, "// Generated by pencompiler.exe v0.3"
Print #fOut, ""

Print " Compiling ~ ";

If debug Then Print
If debug Then Print "00            COMMAND       ARG           OOPPPVVV      Hex"

prefixesI = 0: totalBytes = 0: totalbehs = 0

While Not Eof (fIn) 
	Line Input #fIn, lineFromFile
	parseTokenizeString lineFromFile, tokens (), Chr (9), "#"
	myCommand = Trim (Ucase (tokens (0)))

	If myCommand = "" Then Continue While

	If myCommand = "BEGIN" Then
		curPrefix = tokens (1)
		prefixes (prefixesI) = curPrefix
		prefixesI = prefixesI + 1
		byteCodeI = 0: labelI = 0
	End If

	If myCommand = "END" Then
		writeByte 0

		totalBytes = totalBytes + byteCodeI
		totalbehs = totalbehs + 1

		ctr = 0
		Print #fOut, "const unsigned char " & curPrefix & " [] = {"
		Print #fOut, "	";
		For i = 0 To byteCodeI - 1
			print #fOut, "0x" & Lcase (Hex (byteCode (i), 2));
			If i < byteCodeI - 1 Then Print #fOut, ", ";
			ctr = ctr + 1: If ctr = 16 Then ctr = 0: Print #fOut, "": Print #fOut, "	";
		Next i 
		Print #fOut, ""
		Print #fOut, "};"
		Print #fOut, ""
	End If

	' Fix tokens
	If Instr ("UPRIGHTDOWNLEFT", Ucase (tokens (1))) Then
		myCommand = myCommand & "_" & Ucase (tokens (1))
		tokens (1) = tokens (2)
	End If

	If Len (myCommand) > 1 And Left (myCommand, 1) = ":" Then
		addLabel Right (myCommand, Len (myCommand) - 1)
		Continue While
	End If

	If debug Then ? Hex (byteCodeI, 2), "[" & myCommand & "]", tokens (1),

	op = &HFF

	Select Case myCommand
		Case "LEFT": 		op = 1: parm1 = 0: parm2 = Val (tokens (1))
		Case "DOWN_LEFT": 	op = 1: parm1 = 1: parm2 = Val (tokens (1))
		Case "DOWN":		op = 1: parm1 = 2: parm2 = Val (tokens (1))
		Case "DOWN_RIGHT":	op = 1: parm1 = 3: parm2 = Val (tokens (1))
		Case "RIGHT":		op = 1: parm1 = 4: parm2 = Val (tokens (1))
		Case "UP_RIGHT":	op = 1: parm1 = 5: parm2 = Val (tokens (1))
		Case "UP":			op = 1: parm1 = 6: parm2 = Val (tokens (1))
		Case "UP_LEFT":		op = 1: parm1 = 7: parm2 = Val (tokens (1))

		Case "IDLE":		op = 0: parm1 = 1: parm2 = Val (tokens (1))

		Case "FIRE":		
			op = 2: parm1 = 0
			parm2 = 0
			If Instr ("PLAYER", Ucase (tokens (1))) Then parm2 = 2

		case "SPEED"
			Select Case tokens (1)
				Case "1": op = 3: parm1 = 7: parm2 = 7 
				Case "2": op = 3: parm1 = 7: parm2 = 6 
				Case "4": op = 3: parm1 = 7: parm2 = 5  
				Case "8": op = 3: parm1 = 7: parm2 = 4  
			End Select

		Case "RETURN":
			op = 3
			parm1 = byteCodeI - findPos (tokens (1))
			parm2 = 0

		'Case Else:			op = 0: parm1 = 0: parm2 = 0
	End Select

	' Build
	
	If op < 3 Then 
		If debug Then Print Bin ((op Shl 6) Or (parm1 Shl 3) Or parm2, 8), Hex ((op Shl 6) Or (parm1 Shl 3) Or parm2, 2)
		writeByte (op Shl 6) Or (parm1 Shl 3) Or parm2
	ElseIf op <> &HFF then
		
		If op = 3 And parm1 = 7 And parm2 > 3 Then
			If debug Then Print Bin ((op Shl 6) Or (parm1 Shl 3) Or parm2, 8), Hex ((op Shl 6) Or (parm1 Shl 3) Or parm2, 2)
			writeByte (op Shl 6) Or (parm1 Shl 3) Or parm2
		Else
			If debug Then Print Bin ((op Shl 6) Or parm1, 8), Hex ((op Shl 6) Or parm1, 2) , "-> " & Hex (byteCodeI - parm1, 2)
			writeByte (op Shl 6) Or parm1
		End If
	Else 
		If debug Then Print
	End If
Wend

Close #fIn

Print "Writing index ~ ";

Print #fOut, "const unsigned char * const en_behptrs [] = {"
For i = 0 To prefixesI - 1
	If (i Mod 8) = 0 Then Print #fOut, "	";
	Print #fOut, prefixes (i);
	If i < prefixesI - 1 Then Print #fOut, ", ";
	If (i Mod 8) = 7 Then Print #fOut, "" 
	totalBytes = totalBytes + 2
Next i
If (i Mod 8) <> 7 Then Print #fOut, ""
Print #fOut, "};"
Print #fOut, ""

Close #fOut

Print "" & totalbehs & " enbehs written (" & totalBytes & " bytes) ~ DONE!"
