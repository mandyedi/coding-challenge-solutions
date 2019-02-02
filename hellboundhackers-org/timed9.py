#! /usr/bin/env python
# -*- coding: Utf-8 -*-

# # www.hellbondhackers.org
  #
  # Timed challenge 9 solution
  # Task: Determine the sum of the first 58 numbers in the fibonacci
  #       sequence beginning with 4 and 14.
  #
  # author:  mandyedi
  # contact: mandyedi@gmail.com
  #
  # Python version: 2.7.2
  # #

import urllib, urllib2
from time import time

# # Caluclate the fibonacci sequence
  # 
  # param n limit of the sequence
  # return  list of fibonacci numbers
  # #
def fib(n, a, b):
	l = [a]
	for i in range(0, n-1):
		l.append(b)
		a, b = b, a + b
	return l

url = "http://www.hellboundhackers.org/challenges/timed/timed9/index.php"
cookie = "PHPSESSID=e3013b10f987bd795dc9509bd36b8b93; fusion_user=40536.253b9f990cf2f9be52c660070a166b88"

# # 1st part: opening, downloading...
  # #
  
t1 = time()

# Open and download the chal's page
request  = urllib2.Request(url)
request.add_header("COOKIE", cookie)
response = urllib2.urlopen(request)
page     = response.read()
response.close()

# Search for the number
# How many numbers need to sum in the fibonacci sequence
searchN = "the first "
searchA = "with"
searchB = "and"

indexN = page.find(searchN)
indexA = page.find(searchA, indexN)
indexB = page.find(searchB, indexN)

n      = long(page[indexN      + 10 : indexN      + 12])
a      = long(page[indexA      +  5 : indexB -  1])
b      = long(page[indexB      +  4 : indexB +  6])

print "The first %d numbers need to be summarized." % n
print "Beginning width %d and %d." % (a, b)

# #
  # 2nd part: Sum of the first x numbers in the fibonacci sequence
  # #

# List of fibonacci numbers
l = fib(n, a, b)

# Sum
sum = 0
for i in range(0, n):
	sum += l[i]

print "Sum:", sum

# # 3rd part: post the answer
  # #

url2 = "http://www.hellboundhackers.org/challenges/timed/timed9/index.php"
post = urllib.urlencode({"answer": sum})

# Post
request2 = urllib2.Request(url2)
request2.add_header("COOKIE", cookie)
response2 = urllib2.urlopen(request2, post)

t2 = time()
print "Elapsed time: ", t2-t1

response2.close()