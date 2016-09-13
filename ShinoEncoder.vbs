'ShinoEncode
Function ShinoDecode (t)

	
	'On Error Resume Next
	'Delete Trush
	t = Replace(t, vbTab, " ")
	t = Replace(t, vbCr, " ")
	t = Replace(t, vbLf, " ")

	t = Replace(t, Chr(0), " ")

	For i = 33 To 47
		t = Replace(t, Chr(i), " ")
	Next

	For i = 58 To 64
		t = Replace(t, Chr(i), " ")
	Next

	For i = 91 To 96
		t = Replace(t, Chr(i), " ")
	Next

	For i = 123 To 255
		t = Replace(t, Chr(i), " ")
	Next

	Do While (InStr(t, "  "))
		t = Replace(t, "  ", " ")
	Loop
	'Put each keyword into an array
	Dim s
	s=Split(Trim(t), " ")
	If Ubound(s) Mod 2 <> 0 Then
		ShinoDecode="Encode Error"
	End If

	Dim r 
	r = ""

	For i = 0 To Ubound(s) - 1 Step 2
		If Len(s(i)) - 2 > 16 Or Len(s(i + 1)) - 2 > 16 Then
		Else
			r = r & Chr((Len(s(i)) - 2)*16 + Len(s(i + 1)) - 2)
		End If
	Next

	ShinoDecode= r

End Function
