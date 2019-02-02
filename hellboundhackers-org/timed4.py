#! /usr/bin/env python
# -*- coding: Utf-8 -*-

# # www.hellbondhackers.org
  #
  # Timed challenge 4 solution
  #
  # WORKS ONLY WITH EVEN NUMBER OF LETTERS
  #
  # Task: You will be given a string, it will be scrambled using the following rules:
  #       For every character in the string, take the position of the character. (Starting from 0)
  #       The initial character remains static.
  #       If the current position is even, then leave the character as it is.
  #       If its odd, add your current position and two.
  #       The character following the initial character, will be your last.
  #       Remember! Rules Matter!
  #       You have two seconds to answer this challenge.
  #
  #       PSEUDO Code:
  #
  #       FOR i = 0; i < str.length; i++
  #       	IF isEvenOrZero(i)
  #       		final += final[i]
  #       	ELSE
  #       		final += final[i+2]
  #       END FOR
  #       final += final[1]
  #       RETURN final
  #
  # author: mandyedi
  # contact: mandyedi@gmail.com
  #
  # Python version: 2.7.2
  # #

import urllib, urllib2
from time import time

# # 1st part: opening, downloading...
  # #
url    = "http://www.hellboundhackers.org/challenges/timed/timed4/index.php"
cookie = "PHPSESSID=e3013b10f987bd795dc9509bd36b8b93; fusion_user=40536.253b9f990cf2f9be52c660070a166b88"

t1 = time()

# Open and download the chal's page
request  = urllib2.Request(url)
request.add_header("COOKIE", cookie)
response = urllib2.urlopen(request)
page     = response.read()

# Search for the word
search = "Your word is: <strong>"
l      = len(search)
index1 = page.find(search)
index2 = page.find("</strong>", index1 + l)

scrambled = page[index1+l : index2]
print "Scrambled word:  ", scrambled

response.close()

# #
  # 2nd part: Unscramble the word
  # #
size        = len(scrambled)
unscrambled = ""

unscrambled += scrambled[0]
unscrambled += scrambled[size-1]

for i in range(1, size-1, 2):
	unscrambled += scrambled[i+1]
	unscrambled += scrambled[i]

print "Unscrambled wrod:", unscrambled

# # 3rd part: post the answer
  # #
  
url2 = "http://www.hellboundhackers.org/challenges/timed/timed4/index.php?check"
post = urllib.urlencode({"ans": unscrambled})

# Post
request2 = urllib2.Request(url2)
request2.add_header("COOKIE", cookie)
response2 = urllib2.urlopen(request2, post)

t2 = time()
print "Elapsed time: ", t2-t1

response2.close()