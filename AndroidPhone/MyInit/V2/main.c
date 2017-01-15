


#include <sys/mount.h>
#include "parser.h"
#include "init_parser.h"
#include "log.h"
#include "property_service.h"
#include "util.h"
#include "init_parser.h"
//-----------------------------------------------------------------
int main(int argc, char **argv)
{

mount("devpts", "/dev/pts", "devpts", 0, NULL);
mount("sysfs", "/sys", "sysfs", 0, NULL);
//--
klog_init();
property_init();
//--
process_kernel_cmdline();
//--
INFO("reading config file\n");
init_parse_config_file("/tmp/myinit.rc");
}
//-----------------------------------------------------------------
