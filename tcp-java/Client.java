import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.net.UnknownHostException;

public class Client {
    public static void main(String[] args) {
        try {
            Socket s = new Socket("127.0.0.1",8089);

            //IO
            InputStream is = s.getInputStream();
            OutputStream os = s.getOutputStream();

            // for write
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(os));
            // for read
            BufferedReader br = new BufferedReader(new InputStreamReader(is));
            String mess = br.readLine();
            System.out.println("from server: " + mess);
        } catch (UnknownHostException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
