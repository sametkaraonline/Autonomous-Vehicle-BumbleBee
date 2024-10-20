import cv2
from picamera2 import Picamera2
from ultralytics import YOLO
import serial
import time
import numpy as np


mesgul = 0

ardunio = serial.Serial('/dev/ttyUSB0', 9600) 

# Initialize the Picamera2
picam2 = Picamera2()
picam2.preview_configuration.main.size = (1280, 720)
picam2.preview_configuration.main.format = "RGB888"
picam2.preview_configuration.align()
picam2.configure("preview")
picam2.start()


# Load the YOLOv8 model
model = YOLO("yolov8n.pt")


def msr():
    mesgul = 1
    ardunio.write(b's')
    time.sleep(1)
    ardunio.write(b'l')
    time.sleep(2)
    ardunio.write(b's')
    time.sleep(1)
    ardunio.write(b'r')
    time.sleep(0.8)
    ardunio.write(b'f')
    time.sleep(1)
    ardunio.write(b's')
    time.sleep(1)
    #ardunio.write(b'r')
    #time.sleep(1)
    mesgul = 0


while True:
    # Capture frame-by-frame
    frame = picam2.capture_array()

    #print(frame.shape)

    # Run YOLOv8 inference on the frame
    results = model(frame)

    #print(len(results[0]))

    # Visualize the results on the frame
    annotated_frame = results[0].plot()

    for box in results[0].boxes:
        x1, y1, x2, y2 = box.xyxy[0]  
        #print(f"Box coordinates: ({x1}, {y1}, {x2}, {y2})")

    #left if x < 1000 250den büyükse sag

    if mesgul == 0:

        if len(results[0]) == 0:
            ardunio.write(b'f')

        else:
            msr()
            #if x1 < 1000 and x1 > 250:
            #    msr()



    # Display the resulting frame
    cv2.imshow("Camera", annotated_frame)

    # Break the loop if 'q' is pressed
    if cv2.waitKey(1) == ord("q"):
        break
    print(mesgul)


# Release resources and close windows
cv2.destroyAllWindows()
