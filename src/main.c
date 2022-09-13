#include <stdio.h>
#include <stdarg.h>

#include "xil_printf.h"

void XNullHandler(void *NullParameter) {
	printf("NullHandler called: %p\n", NullParameter);
}

void Xil_Assert(const char8 *File, s32 Line) {
	printf("Assertion failed at %s:%d\n", File, Line);
}

void xil_printf(const char8 *ctrl1, ...) {
	va_list argptr;
 	va_start(argptr, ctrl1);
	vprintf("%s", argptr);
	va_end(argptr);
}

u32 Xil_AssertStatus;
