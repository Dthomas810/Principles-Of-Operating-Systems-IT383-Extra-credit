#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

main()
{

  	int pid;


	pid = fork();

	if (pid ==0)
	{
		// child
		// (1)
		//while (1);
		// (2)
		 //execlp("/bin/sleep","sleep","60",NULL);
		 execlp("sleep","sleep","60",NULL);
		printf(" YOU will never see my message !!!!");
                /*  this line will not be reached!!! */
	
	}
	// parent
	//sleep(15);
}
