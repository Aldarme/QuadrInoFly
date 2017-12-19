// 
// 
// 

#include "Define.h"

/*
*	Array of cmd_t associating String and callback function
*/
const cmd_t cmdLst[4] =
{
	{ "1=",throttleCb },
	{ "3=",RollCb },
	{ "4=",PitchCb },
	{ "Ver?", VersionCb }
};

void serialAnalyser()
{	
	static String inputString = "";
	int inputChar = Serial.read();

	if (inputChar != '\n')
	{
		// convert the incoming byte to a char
		// and add it to the string:
		inputString += (char)inputChar;
	}
	// if you get a newline, print the string,
	// then the string's value:
	else
	{
		int i = 0;
		for (i = 0; i < (sizeof(cmdLst) / sizeof(cmdLst[0])); i++)
		{
			if (inputString.startsWith(cmdLst[i].cmd) == true)
			{
				String tmp = inputString.substring(inputString.indexOf('=') + 1);
				int val = tmp.toInt();
				cmdLst[i].cb(val);
				break;
			}
		}
		inputString = "";
	}	
}

