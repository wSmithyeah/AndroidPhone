#include "config.h"
#include <stdio.h>
#include <dlfcn.h>
#include <unistd.h>
#include <string.h>
#include <android/log.h>

int main(int argc, char** argv)
{
char mpath[256];
getcwd(mpath,255);

printf("\n\n\nstarting...\n");
printf("executable at :%s\nname :%s\n----\n",mpath,argv[0]);
//--
void* liblog = dlopen("/system/lib/liblog.so", RTLD_LAZY); // Added so I can write "logcat" logs
int (*alog)(int prio, const char *tag,  const char *fmt, ...);
alog = dlsym(liblog, "__android_log_print");
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
  printf("Compiled. Moving file to Download\nMust be run as SU\n----\n");
  DoCopy();
  }
else
  {
  //  *** the code is failing at 5c20 code block on call connect@PLT. FRIGATE_BIRD: Error : Connect Failed : Socket fail : No such file or directory
  // It looks like it's trying to create a socket called "/dev/socket/frigate", but NO error for "failed to create socket: %s\\n"
  // compile. copy from phone/download to AndroidPhone
  // open terminal
  // go to AndroidPhone
  // ./copy.sh # copies latest unlock to tmp, opens "adb shell"
  // cd tmp
  // ./su
  // ./unlock
  // logcat # to see all logs (and errors)



  alog(ANDROID_LOG_INFO, "UNLOCK", "Unlock code started");
  //--
  alog(ANDROID_LOG_INFO, "UNLOCK", "About to call setCCModeFlag");
  int (*setCCModeFlag)(int arg1, int arg2);
  // arg 1 : 0=unlock, 1=lock
  // arg 2 : 0=check through VPN, 1=normal
  setCCModeFlag = dlsym(lib, "setCCModeFlag");
  if (setCCModeFlag!=0)
    {
    alog(ANDROID_LOG_INFO, "UNLOCK","setCCModeFlag = %p\n", setCCModeFlag);
    alog(ANDROID_LOG_INFO, "UNLOCK","Result of setCCModeFlag %d\n#----\n",(*setCCModeFlag)(0, 1));
    }
  //--
  alog(ANDROID_LOG_INFO, "UNLOCK", "About to call setSBFlag");
  int (*setSBFlag)(int arg1, int arg2);
  // arg1 : 0=unlock, 1=lock
  // arg2 : write NOCC or FFOC based on the value (1 or 0)
  setSBFlag = dlsym(lib, "setSBFlag");
  if (setSBFlag!=0)
    {
    alog(ANDROID_LOG_INFO, "UNLOCK","setSBFlag = %p\n", setSBFlag);
    alog(ANDROID_LOG_INFO, "UNLOCK","Result of setSBFlag %d\n#----\n",(*setSBFlag)(0,1)); // D SecurityManager: Failed to open f : No such file or directory
    }
  //--
  alog(ANDROID_LOG_INFO, "UNLOCK", "Test code complete");
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
printf("Copy complete\n");
}
//--
