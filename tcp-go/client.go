package main
import (
	"fmt"
	"net"
    "bufio"
    "io"
)
func main() {
	conn, err := net.Dial("tcp", "127.0.0.1:8089")
	if err != nil {
		fmt.Println("dial failed, err", err)
		return
	}
	defer conn.Close()
    // 
    reader := bufio.NewReader(conn)
    var buf [1024]byte
    n, err := reader.Read(buf[:])
    if err == io.EOF {
        fmt.Println("io err:", err)
        return
    }
    if err != nil {
        fmt.Println("read from client failed, err:", err)
        return
    }
    recvStr := string(buf[:n])
    fmt.Println("from server:", recvStr)
}
