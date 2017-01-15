#include "config.h"
#include <stdio.h>
#include <dlfcn.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char** argv)
{
char mpath[256];
getcwd(mpath,255);

printf("\n\n\nstarting...\n");
printf("executable at :%s\nname :%s\n----\n",mpath,argv[0]);
//--
void* lib = dlopen("/system/lib/libSecurityManagerNative.so", RTLD_LAZY);
if(lib == NULL)
  {
  printf("Unable to load library for unlocking: dlerror: %s\n",dlerror());
  return 1;
  }
//--
if (strcmp(argv[0],"Unlock.c.elf")==0)
  {
  printf("difference %d - So no settings\n----\n",strcmp(argv[0],"Unlock.c.elf"));
  ReadInfo(lib);
  DoCopy();
  }
else
  {
  ReadInfo(lib);
  //--
  Java_com_sec_android_service_sm_job_SecurityNativeJob_setCCModeFlag
  //--
  int (*setCCModeFlag)(int);
  setCCModeFlag = dlsym(lib, "setCCModeFlag");
  if (setCCModeFlag!=0)
    {
    printf("setCCModeFlag = %p\n", setCCModeFlag);
    printf("Result of setCCModeFlag %d\n#----\n",(*setCCModeFlag)(0));
    }

  int (*setSBFlag)(int arg1, int arg2);
  setSBFlag = dlsym(lib, "setSBFlag");
  if (setSBFlag!=0)
    {
    printf("setSBFlag = %p\n", setSBFlag);
    printf("Result of setSBFlag %d\n#----\n",(*setSBFlag)(0, 0));
    }

  int (*Java_com_sec_android_service_sm_job_SecurityNativeJob_setSBFlagOff)(void);
  Java_com_sec_android_service_sm_job_SecurityNativeJob_setSBFlagOff = dlsym(lib, "Java_com_sec_android_service_sm_job_SecurityNativeJob_setSBFlagOff");
  if (Java_com_sec_android_service_sm_job_SecurityNativeJob_setSBFlagOff!=0)
    {
    printf("Java_com_sec_android_service_sm_job_SecurityNativeJob_setSBFlagOff = %p\n", Java_com_sec_android_service_sm_job_SecurityNativeJob_setSBFlagOff);
    printf("Result of Java_com_sec_android_service_sm_job_SecurityNativeJob_setSBFlagOff %d\n#----\n",(*Java_com_sec_android_service_sm_job_SecurityNativeJob_setSBFlagOff)());
    }

  int (*Java_com_sec_android_service_sm_job_SecurityNativeJob_setCCModeFlag)(int arg1, int arg2);
  Java_com_sec_android_service_sm_job_SecurityNativeJob_setCCModeFlag = dlsym(lib, "Java_com_sec_android_service_sm_job_SecurityNativeJob_setCCModeFlag");
  if (Java_com_sec_android_service_sm_job_SecurityNativeJob_setCCModeFlag!=0)
    {
    printf("Java_com_sec_android_service_sm_job_SecurityNativeJob_setCCModeFlag = %p\n", Java_com_sec_android_service_sm_job_SecurityNativeJob_setCCModeFlag);
    printf("Result of Java_com_sec_android_service_sm_job_SecurityNativeJob_setCCModeFlag %d\n#----\n",(*Java_com_sec_android_service_sm_job_SecurityNativeJob_setCCModeFlag)(0, 0));
    }
  }
return 0;
}
//--
int DoCopy(void)
{
FILE *from, *to;
char ch;

  /* open source file */
  if((from = fopen("/data/data/name.antonsmirnov.android.cppdroid/build/Unlock.c.elf", "rb"))==NULL)
    {
    printf("Cannot open source file.\n");
    return(1);
    }

  /* open destination file */
  if((to = fopen("/sdcard/Download/unlock", "wb"))==NULL)
    {
    printf("Cannot open destination file.\n");
    return(1);
    }

  /* copy the file */
  while(!feof(from))
    {
    ch = fgetc(from);
    if(ferror(from))
      {
      printf("Error reading source file.\n");
      return(1);
      }
    if(!feof(from)) fputc(ch, to);
    if(ferror(to))
      {
      printf("Error writing destination file.\n");
      return(1);
      }
    }

  if(fclose(from)==EOF)
    {
    printf("Error closing source file.\n");
    return(1);
    }

  if(fclose(to)==EOF)
    {
    printf("Error closing destination file.\n");
    return(1);
    }
}
//--
void ReadInfo(void* lib)
{

int (*getCCModeStatusForKeystore)(void);
getCCModeStatusForKeystore = dlsym(lib, "getCCModeStatusForKeystore");
if (getCCModeStatusForKeystore!=0)
  {
  printf("getCCModeStatusForKeystore = %p\n", getCCModeStatusForKeystore);
  printf("Result of getCCModeStatusForKeystore %d\n#----\n",(*getCCModeStatusForKeystore)());
  }

int (*getCCModeStatusForODE)(void);
getCCModeStatusForODE = dlsym(lib, "getCCModeStatusForODE");
if (getCCModeStatusForODE!=0)
  {
  printf("getCCModeStatusForODE = %p\n", getCCModeStatusForODE);
  printf("Result of getCCModeStatusForODE %d\n#----\n",(*getCCModeStatusForODE)());
  }

int (*getCCModeFlag)(void);
getCCModeFlag = dlsym(lib, "getCCModeFlag");
if (getCCModeFlag!=0)
  {
  printf("getCCModeFlag = %p\n", getCCModeFlag);
  printf("Result of getCCModeFlag %d\n#----\n",(*getCCModeFlag)());
  }

int (*getSBFlag)(void);
getSBFlag = dlsym(lib, "getSBFlag");
if (getSBFlag!=0)
  {
  printf("getSBFlag = %p\n", getSBFlag);
  printf("Result of getSBFlag %d\n#----\n",(*getSBFlag)());
  }

int (*Java_com_sec_android_service_sm_job_SecurityNativeJob_getSBFlag)(void);
Java_com_sec_android_service_sm_job_SecurityNativeJob_getSBFlag = dlsym(lib, "Java_com_sec_android_service_sm_job_SecurityNativeJob_getSBFlag");
if (Java_com_sec_android_service_sm_job_SecurityNativeJob_getSBFlag!=0)
  {
  printf("Java_com_sec_android_service_sm_job_SecurityNativeJob_getSBFlag = %p\n", Java_com_sec_android_service_sm_job_SecurityNativeJob_getSBFlag);
  printf("Result of Java_com_sec_android_service_sm_job_SecurityNativeJob_getSBFlag %d\n#----\n",(*Java_com_sec_android_service_sm_job_SecurityNativeJob_getSBFlag)());
  }

int (*Java_com_sec_android_service_sm_job_SecurityNativeJob_getCCModeFlag)(void);
Java_com_sec_android_service_sm_job_SecurityNativeJob_getCCModeFlag = dlsym(lib, "Java_com_sec_android_service_sm_job_SecurityNativeJob_getCCModeFlag");
if (Java_com_sec_android_service_sm_job_SecurityNativeJob_getCCModeFlag!=0)
  {
  printf("Java_com_sec_android_service_sm_job_SecurityNativeJob_getCCModeFlag = %p\n", Java_com_sec_android_service_sm_job_SecurityNativeJob_getCCModeFlag);
  printf("Result of Java_com_sec_android_service_sm_job_SecurityNativeJob_getCCModeFlag %d\n#----\n",(*Java_com_sec_android_service_sm_job_SecurityNativeJob_getCCModeFlag)());
  }

}
//Java_com_sec_android_service_sm_job_SecurityNativeJob_setCCModeFlag
//Java_com_sec_android_service_sm_job_SecurityNativeJob_setSBFlagOff

/*

use 
  su
  logcat
you may need 
  logwrapper -a /tmp/unlock

02-24 20:21:54.589  3488  3488 D SecurityManager: SecurityManagerNative v1.2.5.3 On 32bit PLATFORM With BORINGSSL
02-24 20:21:54.589  3488  3488 D SecurityManager: The current status of CC : 2
02-24 20:21:54.589  3488  3488 D SecurityManager: MDFPP STATUS : 2
02-24 20:21:54.589  3488  3488 D SecurityManager: sec_data_flag input parameter is invalid : 27
02-24 20:21:54.589  3488  3488 D SecurityManager: sec_data_flag input parameter is invalid : 23
02-24 20:21:54.589  3488  3488 D SecurityManager: READ SB flag with SEC_DATAIO...START
02-24 20:21:54.589  3488  3488 E FRIGATE_BIRD: Error : Permission error!
02-24 20:21:54.589  3488  3488 D SecurityManager: Failed to read_from_secBlock. res : -1
02-24 20:21:54.589  3488  3488 D SecurityManager: READ CC flag with SEC_DATAIO...START
02-24 20:21:54.589  3488  3488 E FRIGATE_BIRD: Error : Permission error!
02-24 20:21:54.589  3488  3488 D SecurityManager: Failed to read_from_secBlock. res : -1
02-24 20:21:54.589  3488  3488 D SecurityManager: Failed to open f : No such file or directory
02-24 20:21:54.589  3488  3488 D SecurityManager: Failed to open f : No such file or directory
02-24 20:21:54.599  3488  3488 D SecurityManager: READ SB flag with SEC_DATAIO...START
02-24 20:21:54.599  3488  3488 E FRIGATE_BIRD: Error : Permission error!
02-24 20:21:54.599  3488  3488 D SecurityManager: Failed to read_from_secBlock. res : -1
02-24 20:21:54.599  3488  3488 E FRIGATE_BIRD: Error : Permission error!
02-24 20:21:54.599  3488  3488 D SecurityManager: Failed to read_from_secBlock. res : -1
*/


