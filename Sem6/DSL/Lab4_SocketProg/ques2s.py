import socket
HOST = '127.0.0.1' 
PORT = 31621 
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind((HOST, PORT))
while True:
    # print("Waiting for user2...")
    # name = input(str("Enter your name: "))
    # s.sendto(name.encode(),(HOST,PORT))
    # data,addr = s.recvfrom(1024)
    # message = input(str("Me : "))
    # if message == "[e]":
    #     message = "Left chat room!"
    #     s.sendto(message.encode(),(HOST,PORT))
    #     print("\n")
    #     break
    # s.sendto(message.encode(), (HOST,PORT))
    # message = s.recvfrom(1024)
    # print(name, ":", message[0].decode())
    
    print("##### SERVER IS LISTENING #####")
    msg,addr = s.recvfrom(1024)
    print("Server received:",msg.decode())

    sendmsg = input(str("Type some text to send: "))
    print("Server sent:",sendmsg)
    s.sendto(sendmsg.encode(), addr)