#include <iostream>
#include "principal.h"

using namespace PrimeraEntregaMComputacional;
using namespace System;

int main(){
	principal ^pPrin = gcnew principal();
	Application::Run(pPrin);

	return 0;
}