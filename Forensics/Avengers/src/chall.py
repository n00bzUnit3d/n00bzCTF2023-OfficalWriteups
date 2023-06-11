import os
import cv2
from PIL import Image
mean_height = 300
mean_width = 300
path='../Images/.'
num_of_images = len(os.listdir('.'))
for file in os.listdir('.'):
	if file.endswith('.png'):
		im = Image.open(os.path.join(path, file))

		width, height = im.size
		mean_width += width
		mean_height += height
	else:
		continue
mean_width = int(mean_width / num_of_images)
mean_height = int(mean_height / num_of_images)
for file in os.listdir('.'):
	if file.endswith(".jpg") or file.endswith(".jpeg") or file.endswith("png"):
		im = Image.open(os.path.join(path, file))
		width, height = im.size
		print(width, height)
		imResize = im.resize((mean_width, mean_height), Image.ANTIALIAS)
		imResize.save( file, 'JPEG', quality = 95)
def image_to_video():
	image_folder = '../Images/.'
	video_name = '../Attachment/flag.avi'
	images = [img for img in os.listdir(image_folder)
			if img.endswith(".jpg") or
				img.endswith(".jpeg") or
				img.endswith(".png")]
	frame = cv2.imread(os.path.join(image_folder, images[0]))
	height, width, layers = frame.shape
	video = cv2.VideoWriter(video_name, 0, 1, (width, height))
	for image in images:
		video.write(cv2.imread(os.path.join(image_folder, image)))
	cv2.destroyAllWindows()
	video.release()
image_to_video()
