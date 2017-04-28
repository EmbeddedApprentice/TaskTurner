#ifndef TASK_H
#define TASK_H

typedef int (*task_init)(int);
typedef int (*task_func)(int);

typedef struct {
	char taskName[20];
	// task_init init;
	// task_func func;
	int *	runNow;
} Task;

#endif	//TASK_H
