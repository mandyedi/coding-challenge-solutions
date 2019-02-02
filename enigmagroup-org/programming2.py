#! /usr/bin/env python
# -*- coding: Utf-8 -*-

# # www.enigmagroup.org
  #
  # Programming mision 2
  # Task: You have 1 second to multiply this random number 87155465 by 4 and submit it
  #
  #
  # author:  mandyedi
  # contact: mandyedi@gmail.com
  #
  # Python version: 2.7.2
  # #

import urllib, urllib2, md5
from time import time

url    = "http://www.enigmagroup.org/missions/programming/2/"
cookie = "PHPSESSID=6a5c7830ae680167a2052017149971ee; enigmafiedV4=a%3A4%3A%7Bi%3A0%3Bs%3A5%3A%2233758%22%3Bi%3A1%3Bs%3A40%3A%221c39a0ab34ce6de0d4309cec18a4a6d7bb92dc40%22%3Bi%3A2%3Bi%3A1531769411%3Bi%3A3%3Bi%3A2%3B%7D"

# # 1st part: opening, downloading...
  # #
 
t1 = time()
# Open and download the chal's page
request  = urllib2.Request(url)
request.add_header("COOKIE", cookie)
response = urllib2.urlopen(request)
page     = response.read()

# Search for the numbers

def search(keyword, length, page):
	l      = len(keyword)
	index  = page.find(keyword)
	return page[index+l+1 : index+l+length+1]

number = search("random number", 8, page)
t      = search("\"E[time]\" value=", 10, page)
h      = search("\"hash\" value=", 32, page)
answer = str(int(number) * 4)

print "NUMBER:", number
print "TIME:  ", t
print "HASH:  ", h
print "ANSWER:", answer 

print page

response.close()

# # 2rd part: submit the answer
  # #

url2 = "http://www.enigmagroup.org/missions/programming/2/index.php"
post = urllib.urlencode({"answer":    answer,
                         "E[number]": number,
                         "E[time]":   t,
                         "hash":      h})

# Post
request2  = urllib2.Request(url2)
request2.add_header("COOKIE", cookie)
response2 = urllib2.urlopen(request2, post)

response2.close()

t2 = time()
print "Elapsed time:", t2-t1