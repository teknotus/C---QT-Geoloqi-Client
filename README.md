C++/QT Geoloqi Client
=====================

This is very much beta code. 

It however is somewhat useful as it can download history data, and draw a crude map based on that data.

The only library currently required beyond what comes with Qt is QJSON.


Building
--------

So far building has only been tested on Ubuntu. I think installing the following packages may be sufficient for setting up a build environment on Ubuntu.

qt-sdk
libqjson-dev

Once those packages are installed the simplest way to build is. 
open the Qt-Creator IDE
goto file-> Open file or Project
select geoloqi.pro

This should load most of the files into the project tree view.

At this point to build, and run should be as simple as clicking the "Play" button near the lower left corner of the IDE.

To Use
------

The first time the program runs it will prompt for a usage key. If you already have a geoloqi account simply go to https://developers.geoloqi.com/getting-started and just below "Try it Quickly" that big string of caracters isn't an example of what a key looks like but actually your own personal key. Paste that key into the box, and hit save. This information is saved in an operating system specific way on Linux I found the config file in.

~/.config/ModernTwinPowers/geoeater.conf

If you don't already have an account go to https://geoloqi.com to get one. I recommend creating one with your twitter login so that you end up with a sensible username instead of a random one. Then add email, and password to your account info. The data that you can retrieve won't be very interesting until you have logged some so get the app for your phone, and meander about the city.

Roadmap
-------

Initially the effort was just to get something that worked, and that code has already almost been entirely replaced with a new design that seemed easier to work with. Once the new design has all of the features of the original code the old code should be cleared out. Class naming, and coding conventions haven't been decided on yet, and as they are the existing code base will have variables, and methods renamed to fit conventions.

From a design perspective one goal was to implement the most complicated features of the geoloqi rest api early in the development process in order to avoid technical debt later. So far that means implementing the history get method as it has many options. Next up is the batch method as in order to support it every request object will need to to be able to generate a json as well as a URL version of requests.

A little further down the roadmap is to split the geoloqi api related code into a library so that it can be used in other programs. 

Another goal is to create a Quantum GIS http://qgis.org/ plugin such that geodata can be easily moved between geoloqi, and other GIS tools. This application is written using the same framework that qgis uses so that shouldn't be too difficult. 

