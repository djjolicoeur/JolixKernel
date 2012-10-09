Most, if not all of thus is gleaned from James Molloys tutorial, and in no way 
am I taking credit for it. This is simply my implementation of his 
"build a unix kernel clone" tutorial.  

The tutorial can be found here http://www.jamesmolloy.co.uk/tutorial_html/


I found it easier to user qemu-system-i386 -kernel src/kernel to test my kernel,
rather than bochs.  Unless you have a burning desire to learn about bootloaders and write your kernel to a floppy every time, I would suggest doing the same


bochs is great, but when you frequently have to restart, I find this built-in 
boot loader a little easier to use
--Dan J


