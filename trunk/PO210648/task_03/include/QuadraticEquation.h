#ifndef ENTROPY_CALCULATOR_H
#define ENTROPY_CALCULATOR_H

#ifdef _WIN32
#define DLLExport __declspec(dllexport)
#else
#define DLLExport
#endif

extern "C" DLLExport double calculateEntropy(const char* word); 
#endif // ENTROPY_CALCULATOR_H