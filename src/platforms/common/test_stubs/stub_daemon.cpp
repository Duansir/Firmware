#include <string>
#include <map>

#include <platforms/posix/apps.h>

namespace px4_daemon
{
namespace Pxh
{
void process_line(std::string &, bool) {}
}
}

void init_app_map(apps_map_type &apps) {}
void list_builtins(apps_map_type &apps) {}
