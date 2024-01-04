import cv2
import numpy as np
import time

lower_discoloration = np.array([25, 50, 70])
upper_discoloration = np.array([35, 255, 255])

lower_tree = np.array([36,50,70])
upper_tree = np.array([89,255,255])

i=0

video = cv2.VideoCapture(0)

while True:
    success, img = video.read()
    print(success)

    font = cv2.FONT_HERSHEY_SIMPLEX

    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV) 

    mask_discoloration = cv2.inRange(hsv, lower_discoloration, upper_discoloration)
    mask_tree = cv2.inRange(hsv, lower_tree, upper_tree)

    output_discoloration = cv2.bitwise_and(img, img, mask = mask_discoloration)
    output_tree = cv2.bitwise_and(img, img, mask = mask_tree)

    kernel = np.ones((5, 5),np.uint8)
    mask_tree = cv2.erode(mask_tree, kernel)

    cv2.imshow('mask_tree', mask_tree)

    contours, _ = cv2.findContours(mask_tree, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    for cnt in contours:
        approx = cv2.approxPolyDP(cnt, 0.01*cv2.arcLength(cnt, True), True)
        cv2.drawContours(img, [approx], 0, (0, 0, 0), 5)
        
        area = cv2.contourArea(cnt)


    discoloration = cv2.countNonZero(mask_discoloration)/(area)
    colorPercent = (discoloration * 100)

    cv2.putText(output_discoloration, str(np.round(colorPercent, 2)), (50, 50), font, 1, (0, 255, 255), 2, cv2.LINE_4)
    
    # cv2.imshow('img', img)
    # cv2.imshow('mask_disc', mask_discoloration)
    # cv2.imshow('output_disc', output_discoloration)
    # cv2.imshow('mask_tree', mask_tree)
    # cv2.imshow('output_tree', mask_tree)

    if (colorPercent > 5):
        mask = np.zeros(img.shape[:2], dtype="uint8")

        rect = (100, 60, 400, 410)

        fgModel = np.zeros((1, 65), dtype="float")
        bgModel = np.zeros((1, 65), dtype="float")

        start = time.time()
        (mask, bgModel, fgModel) = cv2.grabCut(img, mask, rect, bgModel,
	        fgModel, 5, mode=cv2.GC_INIT_WITH_RECT)
        end = time.time()

        values = (
	        ("Definite Background", cv2.GC_BGD),
	        ("Probable Background", cv2.GC_PR_BGD),
	        ("Definite Foreground", cv2.GC_FGD),
	        ("Probable Foreground", cv2.GC_PR_FGD),
        )

        outputFinalMask = np.where((mask == cv2.GC_BGD) | (mask == cv2.GC_PR_BGD),
        	0, 1)

        outputFinalMask = (outputFinalMask * 255).astype("uint8")

        outputFinal = cv2.bitwise_and(img, img, mask=outputFinalMask)

        hsvFinal = cv2.cvtColor(outputFinal, cv2.COLOR_BGR2HSV) 

        mask_discolorationFinal = cv2.inRange(hsvFinal, lower_discoloration, upper_discoloration)
        mask_treeFinal = cv2.inRange(hsvFinal, lower_tree, upper_tree)

        discolorationFinal = cv2.countNonZero(mask_discolorationFinal)/(hsvFinal.size/3)
        colorPercentFinal = (discolorationFinal * 100)

        if (colorPercentFinal > 5):
            cv2.imwrite('tree'+str(i)+'.jpg', img)
            i+=1
        
    

    k = cv2.waitKey(5) & 0xFF
    if k == 27:
        break

cv2.destroyAllWindows()

