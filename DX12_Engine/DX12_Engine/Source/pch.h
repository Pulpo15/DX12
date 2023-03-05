#pragma once //Message to compiler to compile once

#include <Windows.h>

#include "../resource.h"

#define MAX_NAME_STRING 256
#define HInstance() GetModuleHandle(NULL) //Macro to get service instance

#include "Engine.h"