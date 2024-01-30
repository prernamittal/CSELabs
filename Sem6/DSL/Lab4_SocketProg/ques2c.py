import socket
HOST = '127.0.0.1' 
PORT = 31621
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
name = input(str("\nEnter your name: ")) 
while True:
    # print("Waiting for user1...")
    # name = input(str("Enter your name: "))
    # s.sendto(name.encode(),(HOST,PORT))
    # data,addr = s.recvfrom(1024)
    # print(name, "has joined the chat room\nEnter [e] to exit chat room\n")
    # message = input(str("Me : "))
    # if message == "[e]":
    #     message = "Left chat room!"
    #     s.sendto(message.encode(),(HOST,PORT))
    #     print("\n")
    #     break
    # s.sendto(message.encode(),(HOST,PORT))
    # message = s.recvfrom(1024)
    # print(name, ":", message[0].decode())

    sendmsg = input(str("Type some text to send: "))
    print("Client sent:",sendmsg)
    s.sendto(sendmsg.encode(), (HOST,PORT))

    msg = s.recvfrom(1024)
    print("Client received:",msg[0].decode())