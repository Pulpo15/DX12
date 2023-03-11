#pragma once

#include <string>

class ENGINE_API Logger {

	//Gettres and Setters for singleton static class
private:
	static Logger* inst;
public:
	static Logger* Instanc() { return inst; }

	//Constructor
public:
	Logger();
	~Logger();

	//*** Print to Log File ***//
	static VOID PrintLog(const WCHAR* fmt, ...);
	static std::wstring LogDirectory();
	static std::wstring LogFile();

	//*** Print a line of '-' char's ***//
	static VOID PrintDebugSeperator();
	
	//*** Check to see if MTail is already running ***//
	static BOOL IsMTailRunning();

	//*** Start MTail Application ***//
	static VOID StartMTail();
};