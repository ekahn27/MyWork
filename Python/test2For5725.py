import signal
from time import sleep

def myInterrupt(signum, frame):
    print('interrupt')

signal.signal(signal.SIGALRM, myInterrupt)
#signal.alarm(1)
signal.setitimer(signal.ITIMER_REAL, 2.0, 1.0)

while(1):
    print('hello world')
    sleep(0.5)

