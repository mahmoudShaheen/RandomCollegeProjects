import time
import subprocess
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BOARD)
GPIO.setup(8, GPIO.IN)

while True:
        if (GPIO.input(8) == True):
                print " Motion Detected"
                subprocess.Popen("sudo ./cam.sh", shell=True)
                time.sleep(3)
 
        else:
                print "There is No motion"

time.sleep(1) 
