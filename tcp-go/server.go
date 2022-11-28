package main
import (
	"fmt"
	"net"
)
func main() {
	network := "tcp"
	address := "127.0.0.1:30000"
	listen, err := net.Listen(network, address)
	if err != nil {
		fmt.Printf("main | net.Listen(%s, %s) failed to execute", network, address)
		return
	}
	defer listen.Close()
    conn, err := listen.Accept()
    if err != nil {
        fmt.Println("accept failed, err:", err)
        return
    }
    defer conn.Close()
    msg := `Hello World! This is a test demo.`
    conn.Write([]byte(msg))
}
