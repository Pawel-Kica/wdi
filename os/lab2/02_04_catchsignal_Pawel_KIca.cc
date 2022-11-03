#include <iostream>
#include <csignal>
#include <string.h>

using namespace std;

void signalHandler( int signalId ) {
   cout << "Signal id: "<<signalId<<endl;
   cout << "Signal name: "<<strsignal(signalId)<<endl;
}

int main () {
    signal(SIGHUP,signalHandler);
    signal(SIGINT,signalHandler);
    signal(SIGQUIT,signalHandler);
    signal(SIGILL,signalHandler);
    signal(SIGTRAP,signalHandler);
    signal(SIGIOT,signalHandler);
    signal(SIGBUS,signalHandler);
    signal(SIGFPE,signalHandler);
    signal(SIGKILL,signalHandler);
    signal(SIGUSR1,signalHandler);
    signal(SIGSEGV,signalHandler);
    signal(SIGUSR2,signalHandler);
    signal(SIGPIPE,signalHandler);
    signal(SIGALRM,signalHandler);
    signal(SIGTERM,signalHandler);
    signal(SIGSTKFLT,signalHandler);
    signal(SIGCHLD,signalHandler);
    signal(SIGCONT,signalHandler);
    signal(SIGSTOP,signalHandler);
    signal(SIGTSTP,signalHandler);
    signal(SIGTTIN,signalHandler);
    signal(SIGTTOU,signalHandler);
    signal(SIGURG,signalHandler);
    signal(SIGXCPU,signalHandler);
    signal(SIGXFSZ,signalHandler);
    signal(SIGVTALRM,signalHandler);
    signal(SIGPROF,signalHandler);
    signal(SIGWINCH,signalHandler);
    signal(SIGIO,signalHandler);
    signal(SIGPWR,signalHandler);

    cout<<"Current process pid: "<< getpid() << endl;

    while(1) {
        cout << "Loop" << endl;
        sleep(1);
    }

    return 0;
}
