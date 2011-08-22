#include<string>
using namespace std;
#include<iostream>
#include<sstream>
#include<fstream>
#include<jni.h>

#include "siftmatcher.h"
#include "globals.h"

#ifdef __cplusplus
extern "C"
{
#endif


string libFileNames[NUMTESTS] = { "lib00.txt", "lib01.txt", "lib02.txt", "lib03.txt", "lib04.txt", "lib05.txt", "lib06.txt", "lib07.txt", "lib08.txt", "lib09.txt", "lib10.txt", "lib11.txt" };
string libPicNames[NUMTESTS] = { "lib00.ppm", "lib01.ppm", "lib02.ppm", "lib03.ppm", "lib04.ppm", "lib05.ppm", "lib06.ppm", "lib07.ppm", "lib08.ppm", "lib09.ppm", "lib10.ppm", "lib11.ppm" };

const string testImageDirectory = "TestImages\\";

string findFirstName( string Filename );
int matchIndexToBill( int index );


jstring
Java_mcr_indep_MCRindepActivity_stringFromJNI( JNIEnv* env, jobject obj )
{
    return env->NewStringUTF("Hello from JNI !");
}

int
Java_mcr_indep_MCRindepActivity_processCurrencyImage( JNIEnv* env, jobject obj )
{	
	return 20;

	///////////////////main/////////////////////////////
	/*siftmatcher* matcher = new siftmatcher();

	//Always generate the descriptor files - safe but very inefficient
	//matcher->writeDescriptors(libPicNames);	

	//Only build the forest once
	matcher->buildForest(libFileNames);

	string testImage = "test.ppm";

	matcher->processTestImage( testImageDirectory + testImage );

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
	cout<< "Found " << matches[maxIndex] << " between testImage: "
		<< testImage << " and libImage: " << img << endl;
				
		//Remove the image we just processed
		//command = "DEL " + testImageDirectory + testImage;
		//system(command.c_str());
	//}

	delete matcher;
	int result = matchIndexToBill( maxIndex );
	return result;*/
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
