'''
* Team Id : 4961
* Author List: Hiten Arya
* Filename: echo.py
* Theme: Thirsty Crow
'''
import serial
import time
if __name__ == "__main__":
    ser = serial.Serial("COM8", 9600, timeout=0.2)
    while True:
        #taking input from user and storing it in user_input
        user_input = input("Enter key: ")
        #sending user's input to main.c
        ser.write((user_input).encode())
        #receiving data from main.c and storing it in response
        response = ser.read(255)
        #printing the response we got
        print(str(response))
    ser.close()
        
        
