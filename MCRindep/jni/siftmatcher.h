#ifndef SIFT_MATCHER_H
#define SIFT_MATCHER_H

#include "globals.h"

#include "Image.h"
#include<string>

extern "C" {
#include "generic.h"
#include "sift.h"
#include "kdtree.h"
}

class siftmatcher{
public:
	siftmatcher();
	~siftmatcher();

	void processTestImage( string imageName );

	//Build the kdforest and add the data into the forest
	void buildForest(string* libraryNames);

	//Finds all the descriptor matches between the test image and each of the library images
	//matches is the output
	void findMatches(int* matches);

	/////INTERNAL USE ONLY/////
	void processLibraryImages(string* libraryNames);
	void normalize( float* descr, int numDescr );
	void convertToGrayscale(Image img, vl_sift_pix *gray );
	int sift( float* d, float* pixels, Image I );
	void writeDescriptors( string* testNames);
	void outputDescriptors( float* Descript, string Filename, int size );
	int readAllDescriptors( float* Descript, string Filename );
	vl_sift_pix* initializeImage( string name, Image& image );

private:
	string inputFileNames[NUMTESTS];
	float* testDescriptors;
	float* libraryDescriptors;
	int matchDelimeter[NUMTESTS+1];
	int numLibraryDescriptors;
	int numTestDescriptors;
	_VlKDForest* forest;
};







#endif