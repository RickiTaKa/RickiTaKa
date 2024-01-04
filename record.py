import cv2

cap = cv2.VideoCapture(0)

width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))

writer = cv2.VideoWriter('dronerecording.mp4', cv2.VideoWriter_fourcc(*'MP4V'), 25.0, (width,height))


while True:
    ret,frame= cap.read()

    while(ret):

        writer.write(frame)

        cv2.imshow('Original', frame)

        if cv2.waitKey(1) & 0xFF == 27:
            break

        ret,frame= cap.read()
    
    break


cap.release()
writer.release()
cv2.destroyAllWindows()