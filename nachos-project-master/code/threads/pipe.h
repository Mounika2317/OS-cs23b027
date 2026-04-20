#ifndef PIPE_H
#define PIPE_H

#define BUFFER_SIZE 2048 	// Defining the size of the buffer to be 2048 bytes
#define MAX_NUM_DESCRIPTORS 64	// Defining the number of descriptors to be 64 (i.e., the descriptors can range from 0 to 63

class Descriptor{
	public:
		char* buf;
		char* desType;		// A string storing the type of the descriptor(pipe descriptor of file descriptor)
		char* permission;	// A string (mostly a single letter indicating the permission of the owner of this specific descriptor (Read or Write)
		int currSeekPos;	// An int value for storing the current position of the seek
		Descriptor(char* desType, char* permission, char* bufPtr);	// Defining the constructor
		~Descriptor();		// Declaring the destructor
};

class PipeDescriptors{
	public:
		PipeDescriptors();
		// Defining the number of array of descriptors
		Descriptor* descriptors[MAX_NUM_DESCRIPTORS];

		// create function that accepts two parameters passed by reference to populate with the numbers (indices) of the descriptors. Also type of the descriptor required is also passed
		int createDes(int* x, int* y, char* desType);

		// readDes function that accepts the descriptor number from the thread and the number of bytes to be read. Then perform the act of reading the content from the descriptor and returning it
		int readDes(int des, char* buf, int numBytes);

		// writeDes function that accepts the descriptor number from the thread and the number of bytes to be written to the buffer. Here we check for the permission assigned for the descriptor before performing the action of writing to the buffer.
		int writeDes(int des, char* buf, int numBytes);

		// A test method
		void test_method();
};

#endif
