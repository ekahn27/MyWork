from threading import Timer
from time import sleep

def myInterrupt():
    global sampleRFID
    print('interrupt')
    sampleRFID= True
    timer= Timer(1.0, myInterrupt)
    timer.start()

sampleRFID= True
while(1):
    if(sampleRFID):
        #sample
        print('sample')
        sampleRFID= False
#        timer= Timer(1.0, myInterrupt)
#        timer.start()
    print('hello world')
    sleep(0.3)

