#! /usr/bin/env python
# -*- coding: Utf-8 -*-

# # www.hellbondhackers.org
  #
  # Timed challenge 5 solution
  # Task: Your goal is to make 1772 into 1337,   
  #       and submit how you did it: plus_num, or minus_num
  #       using ?password=answer, where "answer" = plus_num, or minus_num
  #
  # author: mandyedi
  # contact: mandyedi@gmail.com
  #
  # Python version: 2.7.2
  # #

import urllib, urllib2
from time import time

url = "http://www.hellboundhackers.org/challenges/timed/timed5/index.php"
cookie = "PHPSESSID=f6f9a38761fa9d85f5e405c95f39c882; fusion_user=40536.253b9f990cf2f9be52c660070a166b88"

# # 1st part: opening, downloading...
  # #
  
t1 = time()

# Open and download the chal's page
request = urllib2.Request(url)
request.add_header("COOKIE", cookie)
response = urllib2.urlopen(request)
page = response.read()

# Search for the number
search = "to make "
l = len(search)
index = page.find(search)

number = page[index + l : index + l + 5]
print "The number:", number

response.close()

# #
  # 2nd part: Calculate the difference
  # #
difference = 1337 - int(number)
print "difference:", difference

if difference > 0:
	answer = "plus_%d" % difference
else:
	answer = "minus_%d" % -difference

print "answer:", answer

# # 3rd part: post the answer
  # #

url2 = "http://www.hellboundhackers.org/challenges/timed/timed5/index.php?password=%s" % answer

# Send the answer
request2 = urllib2.Request(url2)
request2.add_header("COOKIE", cookie)
response2 = urllib2.urlopen(request2)

t2 = time()
print "Elapsed time: ", t2-t1

#response2.close()