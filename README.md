# String EQ Calculator

*OVERALL GOAL*
The String Equality Calculator has a primary interface in python. It accepts a simple string as input. That string must be some kind of mathematical equation like ((3*2)^4)/(7+(15-8)). 


*START UP - IMPORTANT*
Unfortunately, I could not get my Vagrantfile to work properly. Originally, I was having trouble getting it booted up with 'vagrant up'. After some testing and googling, I found that I was having issues running a Virtual Machine inside another VM. I moved to my host environment and Vagrant started to work. I then imported the cookbooks template that was given to us. But I ran into a new problem where Chef was unable to start up. This is where I got stuck. I think it has something to do with the acceptance of the chef license and 404 errors when webpages are loaded. I believe I could have figured it out, but due to other exams and projects, I lost track of time.

- TO RUN: 
1. This project will run without issue in the CSIL labs. Steps to easily do so are below (copy,paste and use your own SFU ID):
    - Upload to CSIL using terminal, proj.zip file is provided, then SSH into CSIL:
        - scp -P24 proj.zip yourSfuId@csil-cpu2.cs.surrey.sfu.ca:/home/yourSfuId/
        - ssh -p24 yourSfuId@csil-cpu2.cs.surrey.sfu.ca
    - Unzip the file and run:
        - unzip proj.zip
        - make (Makefile includes the run command: 'python3 interface.py')
        - to run again without compilation type: 'python3 interface.py'

2. To run without CSIL make sure the following libraries are installed:
    - Dependencies:
        - g++: sudo apt-get install g++
        - gcc: sudo apt install build-essential
        - swig: sudo apt-get install -y swig
        - ghc: sudo apt-get install haskell-platform
        - python3: sudo apt-get install python3.6
    - Run:
        - make
        - to run again without compilation type: 'python3 interface.py'

*COMMUNICATION*
- Swig is used for communication between C++ and Python. Using this interface allows for Python to import and call the C++ library that I have created.
- Haskell is a bit more complicated. There isn't much of straight forward communication between Haskell and Python. I used Haskell's Foreign Function Interface method. This requires the creation of stub functions that interface with a C program. In the C program, more stub functions are created. Lastly, these methods are called in Python.


*FEATURES AND LANGUAGES*
That string is passed to the C++ program which uses the Shunting-Yard Algorithm. This algorithm takes a string and places the above characters on a stack and in a deque. Once this string has been parsed, it will calculate the above string. Then the result is returned. What makes this process more complicated is having to create a 'Token' class which stores data about a character's type, precedence ('^' goes before '*' and so on, like BEDMAS/BEMDAS), and direction of the rest of the equation.

Once the result is found, some recursive Haskell functions will be applied to the calculated value. The value is passed to a simple C interface, which then passes the value to Haskell by utilizing Haskell's 'foreign export' functionality.
- In order for all of the haskell functions to work, the result must be positive. This is due to their recursive nature. For example one of the Haskell functions used is the fibonacci method.

*CITATION*
- I learned about the Shunting-Yard Algorithm on Wikipedia. This page can be found at: https://en.wikipedia.org/wiki/Shunting-yard_algorithm

