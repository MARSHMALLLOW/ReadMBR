/*
	This code should work.
	Compile it with Dev-Cpp, or VisualStudio (any version).
	
	This code is free, you can modify it.
	Just use it for EDUCATIONAL PURPOSES ONLY!
	Under GNU GPL 3.0 license.
	
	This code isn't dangerous. So you can run it in your physical machine.
	It just reads the MBR (Master Boot Record) and writes it to a file called "Binary.bin" in the EXE directory.
	
	There we go...
*/

#include <windows.h>

int main() {
	FreeConsole();
	
	DWORD dwTmp1;
	HANDLE hDrive = CreateFile("\\\\.\\PhysicalDrive0" /*Don't modify it.*/, GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0, NULL);
	//Now we have a handle to our MBR.
	//Let's get the data.
	//make a variable.
	char mbrData[512];
	//MBR is 512 in size.
	SetFilePointer(hDrive, NULL, 0, FILE_BEGIN); //Set the file pointer to the begin of the MBR.
	ReadFile(hDrive, mbrData, 512, &dwTmp1, NULL); //Read all bytes from the MBR.
	CloseHandle(hDrive); //Don't forget to close it!
	HANDLE hFile = CreateFile("Binary.bin", GENERIC_WRITE, 0, 0, CREATE_NEW, 0, NULL);
	DWORD dwTmp2;
	//We have a handle to our new file.
	WriteFile(hFile /*Not hDrive xD*/, mbrData, 512, &dwTmp2, NULL);
	CloseHandle(hFile); //Now close it.
	return 0; //Return 0 lol :P
}
