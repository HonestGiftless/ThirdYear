import cv2
import numpy as np
cv2.namedWindow("Image", cv2.WINDOW_NORMAL)

cam = cv2.VideoCapture(0)
cam.set(cv2.CAP_PROP_AUTO_EXPOSURE, 1)
cam.set(cv2.CAP_PROP_EXPOSURE, -3)
cam.set(cv2.CAP_PROP_AUTO_WB, 0)


#blue
lower_1 = np.array([95, 70, 140])
upper_1 = np.array([105, 255, 255])

#green
lower_2 = np.array([50, 20, 120])
upper_2 = np.array([90, 120, 255])

#red
lower_3 = np.array([170, 100, 90])
upper_3 = np.array([255, 255, 255])


pixel = None
while cam.isOpened():
    _, frame = cam.read()
    frame = cv2.GaussianBlur(frame, (21, 21), 0)
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    mask_1 = cv2.inRange(hsv, lower_1, upper_1)
    mask_2 = cv2.inRange(hsv, lower_2, upper_2)
    mask_3 = cv2.inRange(hsv, lower_3, upper_3)

    contours_1, _ = cv2.findContours(mask_1, cv2.RETR_EXTERNAL,
                                    cv2.CHAIN_APPROX_SIMPLE)
    contours_2, _ = cv2.findContours(mask_2, cv2.RETR_EXTERNAL,
                                    cv2.CHAIN_APPROX_SIMPLE)
    contours_3, _ = cv2.findContours(mask_3, cv2.RETR_EXTERNAL,
                                    cv2.CHAIN_APPROX_SIMPLE)

    
    if len(contours_1) > 0:
        c = max(contours_1, key=cv2.contourArea)
        (x, y), radius = cv2.minEnclosingCircle(c)
        if radius > 20:
            cv2.circle(frame, (int(x), int(y)),int(radius),
                                (0, 255, 255, 0), 0)
            pixel = "Blue"

    if len(contours_2) > 0:
        c = max(contours_2, key=cv2.contourArea)
        (x, y), radius = cv2.minEnclosingCircle(c)
        if radius > 20:
            cv2.circle(frame, (int(x), int(y)),int(radius),
                                (0, 255, 255, 0), 0)
            pixel = "Green"

    if len(contours_3) > 0:
        c = max(contours_3, key=cv2.contourArea)
        (x, y), radius = cv2.minEnclosingCircle(c)
        if radius > 20:
            cv2.circle(frame, (int(x), int(y)),int(radius),
                                (0, 255, 255, 0), 0)
            pixel = "Red"


    cv2.putText(frame, f"HSV = {pixel}", (10, 30),
                cv2.FONT_HERSHEY_COMPLEX, 0.7, (255, 255, 0))
    cv2.imshow("Image", frame)
    pixel = None 
    key = cv2.waitKey(50)
    if key == ord('q'):
        break
 
cv2.destroyAllWindows()