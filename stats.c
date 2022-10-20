#include "stats.h"
#include <stdlib.h>
#include <math.h>

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
	int loopCnt=0;
	if(setlength > 0)
	{
		s.min = numberset[0];
		for(loopCnt=0;loopCnt<setlength;loopCnt++)
		{
			if(s.min > numberset[loopCnt])
			{
				s.min = numberset[loopCnt];
			}
			if(s.max < numberset[loopCnt])
			{
				s.max = numberset[loopCnt];
			}
			s.average = s.average+numberset[loopCnt];
		}
		s.average = s.average/setlength;
	}
	else
	{
	    s.average = NAN;
		s.min = NAN;
		s.max = NAN;
	
	}
	return s;
}


void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
	if(maxThreshold < computedStats.max)
	{
		alerters[0];
		alerters[1];
	}
}


void emailAlerter(void)
{
	emailAlertCallCount++;
}	

void ledAlerter(void)
{
	ledAlertCallCount++;
}
