Imports System.Net.Sockets
Imports System.Text

Module Module1

    Sub Main()

        Dim clArgs() As String = Environment.GetCommandLineArgs()

        If clArgs.Count > 1 Then
            Console.WriteLine(clArgs(1))



            Dim UDPClient As New UdpClient()
            UDPClient.Client.SetSocketOption(SocketOptionLevel.Socket,
             SocketOptionName.ReuseAddress, True)
            UDPClient.Connect("localhost", 777)
            Try

                Dim strMessage As String = String.Empty
                ' Do

                Dim bytSent As Byte() =
                   Encoding.ASCII.GetBytes(clArgs(1))

                UDPClient.Send(bytSent, bytSent.Length)

                'Loop While strMessage <> String.Empty
                UDPClient.Close()

            Catch e As Exception

                Console.WriteLine(e.ToString())
            End Try


        End If


    End Sub

End Module
