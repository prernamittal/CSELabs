import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
ip = socket.gethostname()
port = 12345

while True:
    msg = input("ENter msg: ")
    sock.sendto(msg.encode(), (ip,port))
    data, serverAddr = sock.recvfrom(1024)
    print("Received from server: ", data.decode())