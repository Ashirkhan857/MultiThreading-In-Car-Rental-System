# Overview
## What is MultiThreading?
================================
Multithreading is a model of program execution that allows for multiple threads to be created within a process, executing independently but concurrently sharing process resources. Depending on the hardware, threads can run fully parallel if they are distributed to their own CPU core.

# Implement MultiThreading In Car Rental System

Car Rental System is based on the concept to rent cars and generate rental invoices for a rental company. The main functionality in every module has a separate thread. When a function runs, a thread is created and when the function finishes its working, thread is terminated. You can get the thread pid in every module as well.

# How To Run This Project

-Step 1:   Download pthread.h, semaphore.h, sched.h from include directory.
-Step 2:   Download pthreadVC2.dll and pthreadVC.lib from x64 or x86 directory depends upon visual studio edition.
-Step 3:   Paste all .h files to visual studio include folder. On my System it is located at folder
           *C:\Program Files\Microsoft Visual  Studio\2022\Community\VC*.Paste pthread_VC2.dll file to visual studio bin folder. On my System it is located at the same directory stated earlier.
-Step 4:   Paste pthreadVC2.lib file to visual studio lib folder, located at same directory stated earlier.
-Step 5:   Now in visual studio right click on project (not solution) go to properties 
           a window will open then follow the flow *Linker>Input>Additional Dependencies* now click at the corner button and edit/write there pthreadVC2.lib and press OK (that’s it)pthread