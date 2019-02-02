#! /usr/bin/env python
# -*- coding: Utf-8 -*-

# # www.hellbondhackers.org
  #
  # Timed challenge 10 solution
  # Task: Find the greatest common divisor
  #       between the following integers: 273 6097 4368 7644
  #
  # author:  mandyedi
  # contact: mandyedi@gmail.com
  #
  # Python version: 2.7.2
  # #

import urllib, urllib2, fractions
from time import time

# # Calculate greatest common divisor of a list of numbers
  #
  # param l list of numbers
  # return  greatest common divisor
  # #
def gcd(l):
	return reduce(fractions.gcd, l)

# # 1st part: opening, downloading...
  # #
url = "http://www.hellboundhackers.org/challenges/timed/timed10/index.php"
cookie = "PHPSESSID=e3013b10f987bd795dc9509bd36b8b93; fusion_user=40536.253b9f990cf2f9be52c660070a166b88"  

t1 = time()

# Open and download the chal's page
request = urllib2.Request(url)
request.add_header("COOKIE", cookie)
response = urllib2.urlopen(request)
page = response.read()
response.close()

# Search for the numbers
searchI  = "following integers: "
searchBr = "<br"
indexI   = page.find(searchI)
indexBr  = page.find(searchBr, indexI)
numbers  = page[indexI + 20 : indexBr].split()

print "Number:", numbers

# #
  # 2nd part: Calculate greatest common divisor
  # #
numbers = [ int(x) for x in numbers ]
answer = gcd(numbers)
print "GCD:", answer
  
# # 3rd part: post the answer
  # #

url2 = "http://www.hellboundhackers.org/challenges/timed/timed10/index.php"
post = urllib.urlencode({"answer": answer})

# Post
request2 = urllib2.Request(url2)
request2.add_header("COOKIE", cookie)
response2 = urllib2.urlopen(request2, post)

t2 = time()
print "Elapsed time: ", t2-t1

response2.close()