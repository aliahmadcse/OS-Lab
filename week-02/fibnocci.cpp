#include <iostream>
#include <unistd.h>
#include <sys/types.h>
using namespace std;

/**
 * size {int} the number of digits for fibnocci sequence 
 * returns {pointer} the first element of array containing fibnocci sequence
 */
int *fibnocci(int size)
{
    if (size == 0)
        return nullptr;
    int *fibnocci = new int[size];
    int first = 0;
    int second = 1;
    int next = 0;

    fibnocci[0] = first;
    fibnocci[1] = second;

    for (int i = 2; i < size; i++)
    {
        next = first + second;
        fibnocci[i] = next;
        first = second;
        second = next;
    }
    return fibnocci;
}

int main()
{
    // fork returns process id of type pid_t
    pid_t pid = fork();
    if (pid == 0)
    {
        cout << "I am child process\n";
        int *arr = fibnocci(10);
        for (int i = 0; i < 10; i++)
        {
            cout << arr[i] << endl;
        }
        delete[] arr;
    }
    else
    {
        cout << "I am parent process\n";
    }
    return 0;
}