#!/usr/bin/env python
# coding: utf-8

import serial
from datetime import datetime

ser = serial.Serial('/dev/ttyACM0', 9600, timeout=5)
ser.flush()


while(True):

    data = ser.readline()

    while(data == ''):
        data = ser.readline()

    print(data)

    if (data.count('Cartao')):
    	print("Achei um Cartao")

    elif(data.count('Chaveiro')):
    	print("Achei um Chaveiro")