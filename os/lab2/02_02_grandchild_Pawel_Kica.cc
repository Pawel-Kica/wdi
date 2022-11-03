#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
	int pid;
	pid = fork();
    cout<<"Start pid: "<<pid<<endl;

	if (pid == 0)
	{
		cout<<"Parent process pid: "<< getppid() << endl;
        cout<<"Current process pid: "<< getpid() << endl;
        getchar();
	}

    cout<<"End pid: "<<pid<<endl;
	return 0;
}