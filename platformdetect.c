#include <stdio.h>

int main(void) {

	// print platform name based on it's corresponding pre defined macro
	#ifdef  __unix__
	printf("Some UNIX OS");
	#elif __linux__
	printf("Linux");
	#elif __DOS__
	printf("DOS");
	#elif __TURBOC__
	printf("TURBO C");
	#elif __WIN32__
	printf("Windows");
	#elif __MINGW32__
	printf("MinGW for Windows");
	#elif __APPLE__ && __MACH__
	printf("macOS");
	#endif
	printf(" was detected.\n");

	return 0;
}
