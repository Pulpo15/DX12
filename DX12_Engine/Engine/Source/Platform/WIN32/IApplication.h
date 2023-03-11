#pragma once

#define ENTRYAPP(x) IApplication* EntryApplication() { return new x; }

class ENGINE_API IApplication {

	//Application

public:
	//*** Constructor ***//
	IApplication();

	//*** Deconstructor ***//
	virtual ~IApplication() {};

public:
	//*** Called to setup our pergame settings ***//
	virtual VOID SetupPerGameSettings() = 0;

	//*** Called to Initialize the Application ***//
	virtual VOID Initialize() = 0;

	//*** Game Loop - Called on a loop while the Application is running ***//
	virtual VOID Update() = 0;
};

IApplication* EntryApplication();