from machine import UART
import uos

# import network

# wifi_ssid = "MicroPython-37bdff"
# wifi_password = "micropythoN"

# wifi = network.WLAN(network.STA_IF)
# wifi.active(True)
# wifi.connect(wifi_ssid, wifi_password)

# while not wifi.isconnected():
#     pass

# print("Connected to Wi-Fi")

class Go:
  def __init__(self):
    self.uart = UART(0, 115200)
    self.uart.init(115200, bits=8, parity=None, stop=1)
    uos.dupterm(None, 1) # отключаем репл, чтобы можно было прочесть данные

  def forward(self):
    self.uart.write('f')
  
  def left(self):
    self.uart.write('l')
  
  def right(self):
    self.uart.write('r')

  def stop(self):
    self.uart.write('s')

go = Go()
# go.forward() - example call func
