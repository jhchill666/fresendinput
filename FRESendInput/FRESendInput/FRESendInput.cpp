#include "FRESendInput.h"
#include <string>
#include <iostream>
#include <windows.h>

using namespace std;


extern "C"
{
	FREObject sendInputChar(uint32_t argc, FREObject argv[])
	{
		int32_t cval;
		FREObject retObj = 0;
		FREGetObjectAsInt32(argv[0], &cval);

		INPUT Input;
		ZeroMemory(&Input, sizeof(Input));
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
		Input.ki.wVk = cval;
		
		SendInput(1, &Input, sizeof(INPUT));
		return retObj;
	}

	FREObject sendInput(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[])
	{
		return sendInputChar( argc, argv );
	}

	void contextInitializer(void* extData, const uint8_t* ctxType, FREContext ctx, uint32_t* numFunctions, const FRENamedFunction** functions)
	{
		*numFunctions = 1;

		FRENamedFunction* func = (FRENamedFunction*) malloc(sizeof(FRENamedFunction) * (*numFunctions));

		func[0].name = (const uint8_t*) "sendInput";
		func[0].functionData = NULL;
		func[0].function = &sendInput;

		*functions = func;
	}

	void contextFinalizer(FREContext ctx)
	{
		return;
	}

	void initializer(void** extData, FREContextInitializer* ctxInitializer, FREContextFinalizer* ctxFinalizer)
	{
		*ctxInitializer = &contextInitializer;
		*ctxFinalizer = &contextFinalizer;
	}

	void finalizer(void* extData)
	{
		return;
	}
}