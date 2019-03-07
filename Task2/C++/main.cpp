#include <iostream>
#include <sysinfoapi.h>

using namespace std;

extern "C" __declspec(dllimport)
BOOL __stdcall GetPhysicallyInstalledSystemMemory(PULONGLONG);

void showMemory(){
	ULONGLONG memory;
	GetPhysicallyInstalledSystemMemory(&memory);
	cout<<"RAM: "<<memory/1024/1024;
	}

int main(int argc, char** argv) {
	showMemory();
	return 0;
}
