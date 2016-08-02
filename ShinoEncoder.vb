  Private Function DC(t As String) As String

        Try
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

            Dim s() As String = Split(Trim(t), " ")
            Dim r As String = ""
            If s.Length Mod 2 <> 0 Then
                Return ""
            End If

            For i = 0 To s.Length - 2 Step 2
                If Len(s(i)) - 2 > 16 Or Len(s(i + 1)) - 2 > 16 Then
                Else
                    r = r & Chr(Convert.ToInt64(Hex(Len(s(i)) - 2) & Hex(Len(s(i + 1)) - 2), 16))
                End If
            Next

            Return r


            'Return System.Text.Encoding.UTF8.GetBytes(r)

        Catch ex As Exception
            InputBox("Error:", "ERROR", ex.Message & " " & t)
            Return "Encode Error"
        End Try
    End Function
