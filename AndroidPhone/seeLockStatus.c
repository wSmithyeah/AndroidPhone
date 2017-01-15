#include <stdio.h>
#include <dlfcn.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char** argv)
{
char mpath[256];

printf("\n\n\nstarting...\n");
printf("executable at :%s\nname :%s\n",mpath,argv[0]);
//--
void *lib = dlopen("/system/lib/libSecurityManagerNative.so", RTLD_LAZY);
printf("lib = %p\n", lib);
if(lib == NULL)
  {
  printf("dlerror: %s\n",dlerror());
  return 1;
  }
//setSBFlag(int arg1, int arg2)
int (*getSBFlag)(void);
getSBFlag = dlsym(lib, "getSBFlag");
printf("getSBFlag = %p\n", getSBFlag);
printf("Result of getSBFlag %d\n#----\n",(*getSBFlag)());

int (*getCCModeFlag)(void);
getCCModeFlag = dlsym(lib, "getCCModeFlag");
printf("getCCModeFlag = %p\n", getCCModeFlag);
printf("Result of getCCModeFlag %d\n#----\n",(*getCCModeFlag)());

int (*setCCModeFlag)(int);
setCCModeFlag = dlsym(lib, "setCCModeFlag");
printf("setCCModeFlag = %p\n", setCCModeFlag);
printf("Result of setCCModeFlag %d\n#----\n",(*setCCModeFlag)(0));

return 0;
}
