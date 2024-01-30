import socket
import threading

socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

sender_ip = input("Enter Your System's IP Address: ")
sender_port = int(input("Enter Your System's Port Number: "))

receiver_ip = input("Enter Your Friend's IP Address: ")
receiver_port = int(input("Enter Your Friend's Port Number: "))

socket.bind((sender_ip,sender_port))
def sender():
    while True:
        text = input("\nType the Message: ")
        socket.sendto(text.encode(),(receiver_ip,receiver_port))

def receiver():
    while True:
        msgRcv = socket.recvfrom(1024)
        print("\nMessage from Your Friend: " + msgRcv[0].decode())

t1 = threading.Thread(target=sender)
t2 = threading.Thread(target=receiver)
t1.start()
t2.start()
