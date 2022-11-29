import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    public static void main(String[] args) {
        try {
            ServerSocket ss = new ServerSocket(8089);
            System.out.println("start server ...");
            Socket s = ss.accept();
            System.out.println("client: "+s.getInetAddress().getLocalHost()+" connected to server");

            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(s.getOutputStream()));
            bw.write("Hello World! This is a java demo.\n");
            bw.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
