import serial.tools.list_ports

# Función para detectar el puerto al que está conectado el Arduino
def detectBoardPort():
    ports = serial.tools.list_ports.comports()
    
    for port in ports:
        if 'Arduino' in port.description or 'Aduino' in port.description:
            print(f"Board.description: {port.device}")
            print(f"HWID: {port.hwid}")
            
            return port.device  # Devuelve el puerto serial (ej. COM3, /dev/ttyUSB0)
    
    return None  # Si no se encuentra ningún dispositivo Arduino

# Detecta el puerto del Arduino
port = detectBoardPort()

if port:
    print(f"Se ha encontrado un Arduino en el puerto: {port}")
else:
    print("No se ha encontrado un Arduino conectado.")
