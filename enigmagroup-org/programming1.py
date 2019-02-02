#! /usr/bin/env python
# -*- coding: Utf-8 -*-

# # www.enigmagroup.org
  #
  # Programming mision 1
  # Task: Your objective is to send a POST header to this script. The POST content must contain your IP Address and your USERNAME. The variable names are ip & username! 
  #  		ONE MORE THING... MAKE SURE you send a cookie with the value mission=yes 
  #
  # author:  mandyedi
  # contact: mandyedi@gmail.com
  #
  # Python version: 2.7.2
  # #

import urllib, urllib2, md5
from time import time

url    = "http://www.enigmagroup.org/missions/programming/1/"
cookie = "PHPSESSID=6a5c7830ae680167a2052017149971ee; enigmafiedV4=a%3A4%3A%7Bi%3A0%3Bs%3A5%3A%2233758%22%3Bi%3A1%3Bs%3A40%3A%221c39a0ab34ce6de0d4309cec18a4a6d7bb92dc40%22%3Bi%3A2%3Bi%3A1531769411%3Bi%3A3%3Bi%3A2%3B%7D; mission=yes"
post   = urllib.urlencode({"ip": "193.225.63.8", "username": "mandyedi"})

t1 = time()

request  = urllib2.Request(url)
request.add_header("COOKIE", cookie)
response = urllib2.urlopen(request, post)
page     = response.read()

response.close()

print page

t2 = time()
print "Elapsed time: ", t2-t1