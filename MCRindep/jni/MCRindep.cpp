#include<string>
#include <stdio.h>
using namespace std;
#include<iostream>
#include<sstream>
#include<fstream>
#include<jni.h>
#include<android_log.h>

#include "siftmatcher.h"
#include "globals.h"
#include "descriptors.h"

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#ifdef __cplusplus
extern "C"
{
#endif


siftmatcher* matcher;

string libFileNames[NUMTESTS] = { "lib00.txt", "lib01.txt", "lib02.txt", "lib03.txt", "lib04.txt", "lib05.txt", "lib06.txt", "lib07.txt", "lib08.txt", "lib09.txt", "lib10.txt", "lib11.txt" };
string libPicNames[NUMTESTS] = { "lib00.ppm", "lib01.ppm", "lib02.ppm", "lib03.ppm", "lib04.ppm", "lib05.ppm", "lib06.ppm", "lib07.ppm", "lib08.ppm", "lib09.ppm", "lib10.ppm", "lib11.ppm" };

string findFirstName( string Filename );
int matchIndexToBill( int index );

int
Java_mcr_indep_MCRindepActivity_initializeCurrencyReader( JNIEnv* env, jobject obj )
{	
	LOGD("Initializing the currency reader.");
	matcher = new siftmatcher();

	//Only build the forest once
	matcher->buildForest(DescriptorsArray, DESCRIPTOR_COUNTS);

	return 1;
}

int
Java_mcr_indep_MCRindepActivity_processCurrencyImage( JNIEnv* env, jobject obj, jbyteArray jpeg, jint length )
{
	///////////////////main/////////////////////////////

	LOGD("Converting test image into ppm format.");

	//Decode the the jpeg image(could actually be an image of any format)
	unsigned char* cjpeg;
	cjpeg = (unsigned char*)env->GetByteArrayElements(jpeg,NULL);
	Mat jpegMat = new Mat(1, length, CvType.CV_8U, cjpeg);
	Mat raw = Highgui.imdecode(jpegMat, 1);

	//Resize the image to 300 x 400
	Mat raw_resized = new Mat()

	//Encode the image into ppm
	vector<unsigned char> vppm;
	Highgui.imencode(".ppm", raw_resized, vppm);
	unsigned char* ppm = new unsigned char[sizeof( int ) * myVector.size()];
	memcpy( ppm, &cppm[0], sizeof( int ) * vppm.size() );

	//Process the converted ppm
	LOGD("Processing the converted test image.");
	matcher->processTestImage( cdata );

	//The data has been copied within the matcher... release the ByteArray
	env->ReleaseByteArrayElements(data,(jbyte*)cdata,0);

	LOGD("Finding the matches.");
	int matches[NUMTESTS];
	matcher->findMatches(matches);
	int maxIndex = 0;
	for( int i=1; i<NUMTESTS; i++)
	{
		if( matches[i] > matches[maxIndex] )
		{
			maxIndex = i;
		}
	}
	string img = libPicNames[maxIndex];

	//Remove the image we just processed
	//command = "DEL " + testImageDirectory + testImage;
	//system(command.c_str());

	delete ppm;
	delete matcher;
	int result = matchIndexToBill( maxIndex );
	if( matches[maxIndex] == 0 )
		return -1;
	else
		return result;
}

string findFirstName( string Filename )
{
	ifstream myfile;
	myfile.open (Filename.c_str());
	if(!myfile)
	{
		cerr<<"Could not open picture list file."<<endl;
		return "";
	}
	string first;
	myfile >> first;
	myfile.close();
	return first;
}

int matchIndexToBill( int index )
{
	switch( index )
	{
		case 0:
		case 1:
			return 1;
		case 2:
		case 3:
			return 5;
		case 4:
		case 5:
			return 10;
		case 6:
		case 7:
			return 20;
		case 8:
		case 9:
			return 50;
		case 10:
		case 11:
			return 100;
		default:
			return -1;
	}
	return -1;
}


#ifdef __cplusplus
}
#endif



/*
i_view32 "C:\Users\Alpha Dog\Documents\CurrencyReader\174B proj3\vlfeat-client\Pics\libraryPics\pp-mobile-currency-reader-read-only\*.jpg" /convert="C:\Users\Alpha Dog\Documents\CS 174C\indepCurrReader\indepCurrReader\TestImages\*.ppm"
*/
