import socket
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
udp_host = socket.gethostname()
udp_port = 9991
s.bind((udp_host, udp_port))
while True:
    print("Waiting for server...")
    data,addr = s.recvfrom(1024)
    print("Received Time:",data.decode()," from",addr)