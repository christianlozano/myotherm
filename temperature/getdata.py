import serial

while True:
        ser = serial.Serial('/dev/ttyACM0', 9600)
        line = ser.readline()
        print(line)
print('end')
