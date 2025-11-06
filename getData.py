import serial
import time

from supabase import create_Client, Client
from getPort import port

url="https://qnnpykmfuzvykchaxowp.supabase.co"
key="eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InFubnB5a21mdXp2eWtjaGF4b3dwIiwicm9sZSI6ImFub24iLCJpYXQiOjE3NjA2MjMxMTMsImV4cCI6MjA3NjE5OTExM30.noxFKApJI0UBPzEhoy1eWerrbgiJ3WguxWFcpnh3ZPU"
supabase: Client = create_Client(url, key)

arduino_port = port # Don't worry by the port
baud_rate = 9600 # Baudios
ser = serial.Serial(arduino_port, baud_rate, timeout=1)

time.sleep(2)

while True:
    data = ser.readline().decode('utf-8').rstrip()
    #print(data)
    if data:
        try:
            humidity, temperature = data.split(",")
            humidity = float(humidity)
            temperature = float(temperature)

            # --- ENVÍO A SUPABASE ---
            response = supabase.table("data").insert({
                "humidity": humidity,
                "temperature": temperature
            }).execute()

            print("✅ Datos enviados:", humidity, temperature)
        except ValueError:
            print("⚠️ Formato de datos inválido:", data)
        except Exception as e:
            print("❌ Error al enviar a Supabase:", e)
    time.sleep(1)
