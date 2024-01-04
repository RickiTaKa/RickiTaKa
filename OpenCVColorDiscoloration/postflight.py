import cv2
import numpy as np
import time

# read image
img = cv2.imread('glarepea.jpg')

while True:
    # convert to gray
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    grayimg = gray


    GLARE_MIN = np.array([0, 0, 50],np.uint8)
    GLARE_MAX = np.array([0, 0, 225],np.uint8)

    hsv_img = cv2.cvtColor(img,cv2.COLOR_BGR2HSV)

    #inpaint
    mask1 = cv2.threshold(grayimg , 220, 255, cv2.THRESH_BINARY)[1]
    result1 = cv2.inpaint(img, mask1, 0.1, cv2.INPAINT_TELEA)

    cv2.imshow("NORMAL", img)
    cv2.imshow("INPAINT", result1)

    # Break with esc key
    if cv2.waitKey(1) & 0xFF == ord('q'): 
        break


cv2.destroyAllWindows()
