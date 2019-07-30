#Built in Python
# A Simple Preforking Echo Server

#For forking
import os
#for networking
import socket
#For keyboard interrupt
import sys

HOST='127.0.0.1' # localhost
PORT=65432 #Port for listening
children=6;



#Create a server socket to listen in
s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)
s.bind((HOST, PORT))
s.listen()

#Each child must receive a request from a single client os one fork per client
def childToParent():
    child= os.fork()
    #If 0 then it is a child process
    if(child==0):
        print("We have a child", os.getpid())
        conn, addr = s.accept()
        conn.send(os.getpid," is connected with you")
        try:
            while True:             
                data = conn.recv(1024)
                if not data:
                    break
                else:
                    print (data)
        except KeyboardInterrupt:
            conn.close()
            #sys.exit()

    else:
        print("We have the sever", os.getpid())



#Now make a fork of child processes
#preforking means server creates the child processes
for child in range(children):
    childToParent();
    sys.exit()
    

