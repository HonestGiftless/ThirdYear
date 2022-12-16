import pyautogui, cv2, numpy as np
from matplotlib import pyplot as plt
from mss import mss

def coords():
    Dino = cv2.imread('t-rex.png', cv2.IMREAD_GRAYSCALE)
    w, h = Dino.shape[::-1]
    image = pyautogui.screenshot()
    Shot = cv2.cvtColor(np.array(image), cv2.COLOR_RGB2GRAY, )
    res = cv2.matchTemplate(Shot, Dino, cv2.TM_CCOEFF)
    min_val, max_val, bottom_right, top_left = cv2.minMaxLoc(res) 
    return top_left[0]+w+75, top_left[1], w-10, h-16 
 
def draw_rectangle(screen, top_left, w, h):
    cv2.rectangle(screen, top_left, [top_left[0] + w, top_left[1] + h - 15], 255, 4)
    plt.subplot(1, 1, 1)
    plt.imshow(screen, cmap='gray')
    plt.axis('off')
    plt.suptitle('Trex detected is: ')
    plt.show()

def taps():
    pyautogui.keyDown('space')
    pyautogui.sleep(0.15) 
    pyautogui.keyUp('space')
    return 1

def play(x, y, width, height):
    if x != 0 and y != 0 and width != 0 and height != 0:
        pyautogui.press('space')
        pyautogui.keyDown('down')
        obj = {'top': y, 'left': x,  'width': width * 2 + 15, 'height': height}
        sampler = np.sum(np.array(mss().grab(obj), dtype=np.uint8)) - 10

        with mss() as sct:
            while True:
                img = np.sum(np.array(sct.grab(obj), dtype=np.uint8))
                if img < sampler:
                    obj['left'] += taps()
    else:
        print("Not founded")

def start_game():
    x, y, width, height = coords()
    play(x, y, width, height)

start_game()