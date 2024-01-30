import socket
host=socket.gethostname()
port=12345
s=socket.socket()
s.bind((host, port))
s.listen(5)
conn, addr = s.accept()
print('got connection from: ', addr[0], '(', addr[1], ')')
while True:
        data = conn.recv(1024)
        if not data: break
        conn.send(data)
conn.close()