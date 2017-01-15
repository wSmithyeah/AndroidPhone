#include "config.h"
#include <stdio.h>
#include <dlfcn.h>
#include <asm/unistd.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
if(argc < 2)
  {
  printf("Usage: %s <0/1> (0: unlock, 1: lock)\n", argv[0]);
  return 1;
  }
void *lib = dlopen("/system/lib/libSecurityManagerNative.so", RTLD_LAZY);
printf("lib = %p\n", lib);
if(lib == NULL)
  {
  printf("dlerror: %s\n",dlerror());
  return 1;
  }
//setSBFlag(int arg1, int arg2)
int (*setSBFlag)(int arg1, int arg2);
setSBFlag = dlsym(lib, "setSBFlag");
printf("setSBFlag = %p\n", setSBFlag);
if(setSBFlag)
  {
  printf("Unlocking the download mode!\n");
  (*setSBFlag)(0, 0);
  }
else
  {
  printf("download mode is already unlocked!\n");
  }
return 0;
}
