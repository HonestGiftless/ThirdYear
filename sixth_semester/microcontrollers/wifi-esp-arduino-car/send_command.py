from send_message_to_arduino import go

class Send:
  def my_send(self):
    go.forward()
    go.left()
    go.right()
    go.stop()
