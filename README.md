# Parallel-to-Serial-Port-Adapter
Code in C and 8051 assembly language for testing parallel for serial port adapter

We often come across devices and instruments with only serial communication port (e.g. RS-232, USB etc.) or only parallel port. These devices can be interfaced with each other using a PC which has both these ports. However, interfacing would be much more convenient if a simple, inexpensive and standalone device is used for this purpose. This project describes design of a parallel to serial port adapter for interfacing SPP/EPP with RS-232 port using a 20 pin microcontroller AT89C2051 which permits bi-directional parallel to serial and serial to parallel data transfer with auto baud setting.

This project was implemented successfully as B-Tech final year project at EE Department, IIT Bombay from August 1998 to April 1999. This work was also published online in February 2010 in Dr Dobb's Journal which is not defunct. URL for this paper was http://www.ddj.com/cpp/223100564 
and
https://www.drdobbs.com/embedded-systems/designing-a-parallel-to-serial-port-adap/223100564

I am including code for this project as is that was used to test the adapter successfully during my B-Tech project. Testing was done for Serial to Serial mode using same PC and Parallel to Serial mode using same PC. Code for Serial to Printer parallel port can be implemented on similar lines. Code was tested using Windows 3.1 PC running DOS operating system and Borland C compiler with RS-232 and SPP ports. Hardware and software design is included in attached pdf file. 
