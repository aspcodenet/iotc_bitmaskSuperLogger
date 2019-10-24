#include <stdbool.h>


void WriteLogMessage(char* message,
	bool toFile, bool toConsole, bool includeDate,
	bool includeDayOfWeek,
	bool includeTime,
	bool uppercaseMessage);