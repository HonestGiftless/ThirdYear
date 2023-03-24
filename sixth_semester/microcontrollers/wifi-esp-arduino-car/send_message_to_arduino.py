from machine import UART
import uos

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
go.forward()
