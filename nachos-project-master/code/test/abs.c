/* abs.c
 *      Simple program to test whether the systemcall interface works.
 *
 *      Just do a add syscall that adds two values and returns the result.
 *
 */

#include "syscall.h"

int main() {
    int result;
    int x=-200;
    result = Abs(x);
    PrintNum(result);
    Halt();
    /* not reached */
#include "syscall.h"

int main() {
    int pd;
    int rRes;
    int readVal;
    int result;
    char buf[10];   // allocate buffer properly

    pd = GetPD();

    PrintString("Found the pd from the thread program to be: ");
    PrintNum(pd);
    PrintString("\n");

    // Read 4 bytes (integer) from pipe
    rRes = pipeRead(pd, buf, 4);

    if (rRes <= 0) {
        PrintString("Error reading from pipe\n");
        Halt();
    }

    PrintString("Printing Read value: ");
    
    // Convert buffer to integer
    readVal = ReadInt(buf);
    PrintNum(readVal);
    PrintString("\n");

    // Compute absolute value
    result = Abs(readVal);

    PrintString("Final Result after reading from Abs: ");
    PrintNum(result);
    PrintString("\n");

    Halt();
}}
