#! /usr/bin/env python
# -*- coding: Utf-8 -*-

# # www.hellbondhackers.org
  #
  # Timed challenge 1 solution
  # Task: You will be given a randomly generated md5 hash and your task is to add up all the numbers in the md5 string.
  #       You have two seconds to answer this challenge and your string is: 7dcfd059a13b5003eff5be30d72a8e57
  #
  # author: mandyedi
  # contact: mandyedi@gmail.com
  #
  # Python version: 2.7.2
  # #

import urllib, urllib2
from time import time

url = "http://www.hellboundhackers.org/challenges/timed/timed2/index.php"
cookie = "PHPSESSID=a83dd3626c06f4bf58cd356bc748e2fc; fusion_user=40536.253b9f990cf2f9be52c660070a166b88"

# # First part: opening, downloading...
  # #
  
t1 = time()

# Open and download the chal's page
request = urllib2.Request(url)
request.add_header("COOKIE", cookie)
response = urllib2.urlopen(request)
page = response.read()

# Search for the encoded string
search = "your string is:"
l = len(search)
index = page.find(search)

string = page[index+l+1 : index+l+33]
print "MD5 string:", string

response.close()

# Add up all the numbers
summ = 0

for i in range(0 , len(string)):
	if ord(string[i]) >= 48 and ord(string[i]) <= 57:
		summ += int(string[i])

print "Sum of he numbers:", summ

# # Second part: post the answer
  # #

url2 = "http://www.hellboundhackers.org/challenges/timed/timed2/index.php?check"
post = urllib.urlencode({"ans": summ})

# Post
request2 = urllib2.Request(url2)
request2.add_header("COOKIE", cookie)
response2 = urllib2.urlopen(request2, post)

t2 = time()
print "Elapsed time: ", t2-t1

response2.close()