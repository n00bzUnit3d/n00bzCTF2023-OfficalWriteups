from PIL import Image
import csv

def decode_coordinate(coord):
    x, y = map(int, coord.split(','))
    return (x, y)

def decode_coordinates(encoded_coordinates):
    return [decode_coordinate(coord) for coord in encoded_coordinates]

# Read the black pixel coordinates from the CSV file
with open("secret.csv", "r") as f:
    reader = csv.reader(f)
    next(reader) # Skip the header row
    encoded_coordinates = [row[0] for row in reader]

decoded_coordinates = decode_coordinates(encoded_coordinates)

# Recreate the QR code image
image = Image.new("1", (100, 100), color=255)
for x, y in decoded_coordinates:
    image.putpixel((x, y), 0)

image.save("recreated_qr_code.png")
