import serial
import time

arduino_port = 'COM3'   # Cambiar por tu puerto real
baud_rate = 9600

# Conectar al Arduino
try:
    ser = serial.Serial(arduino_port, baud_rate, timeout=1)
    time.sleep(2)
except serial.SerialException:
    print(f"No se pudo conectar al puerto {arduino_port}")
    exit()

# Leer datos continuamente
while True:
    data = ser.readline().decode('utf-8').rstrip()
    if data:
        try:
            humidity, temperature = data.split(',')
            print(f"Humedad: {humidity}%, Temperatura: {temperature}°C")
        except ValueError:
            print(f"Formato de datos incorrecto: {data}")
    time.sleep(1)
