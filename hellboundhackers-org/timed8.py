#! /usr/bin/env python
# -*- coding: Utf-8 -*-

# # www.hellbondhackers.org
  #
  # Timed challenge 8 solution
  # Task: You have to find out the value of 'a'.
  #       Post back your answer, where ans = a
  #
  #       a+35x52=186
  #
  # author: mandyedi
  # contact: mandyedi@gmail.com
  #
  # Python version: 2.7.2
  # #

import urllib, urllib2
from time import time

url = "http://www.hellboundhackers.org/challenges/timed/timed8/index.php"
cookie = "PHPSESSID=f6f9a38761fa9d85f5e405c95f39c882; fusion_user=40536.253b9f990cf2f9be52c660070a166b88"

# # 1st part: opening, downloading...
  # #
  
t1 = time()

# Open and download the chal's page
request = urllib2.Request(url)
request.add_header("COOKIE", cookie)
response = urllib2.urlopen(request)
page = response.read()
response.close()

# Search for the numbers
searchA  = "a+"
searchX  = "x"
searchEq = "="
indexA  = page.find(searchA)
indexX  = page.find(searchX,  indexA)
indexEq = page.find(searchEq, indexA)

print "Equation:", page[indexA : indexEq + 4]

first  = page[indexA  + 2 : indexX]
second = page[indexX  + 1 : indexEq]
third  = page[indexEq + 1 : indexEq + 4]

print "First  number:", first
print "Second number:", second
print "Third  number:", third

# #
  # 2nd part: Calculate the difference
  # #
a = int(third) - ( int(first) * int(second) )

print "a =", a

# # 3rd part: post the answer
  # #

url2 = "http://www.hellboundhackers.org/challenges/timed/timed8/index.php?check"
post = urllib.urlencode({"ans": a})

# Post
request2 = urllib2.Request(url2)
request2.add_header("COOKIE", cookie)
response2 = urllib2.urlopen(request2, post)

t2 = time()
print "Elapsed time: ", t2-t1

response2.close()