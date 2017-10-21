#ifndef CPUINFO_H
#define CPUINFO_H

#include <QObject>
#include <QFile>

#ifdef Q_OS_WIN
    #include "Windows.h"
#elif (defined(Q_OS_ANDROID) || defined(Q_OS_LINUX))
    #include <sys/types.h>
    #include <sys/sysinfo.h>
#endif

class CpuInfo : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double cpuUsage READ cpuUsage NOTIFY cpuUsageChanged)
public:
    CpuInfo();

    double cpuUsage() const;

public slots:
    void update();

signals:
    void cpuUsageChanged();

private:
    double m_cpuUsage;

#ifdef Q_OS_WIN
    FILETIME idleTime;
    FILETIME kernelTime;
    FILETIME userTime;

    FILETIME last_idleTime;
    FILETIME last_kernelTime;
    FILETIME last_userTime;

    qulonglong convertFileTime(const FILETIME& filetime) const;
#elif (defined(Q_OS_ANDROID) || defined(Q_OS_LINUX))
    qulonglong totalUser = 0;
    qulonglong totalUserNice = 0;
    qulonglong totalSystem = 0;
    qulonglong totalIdle = 0;

    qulonglong last_totalUser = 0;
    qulonglong last_totalUserNice = 0;
    qulonglong last_totalSystem = 0;
    qulonglong last_totalIdle = 0;
#endif
};

#endif // CPUINFO_H
