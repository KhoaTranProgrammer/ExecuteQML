#include "cpuinfoplugins_plugin.h"
#include "cpuinfo.h"

#include <qqml.h>

void CpuInfoPluginsPlugin::registerTypes(const char *uri)
{
    // @uri CpuInfo
    qmlRegisterType<CpuInfo>(uri, 1, 0, "CpuInfo");
}

