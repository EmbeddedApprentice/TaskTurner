#include "stdio.h"
#include "../include/errors.h"
#include "../include/tasks.h"
#include "../include/taskrunner.h"

int doNow, doLater;

int taskrunner(Task * TaskList, unsigned int listLen)
{
	int iter;

	printf("Running Tasks, %d\n", listLen);
	for(iter = 0; iter < listLen; iter++)
	{
		if( 0 == *TaskList[iter].runNow)
		{
			printf("%s, %d\n", TaskList[iter].taskName, *TaskList[iter].runNow);
		}
	}
	return(iter);
}

Task tasks[] = {
	{"First_Task", &doNow},
	{"Second_Task", &doLater},
	{"Third_Task", &doNow},
};

#define NUM_TASKS sizeof(tasks)/sizeof(Task)

int runAllTasks(void)
{
	int Error;
	Error = 0;
	doNow = 0;
	doLater = 0;
	while(0 == Error)
	{
		Error = taskrunner(tasks, NUM_TASKS);
		if(doLater == 0)
			Error = 0;
		doLater = 1;
	}
	return(Error);
}

int main()
{
	int Error;
	printf("Hello world\n");
	/* Initialize task list */
	/* Run the task list using the given tasks */
	printf("Final task result = %d\n", runAllTasks());
	return(0);
}

