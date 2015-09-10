Spiritual successor to the pp-mcreader google code project:
http://code.google.com/p/pp-mcreader/

The UI is similar but the architectural structure has changed completely along with the image processing code.

Moves all vision code onto the client(phone) and thus is server independent. Major challenges so far have been:

1. Porting the vision library(VLFEAT) to compile using android NDK.

2. Performance - due to intensive vision code and limited mobile processing resources.

3. Distinguishing between various types of bills using the SIFT algorithm since they have very similar features. Also the very nature of the algorithm results leads to a lot of false positives unless carefully interpreted.

Here is the high level flow of the app:
![http://mcreader-indep.googlecode.com/files/CurrencyReaderFlow.jpg](http://mcreader-indep.googlecode.com/files/CurrencyReaderFlow.jpg)
**The green arrows indicate the initialization code that is only run once at the start of the application.**

**The blue arrows indicate the execution loop thereafter.**


Libraries and tools I've used to create the app:

1. VLFeat - using heavily modified source code that compiles with the NDK:
http://www.vlfeat.org/

2. OpenCV for android:
http://opencv.willowgarage.com/wiki/Android

3. Android NDK/SDK:
http://developer.android.com/sdk/index.html