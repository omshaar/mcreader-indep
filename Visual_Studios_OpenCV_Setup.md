This documents getting OpenCV to work with my existing desktop currency reader application in Visual Studios 2010.




# Details #

I wanted to use the same version of OpenCV as the OpenCV for android so I went with OpenCV 3.0. I ran into some trouble since the installation tutorial on the OpenCV website is for 2.2 and 2.1:
http://opencv.willowgarage.com/wiki/VisualC%2B%2B

I then went on to follow another tutorial that I found that relied heavily on CMake which I found a lot easier to follow:
http://redkiing.wordpress.com/2010/10/03/opencv-and-visual-studio-2010-with-cmake/

In the second tutorial, I also had to copy two of the OpenCV dll files into my executable directory in order for them to link at runtime. After that the basic Hello World code working.

The next step would've been using CMake to configure my existing project to be compatible with OpenCV. Instead I just copied over the project properties for the include files(Project -> Properties -> C/C++ -> General -> Additional Include directories). The project compiled after this step with OpenCV code/include files. I then had to do the following in order to get it to run:
1. Copy over lib files in Project -> Properties -> Linker -> Input -> Additional Dependencies
2. Project -> Properties -> VC++ Directories -> Library Directories
Add the OpenCV lib Debug directory
3. Copy over dll files

