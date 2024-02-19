import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
ip = socket.gethostname()
port = 12345

sock.bind((ip, port))
sock.listen()

print("Waiting for connection...")
conn, cliAddr = sock.accept()

name = conn.recv(1024).decode()
print(name, "has connected")

name = input("enter your name: ")
conn.send(name.encode())

while True:
    msg = input(str("Me: "))
    if msg == "exit":
        conn.close()
        break
    conn.send(msg.encode())
    msg=conn.recv(1024).decode()
    print(msg)


