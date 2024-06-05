# Import packages
import sys # for system clean-up
import pygame # for game window
import serial # for compatability w/ Arduino

# set up connection to Arduino via port
ser = serial.Serial('/dev/cu.usbmodem14101', 9600)

# Initialize pygame
pygame.init()

# Set up the window
window_width = 1500
window_height = 1000

# display window
window = pygame.display.set_mode((window_width, window_height))
window.fill((255, 255, 255))  # Fill with white color
pygame.display.set_caption("ECG")

# Define a pixel color (red)
pixel_color = (255, 0, 0)

# Define the starting position of the pixel
pixel_x = 0
# Center of the window vertically
pixel_y = window_height // 2

# initialize previous cords to start at same as start position
pixel_x_prev = pixel_x
pixel_y_prev = pixel_y

# Define the pixel velocity (movement speed)
pixel_velocity = 3  # 3 Pixels per frame

# start reading in values until stopped
running = True
while running:
    # Check for pygame quit
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            # end program
            running = False

    # Move the pixel horizontally
    pixel_x += pixel_velocity

    # If the pixel goes past the right side of the window, reset its position to the right side of the screen
    if pixel_x >= window_width:
        pixel_x = 0
        pixel_x_prev = 0
        # Clear the window by filling with white color
        window.fill((255, 255, 255))

    # Read data from Arduino convert to ASCII and strip whitespaces
    data = ser.readline().decode().strip()

    # Data reads in upside down so flipped it by subtracting from max
    data = 1023 - float(data)
    # scaled the read in data as percent of max possible signal
    scale = data / 1023
    # Calculate the position for ECG screen centered at 500th pixel
    pixel_y = scale * 200 + 500

    # Change the color of the single pixel to red
    window.set_at((pixel_x, int(pixel_y)), pixel_color)

    # Draw red line from the previous pixel to the new read in values with a width of two
    pygame.draw.line(window, pixel_color, (pixel_x_prev, pixel_y_prev), (pixel_x, pixel_y), 2)

    # set the current X and Y to the prev to be stored for next iteration
    pixel_x_prev = pixel_x
    pixel_y_prev = pixel_y

    # Update the display
    pygame.display.update()

    # Control the frame rate (e.g., 9600 frames per second)
    # corresponds to baud rate
    pygame.time.Clock().tick(9600)

# Quit pygame and clean up resources
pygame.quit()
sys.exit()
