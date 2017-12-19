// serialRcver.h

#ifndef _SERIALRCVER_h
#define _SERIALRCVER_h

/*
*	cmd_t struct
*/
struct cmd_t
{
	String cmd;
	void(*cb)(int);
};

void serialAnalyser();

#endif //_SERIALRCVER_h

