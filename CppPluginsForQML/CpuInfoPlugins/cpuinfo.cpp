#include "cpuinfo.h"

CpuInfo::CpuInfo()
{
    m_cpuUsage = 0;

#ifdef Q_OS_WIN
    //get the last systemtime
    GetSystemTimes(&last_idleTime, &last_kernelTime, &last_userTime);
#elif (defined(Q_OS_ANDROID) || defined(Q_OS_LINUX))
    //get cpu first time running
    QFile file2("/proc/stat");
    file2.open(QIODevice::ReadOnly);
    QByteArray line2 = file2.readLine();
    file2.close();
    sscanf(line2.data(), "cpu %llu %llu %llu %llu", &last_totalUser, &last_totalUserNice, &last_totalSystem, &last_totalIdle);
#endif
}

double CpuInfo::cpuUsage() const
{
    return m_cpuUsage;
}

void CpuInfo::update()
{
#ifdef Q_OS_WIN
    //update cpu
    GetSystemTimes( &this->idleTime, &this->kernelTime, &this->userTime);
    qulonglong usr, ker, idl, sys;
    usr = convertFileTime(userTime)   - convertFileTime(last_userTime);
    ker = convertFileTime(kernelTime) - convertFileTime(last_kernelTime);
    idl = convertFileTime(idleTime)   - convertFileTime(last_idleTime);
    sys = ker + usr;
    last_userTime = userTime;
    last_kernelTime = kernelTime;
    last_idleTime = idleTime;
    m_cpuUsage = (sys - idl) * 100 / sys;
#elif (defined(Q_OS_ANDROID) || defined(Q_OS_LINUX))
    //update cpu
    QFile file2("/proc/stat");
    file2.open(QIODevice::ReadOnly);
    QByteArray line2 = file2.readLine();
    file2.close();
    sscanf(line2.data(), "cpu %llu %llu %llu %llu", &totalUser, &totalUserNice, &totalSystem, &totalIdle);

    double overall = totalUser - last_totalUser;
    overall += totalUserNice - last_totalUserNice;
    overall += totalSystem - last_totalSystem;

    double total = overall + totalIdle - last_totalIdle;
    last_totalUser = totalUser;
    last_totalUserNice = totalUserNice;
    last_totalSystem = totalSystem;
    last_totalIdle = totalIdle;

    m_cpuUsage = (overall / total) * 100.0;
#endif

    emit cpuUsageChanged();
}

#ifdef Q_OS_WIN
qulonglong CpuInfo::convertFileTime(const FILETIME& filetime) const
{
    ULARGE_INTEGER largeInteger;
    largeInteger.LowPart = filetime.dwLowDateTime;
    largeInteger.HighPart = filetime.dwHighDateTime;
    return largeInteger.QuadPart;
}
#endif
