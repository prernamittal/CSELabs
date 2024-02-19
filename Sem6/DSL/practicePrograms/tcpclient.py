import socket

ip = socket.gethostname()
port = 12345
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

sock.connect((ip, port))

name = input("Enter your name: ")
sock.send(name.encode())

name = sock.recv(1024).decode()
print(name, "has joined the chat")

while True:
    msg =  sock.recv(1024).decode()
    print(f"{name}: {msg}")
    if(msg=="exit"):
        break
    msg = input("ENter your msg: ")
    sock.send(msg.encode())