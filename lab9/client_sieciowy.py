import socket

s = socket.socket()
s.connect(('127.0.0.1', 8080))

while True:
    try:
        msg = input()
        s.send(msg.encode())
        if msg == 'exit': break
        print(s.recv(1024).decode())
    except (EOFError, KeyboardInterrupt):
        break

s.close()
