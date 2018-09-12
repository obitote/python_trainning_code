from urllib import request,error
import socket

try:
    response = request.urlopen('https://www.baidu.com', timeout = 0.01)
except error.URLError as e:
    print(type(e.reason))
    if isinstance(e.reason, socket.timeout):
        print('TIME OUT')
