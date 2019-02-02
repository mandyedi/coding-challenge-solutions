#! /usr/bin/env python
# -*- coding: Utf-8 -*-

# # www.hellbondhackers.org
  #
  # Timed challenge 8 solution
  # Task: Encode barcode
  #
  # author: mandyedi
  # contact: mandyedi@gmail.com
  #
  # Python version: 2.7.2
  # #

import urllib, urllib2
from time import time
from PIL import Image

url    = "http://www.hellboundhackers.org/challenges/timed/timed7/barcode.php"
cookie = "PHPSESSID=e3013b10f987bd795dc9509bd36b8b93; fusion_user=40536.253b9f990cf2f9be52c660070a166b88"

# # 1st part: opening, downloading...
  # #
  
t1 = time()

# Open and download the image
request = urllib2.Request(url)
request.add_header("COOKIE", cookie)
response = urllib2.urlopen(request)
data = response.read()

file = open("image.png", 'w')
file.write(data)
file.close()

response.close()

# # # #
# 2nd part: Decode the image
# # # #
  
# # Decode the digits
  # 
  # param s string we want to decode
  #
  # return  decoded number as char
  # #
def decode(s):
	if   s == "0001101" or s == "1110010":
		return '0'
	elif s == "0011001" or s == "1100110":
		return '1'
	elif s == "0010011" or s == "1101100":
		return '2'
	elif s == "0111101" or s == "1000010":
		return '3'
	elif s == "0100011" or s == "1011100":
		return '4'
	elif s == "0110001" or s == "1001110":
		return '5'
	elif s == "0101111" or s == "1010000":
		return '6'
	elif s == "0111011" or s == "1000100":
		return '7'
	elif s == "0110111" or s == "1001000":
		return '8'
	elif s == "0001011" or s == "1110100":
		return '9'

# Open image file
image = Image.open("image.png")
width, height = image.size
pix = image.load()

# Check the sart lines
a = pix[10, height/2]
b = pix[11, height/2]
c = pix[12, height/2]

# Calculate the step number
# The first 3 line is always 1 0 1, but some picture's bar code is wider 2x or 3x
if a == 1 and b == 0 and c == 1:
	step = 1
elif a == 1 and b == 1 and c == 0:
	step = 2
elif a == 1 and b == 1 and c == 1:
	step = 3

# Left side digits
digits = ""
for i in range(10 + 3*step, 10 + 45*step, step):
	digits += str(pix[i, height/2])

# Right side digits
for i in range(10 + 50*step, 10 + 92*step, step):
	digits += str(pix[i, height/2])

# Decode the digits
answer = ""
for i in range(0, len(digits), 7):
	answer += decode(digits[i : i+7])

print "Decoded number:", answer
  

# # # #
# 3rd part: post the answer
# # # #

url2 = "http://www.hellboundhackers.org/challenges/timed/timed7/index.php"
post = urllib.urlencode({"barcode": answer, "validity": "valid"})

# Post
request2 = urllib2.Request(url2)
request2.add_header("COOKIE", cookie)
response2 = urllib2.urlopen(request2, post)

t2 = time()
print "Elapsed time: ", t2-t1

response2.close()