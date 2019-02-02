#! /usr/bin/env python

# # www.hackthissite.org
  #
  # Programming mission 2 solution
  # Task:
  # The pixels in the above image are numbered 0..99 for the first row,
  # 100..199 for the second row etc. 
  # White pixels represent ascii codes.
  # The ascii code for a particular white pixel is equal to the offset from the last white pixel.
  # For example, the first white pixel at location 65 would represent ascii code 65 ('A'),
  # the next at location 131 would represent ascii code (131 - 65) = 66 ('B') and so on.
  #
  # The text contained in the image is the answer encoded in Morse,
  # where "a test" would be encoded as ".- / - . ... -"
  #
  # author: mandyedi
  # contact: mandyedi@gmail.com
  #
  # Python version: 2.7.2
  # #

import urllib, urllib2
import morse
from time import time
from PIL import Image

#url    = "http://www.hackthissite.org/missions/prog/2/PNG"
#cookie = "PHPSESSID=5b25f5sdspjsobpv8a35e3kti2"

# # 1st part: opening, downloading...
  # #
  
t1 = time()

# Open and download the image
#request = urllib2.Request(url)
#request.add_header("COOKIE", cookie)
#response = urllib2.urlopen(request)
#data = response.read()

#file = open("prog2.png", 'w')
#file.write(data)
#file.close()

#response.close()

# # # #
# 2nd part: Decode the image
# # # #
code = {
			' ': '/', # it is only for a mission on hackthissite.org, otherwise use ' '
			'a': '.-',
			'b': '-...',
			'c': '-.-.',
			'd': '-..',
			'e': '.',
			'f': '..-.',
			'g': '--.',
			'h': '....',
			'i': '..',
			'j': '.---',
			'k': '-.-',
			'l': '.-..',
			'm': '--',
			'n': '-.',
			'o': '---',
			'p': '.--.',
			'q': '--.-',
			'r': '.-.',
			's': '...',
			't': '-',
			'u': '..-',
			'v': '..-',
			'w': '.--',
			'x': '-..-',
			'y': '-.--',
			'z': '--..',
			'1': '.----',
			'2': '..---',
			'3': '...--',
			'4': '....-',
			'5': '.....',
			'6': '-....',
			'7': '--...',
			'8': '---..',
			'9': '----.',
			'0': '.....',
			'.': '.-.-.-',
			',': '--..--',
			'?': '..--..',
			'\'': '.----.',
			'!': '-.-.--',
			'/': '-..-.',
			'(': '-.--.',
			')': '-.--.-',
			'&': '.-...',
			':': '---...',
			';': '-.-.-.',
			'=': '-...-',
			'+': '.-.-.',
			'-': '-....-',
			'_': '..--.-',
			'"': '.-..-.',
			'$': '...-..-',
			'@': '.--.-.'
		}

image = Image.open("prog2.png")
width, height = image.size
pix = image.load()


s      = ""
last   = 0
index  = 0
for i in range(0, height-1):
	for j in range(0, width-1):
		if pix[j, i] == 1:
			s    += chr(index - last)
			last =  index
		index += 1

print s

# # # #
# 3rd part: post the answer
# # # #

#url2 = "http://www.hellboundhackers.org/challenges/timed/timed7/index.php"
#post = urllib.urlencode({"barcode": answer, "validity": "valid"})

# Post
#request2 = urllib2.Request(url2)
#request2.add_header("COOKIE", cookie)
#response2 = urllib2.urlopen(request2, post)

t2 = time()
print "Elapsed time: ", t2-t1

#response2.close()