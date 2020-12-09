#pragma once
#include "Utilities.h"
#include <iostream>
#include <memory>
#include <string>
#include <crtdbg.h>

/**
External entrypoint for use by applications built with the IndiaEngine.
*/
extern India::IndiaEngine& India::Create();

/**
Starting point of the application.
*/
#ifndef _DEBUG
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

int Start() {
	try {
		India::Create();
	}
	catch (const std::exception& exception) {
		India::Utilities::HandleException(exception);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	return Start();	
}




