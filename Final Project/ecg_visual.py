import serial
import matplotlib.pyplot as plt
from collections import deque
import chobo

# Initialize serial connection with Arduino
ser = serial.Serial('/dev/cu.usbmodem14101', 9600)  # Replace 'COM3' with your Arduino's serial port






while True:
    data = ser.readline().decode().strip()  # Read data from Arduino
    print(data)
    # MAP

    window.line.fill((255,255,255))

    height_new = height - inByte;
    height_old = height_new;
    window.line()
    if (xPos >= width):
        xPos = 0
        window.fill((0,0,0))
    else:
    # increment the horizontal position:
        xPos = xPos + 1
#
# # Initialize a deque to store data points
# x_data = deque(maxlen=100)  # Adjust maxlen according to how many data points you want to display
# y_data = deque(maxlen=100)
# # Create a plot
# plt.ion()  # Turn on interactive mode
# fig, ax = plt.subplots()
# line, = ax.plot(x_data, y_data)
# ax.set_xlabel('Time')
# ax.set_ylabel('Value')
#
# # Start reading and plotting data
# try:
#     while True:
#         data = ser.readline().decode().strip()  # Read data from Arduino
#         value = float(data)  # Convert data to float
#         x_data.append(len(x_data))  # Append new x value (time)
#         y_data.append(value)  # Append new y value (Arduino data)
#
#         # Update plot
#         line.set_xdata(x_data)
#         line.set_ydata(y_data)
#         ax.relim()
#         ax.autoscale_view()
#
#         # Redraw the plot
#         plt.draw()
#         plt.pause(0.001)  # Pause to allow time for the plot to update
# except KeyboardInterrupt:
#     print("Plotting stopped by user")
#
# # Close serial connection
# ser.close()
