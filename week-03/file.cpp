#include <iostream>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
using namespace std;

int main()
{
    int fid;
    fid=creat("check.txt", 0777);
    //create a file in currently location where the program store 
    //and store file descriptor in fid int

    int fd; //Used to Store the file descripter

    char buffer[80];

    char msg[50]="Hello world";
    fd=open("check.txt", O_RDWR); //open a already existing file on the same location 
    //where this program file
    //And store the file descriptor in int name fd
    cout<<"fd output: "<<fd<<endl; //Print the File descriptor 

    if (fd!=-1) //Loop will execute if file Descriptor is not -1 
    //-1 mean file is not open and currently File Descriptor stored value is 3 
    //because of O_RDWR mood)
    {
        cout<<"check file open with Read write Access"<<endl;
        write(fd, msg, sizeof(msg)); //write the msg char string in file which is open name fd

        lseek(fd, 0, SEEK_SET); //used to change location of read/write pointer of a file descriptor
        read(fd, buffer, sizeof(msg));//read data from file of size equals msg
        //store it in buffer
        cout<<buffer<<" was written to the file"<<endl;
        close(fd);//close the file
    }
    return 0;
}