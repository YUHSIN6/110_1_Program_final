#include "shared.h"
//製作新點
point make_point(int i, int j){
    point new_point;
    new_point.i = i;
	new_point.j = j;
    return new_point;
}

//debug
void debug(const char* format, ...) {
	va_list arg;
	va_start(arg, format);
	vlog(format, arg);
	va_end(arg);
}

static void vlog(const char* format, va_list arg) {
	static int clear_file = 1;
	// Write log to file for later debugging.
	FILE* pFile = fopen("debug.txt", clear_file ? "w" : "a");
	if (pFile) {
		vfprintf(pFile, format, arg);
		fclose(pFile);
	}
	clear_file = 0;
}
