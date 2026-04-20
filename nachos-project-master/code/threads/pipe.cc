#include "pipe.h"
#include<iostream>
#include<cstring>
#include "debug.h"
using namespace std;

//Descriptor* descriptors[MAX_NUM_DESCRIPTORS] = {NULL};	// Intialising with null pointers to avoid any accidental garbage pointers.


Descriptor::Descriptor(char* desType, char* permission, char* bufPtr){
	buf = bufPtr;	// Allocating a char array initially to a NULL pointer
	
	this->desType = desType;
	this->permission = permission;
	this->currSeekPos = 0;
}

Descriptor::~Descriptor(){
	delete [] buf;
}

void PipeDescriptors::test_method(){
	std::cout<<"Imports via header files are working!!\n";
}

PipeDescriptors::PipeDescriptors(){
	Descriptor* descriptors[MAX_NUM_DESCRIPTORS] = {nullptr};	// Intialising with null pointers to avoid any accidental garbage pointers.
}

int PipeDescriptors::createDes(int* x, int* y, char* desType){
	char* buf = new char[BUFFER_SIZE];
	int parentPd = -1, childPd = -1; 	// Variables holding the pipe descriptors
	
	// Count the number of free Descriptors available
	int freeDes_cnt = 0;
	for(int i = 0; i < MAX_NUM_DESCRIPTORS; i++){
		if(descriptors[i] == nullptr){
			freeDes_cnt++;
		}
	}

	// If they are less than 2 then return the error code -1 indicating the failure to assign the descriptors
	if(freeDes_cnt < 2){
		return -1;
	}
	// Create two new descriptors - one for parent process and one for child process but pass the same buffer pointer to both the descriptor objects
	Descriptor* parentDes = new Descriptor(desType, "w", buf);
	Descriptor* childDes = new Descriptor(desType, "r", buf);

	// Scan through the entire array of descriptors and assign the descriptor that is not yet assigned to any of the processes (i.e., it has NULL)
	for(int i = 0; i < MAX_NUM_DESCRIPTORS; i++){
		if(descriptors[i] == nullptr){
			parentPd = i;
			break;
		}
	}
	descriptors[parentPd] = parentDes;
	
	// Scan through the entire array of descriptors and find that descriptor number that is not assigned to any of the processes (i.e., it has NULL)
	for(int i = 0; i < MAX_NUM_DESCRIPTORS; i++){
		if(descriptors[i] == nullptr){
			childPd = i;
			break;
		}
	}
	descriptors[childPd] = childDes;

	// Assign the parent and child pipe descriptors - the return values of the function using the technique of pass by address
	*x = parentPd;
	*y = childPd;
	return 1;	// Return 1 as the success code indicating the success of the creation of two pipe descriptors one for parent and one for child
}


int PipeDescriptors::readDes(int des, char* buf, int numBytes){
	if(des < 0 || des >= MAX_NUM_DESCRIPTORS){
		cout<<"No pipe descriptor exists for the given index:"<<des<<endl;
	}
	int numRead = 0;
	Descriptor* pDes = descriptors[des];
	char* pipeBuf = pDes->buf;
	for(int i = 0; i < numBytes; i++){
		/*if(buf[i] == '\0'){
			break;
		}*/
		buf[i] =  pipeBuf[i];
		numRead++;
	}
	if(numRead != numBytes){
		cout<<"Asked for :"<<numBytes<<" but read:"<<numRead<<endl;
	}
        ASSERT(numRead == numBytes);
	return numRead;
}

int PipeDescriptors::writeDes(int des, char* buf, int numBytes){
	if(des < 0 || des >= MAX_NUM_DESCRIPTORS){
		cout<<"No pipe descriptor exists for the given index:"<<des<<endl;
	}
	Descriptor* pDes = descriptors[des];
	int permCheck = strcmp(pDes->permission, "w");
	// Throw an error when the permission for the current pipe descriptor we are accessing.
	ASSERT(permCheck == 0);
	int numWrite = 0;
	//cout<<"Attempting to write:"<<buf<<endl;
	for(int i = 0; i < numBytes; i++){
		/*if(buf[i] == '\0'){
			break;
		}*/
		pDes->buf[i+pDes->currSeekPos] = buf[i];
		numWrite++;
	}
	pDes->currSeekPos += numWrite;
	if(numWrite != numBytes){
		cout<<"Requested for writing :"<<numBytes<<" but wrote :"<<numWrite<<endl;
	}
	ASSERT(numWrite == numBytes);
	//cout<<"Successfully written :"<<buf<<endl;
	return numWrite;
}
