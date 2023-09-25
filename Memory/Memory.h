#pragma once
#include <string>
#include <windows.h>
#include <TlHelp32.h>

class Memory
{

private:
	HANDLE handle;
	DWORD procId;


public:
	Memory(const std::wstring procName);
	~Memory();
	
	void read() {

	}

	void write(LPVOID &adress, LPCVOID buffer) {
		WriteProcessMemory(handle,&adress,&buffer,sizeof(buffer),NULL);
	}

	


};

