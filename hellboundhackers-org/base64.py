#! /usr/bin/env python
# -*- coding: Utf-8 -*-

# # Base64 encoder/decoder
  # 
  # author: mandyedi
  # contact: mandyedi@gmail.com
  #
  # Python version: 2.7.2
  # #
  
indexTable = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

# converts char to 8 bits binary
def charToBinary8(c):
	zeros = "00000000"
	decimal = ord(c)
	binary  = bin(decimal)
	
	return  zeros[0 : 8 - len(binary[2:])] + binary[2:]
	
	return  zeros[0 : 6 - len(binary[2:])] + binary[2:]
	
# converts binary to decimal
def binaryToDecimal(binaryString):
	decimal = 0
	binaryString = binaryString[::-1]
	
	for i in range(0, len(binaryString)):
		if binaryString[i] == '1':
			decimal += pow(2, i)
			
	return decimal

# # Base64 Encoder
  #
  # param  s is the string we want to encode
  # return   encoded string
  # #
def encode(s):
	# convert letters to Bit Pattern
	bitPattern = ""
	for i in range(0, len(s)):
			bitPattern += charToBinary8(s[i])
	if len(s) % 3 == 2:
		bitPattern += "00000000"
	elif len(s) % 3 == 1:
		bitPattern += "0000000000000000"
			
	# convert Bit Pattern to 6 bits Bit Pattern
	bitPattern6bit = []
	temp = ""
	for i in range(0, len(bitPattern)):
		if (i+1) % 6 == 0:
			temp += bitPattern[i]
			bitPattern6bit.append(temp)
			temp = ""
		else:
			temp += bitPattern[i]
	
	# convert 6 bits Bit Pattern to Base64-encoded string
	encoded = ""
	for pattern in bitPattern6bit:
		decimal = binaryToDecimal(pattern)
		encoded += indexTable[decimal]
	
	if len(s) % 3 == 2:
		encoded = encoded[0 : len(encoded)-1] + '='
		return encoded
	elif len(s) % 3 == 1:
		encoded = encoded[0 : len(encoded)-2] + '=='
		return encoded
	else:
		return encoded

# # Base64 Decoder
  #
  # param  s is the string we want to decode
  # return   decoded string
  # #
def decode(s):
	# convert Base64-encoded string to Bit Pattern
	bitPattern = ""
	zeros = "000000"
	for i in range(0, len(s)):
			if s[i] == '=':
				bitPattern += ""
			else:
				value = indexTable.find(s[i])
				binary = bin(value)
				bitPattern += zeros[0 : 6 - len(binary[2:])] + binary[2:]
	
	# convert Bit Patettern to 8 bits Bit Pattern
	bitPattern8bit = []
	temp = ""
	for i in range(0, len(bitPattern)):
		if (i+1) % 8 == 0:
			temp += bitPattern[i]
			bitPattern8bit.append(temp)
			temp = ""
		else:
			temp += bitPattern[i]
		
	# convert 8 bits Bit Pattern to decoded string
	decoded = ""
	for pattern in bitPattern8bit:
		decoded += chr(binaryToDecimal(pattern))
	
	return decoded