#include "Global.h"

int compareName(Student a, Student b)
{
	if (a.getName() > b.getName())
		return 1;
	if (a.getName() == b.getName())
		return 0;
	return -1;
}

int compareMathGrade(Student a, Student b)
{
	if (a.getMathGrade() > b.getMathGrade())
		return 1;
	if (a.getMathGrade() == b.getMathGrade())
		return 0;
	return -1;
}

int compareEngGrade(Student a, Student b)
{
	if (a.getEngGrade() > b.getEngGrade())
		return 1;
	if (a.getEngGrade() == b.getEngGrade())
		return 0;
	return -1;
}

int compareHistGrade(Student a, Student b)
{
	if (a.getHistGrade() > b.getHistGrade())
		return 1;
	if (a.getHistGrade() == b.getHistGrade())
		return 0;
	return -1;
}

int compareAvgGrade(Student a, Student b)
{
	if (a.getAvgG() > b.getAvgG())
		return 1;
	if (a.getAvgG() == b.getAvgG())
		return 0;
	return -1;
}