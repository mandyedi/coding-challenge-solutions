#! /usr/bin/env python
# -*- coding: Utf-8 -*-

# # www.hellbondhackers.org
  #
  # Timed challenge 3 solution
  # Task: You will be given a randomly generated md5 hash
  #       and your task is to crack the hash using the
  #       wordlist found here and return the plaintext.
  #       You have three seconds to answer this challenge
  #       and your string is: 4d5257e5acc7fcac2f5dcd66c4e78f9a
  #
  # author: mandyedi
  # contact: mandyedi@gmail.com
  #
  # Python version: 2.7.2
  # #

import urllib, urllib2, md5
from time import time

url = "http://www.hellboundhackers.org/challenges/timed/timed3/index.php"
cookie = "PHPSESSID=f6f9a38761fa9d85f5e405c95f39c882; fusion_user=40536.253b9f990cf2f9be52c660070a166b88"

# # 1st part: opening, downloading...
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

HBH_hash = page[index+l+1 : index+l+33]
print "MD5 hash:", HBH_hash

response.close()

# #
  # 2nd part: Crack the hash
  # #

file = open("timed3.txt", 'r')
words = file.readline().split(',')
file.close()

for word in words:
	hash = md5.md5(word).hexdigest()
	if hash == HBH_hash:
		answer = word

print "The cracked hash is:", answer

# # 3rd part: post the answer
  # #

url2 = "http://www.hellboundhackers.org/challenges/timed/timed3/index.php?check"
post = urllib.urlencode({"ans": answer})

# Post
request2 = urllib2.Request(url2)
request2.add_header("COOKIE", cookie)
response2 = urllib2.urlopen(request2, post)

t2 = time()
print "Elapsed time: ", t2-t1

response2.close()