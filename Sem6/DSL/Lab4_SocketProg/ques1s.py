import socket
import time
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
udp_host = socket.gethostname()
udp_port = 9991
while True:
    currentTime = time.ctime(time.time()) + "\r\n"
    sock.sendto(currentTime.encode(),(udp_host,udp_port))
