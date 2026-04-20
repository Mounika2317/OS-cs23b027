/* add.c
 *	Simple program to test whether the systemcall interface works.
 *
 *	Just do a add syscall that adds two values and returns the result.
 *
 */

#include "syscall.h"

int main() {
    int x,y,wRes,pid,result;
    int i,j;int main()
{
    int x, y, result, wRes, pid;
    char* buf = "Hello";  // unused in the provided snippet

    Pipe(&x, &y);                    // Create a pipe; x = read end, y = write end (from parent's view)
    result = Add(-11, 1);            // Call a custom syscall? Computes -11 + 1 = -10
    wRes = pipeWrite(x, (char*)&result, 4);  // Write the 4-byte integer result to the *read* end? (see note below)
    pid = ExecP("../test/abs", y);   // Exec a child program "abs", passing the write end of the pipe as argument
    if(pid < 0){
        PrintString("Exec failed\n");
    }
    Join(pid);                       // Wait for the child to finish
    // return 0;
}
    //result = Add(42, 23);
    //PrintNum(result);
    for(i=0;i<10;i++){
	    for(j=0;j<10000;j++){
	    }
	    PrintString("In child @1\n");
    }
    //Halt();
    /* not reached */
}
