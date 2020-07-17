#include <iostream>
#include <unistd.h>
#include <sys/types.h>
using namespace std;

int main()
{
    fork();
    cout << endl;
    cout << "Process ID=" << getpid() << endl;
    cout << "Parent Process ID=" << getppid() << endl;
    cout << "Read User Id=" << getuid() << endl;
    cout << "Real group Id=" << getgid() << endl;
    cout << "Effective User Id=" << geteuid() << endl;
    cout << "Effective group Id=" << getegid() << endl;
    //cout<<getpwuid()<<endl;
    return 0;
}