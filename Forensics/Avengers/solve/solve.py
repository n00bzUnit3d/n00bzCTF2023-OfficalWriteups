from PIL import Image
from PIL import ImageDraw
from PIL import ImageFont
import pytesseract
import cv2
 
flag_video = cv2.VideoFlag_video('../Attachment/flag.avi') # Opening the video
 
img_number = 0

#========Splitting the video into frames=======

while (True):
 
    success, img = flag_video.read()
 
    if success:
        cv2.imwrite(f'img_{img_number}.png', img)
    else:
        break
 
    img_number = img_number+1
 
flag_video.release()

#=======Reading the data from each frame and storing into a variable=======

flag = []
for i in range(114):
	x = pytesseract.image_to_string(Image.open(f'img_{i}'+'.png'))
	for j in x:
		if j in '01':
			flag.append(j)
		else:
			continue
#=======Decoding the binary into text and printing the flag=======
decoded_flag=''
for i in flag:
	decoded_flag += str(i)
decoded_flag = [chr(int(decoded_flag[i:i+8],2)) for i in range(0, len(decoded_flag), 8)]
print(''.join(decoded_flag))