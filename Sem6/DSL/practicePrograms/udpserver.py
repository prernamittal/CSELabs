import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
ip = socket.gethostname()
port = 12345

sock.bind((ip, port))

while True:
    print("Waiting for client...")
    data, cliAddr = sock.recvfrom(1024)
    print("server received: ", data.decode())
    msg = input("ENter msg: ")
    sock.sendto(msg.encode(), cliAddr)
