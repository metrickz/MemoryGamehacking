#include "Memory.h"


Memory::Memory(const std::wstring procName) {


	const HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	PROCESSENTRY32 pe32;

	WCHAR name = pe32.szExeFile[0];

	while (Process32Next(snapshot, &pe32)) {
		if (wcscmp(pe32.szExeFile,procName.c_str()) == 0) {
			procId = pe32.th32ProcessID;
			handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procId);




		}
		

	}

}


Memory::~Memory() {
	if (handle)
		CloseHandle(handle);
}