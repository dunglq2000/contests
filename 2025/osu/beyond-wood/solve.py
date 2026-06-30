from PIL import Image
import random

FLAG = Image.open("output.png")
width, height = FLAG.size

key = [random.randrange(0, 256) for _ in range(width+height+3)]

out = FLAG.copy()
for i in range(width):
    for j in range(height):
        pixel = FLAG.getpixel((i, j))
        pixel = tuple(x ^ k for x, k in zip(pixel, key))
        oldi, oldj = (i - 2134266) * pow(727, -1, width) % width, (j - 4501511) * pow(727, -1, height) % height
        # newi, newj = (2134266 + i * 727) % width, (4501511 + j * 727) % height 
        out.putpixel((oldi, oldj), pixel)

out.save("flag.png")