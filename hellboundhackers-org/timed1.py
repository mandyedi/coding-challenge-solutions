#! /usr/bin/env python
# -*- coding: Utf-8 -*-

# # www.hellbondhackers.org
  #
  # Timed challenge 1 solution
  # Task: Decrypt the following random string: OTZhMT1iKS0hKGMhOTYsZg== 
  #            and answer like this: /challenges/timed/timed1/index.php?b64=decryptedString, you have 1 second to do this in!
  #
  # author: mandyedi
  # contact: mandyedi@gmail.com
  #
  # Python version: 2.7.2
  # #

import urllib, urllib2, base64
from time import time

url = "http://www.hellboundhackers.org/challenges/timed/timed1/index.php"
cookie = "PHPSESSID=a83dd3626c06f4bf58cd356bc748e2fc; fusion_user=40536.253b9f990cf2f9be52c660070a166b88"

# # First part: opening, downloading, decoding...
  # #
  
t1 = time()

# Open and download the chal's page
request = urllib2.Request(url)
request.add_header("COOKIE", cookie)
response = urllib2.urlopen(request)
page = response.read()

# Search for the encoded string
search = "random string:"
l = len(search)
index = page.find(search)

encodedString = page[index+l+1 : index+l+25]
print "Encoded string: ", encodedString

response.close()

# Decode the string
decodedString = base64.decode(encodedString)
print "Decoded string: ", decodedString

# # Second part: send back the answer
  # #

url2 = "http://www.hellboundhackers.org/challenges/timed/timed1/index.php?b64=" + decodedString

# Open the link
request2 = urllib2.Request(url2)
request2.add_header("COOKIE", cookie)
response2 = urllib2.urlopen(request2)

t2 = time()
print "Elapsed time: ", t2-t1

response2.close()