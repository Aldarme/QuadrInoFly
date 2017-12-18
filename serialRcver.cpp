// 
// 
// 

#include "Define.h"

/*
*	Array of cmd_t associating String and callback function
*/
const cmd_t cmdLst[4] =
{
	{ "0_",throttleCb },
	{ "3_",RollCb },
	{ "4_",PitchCb },
	{ "Ver?", VersionCb }
};

int serialAnalyser()
{
	if (Serial.available() < 0)
	{
		return 0;
	}

	static String inputString = "";
	const int inputChar = Serial.read();

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
				String tmp = inputString.substring(inputString.indexOf('_') + 1);
				const int val = tmp.toInt();
				cmdLst[i].cb(val);
				break;
			}
		}
		inputString = "";
	}
}

