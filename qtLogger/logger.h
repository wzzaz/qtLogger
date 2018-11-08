#ifndef LOGGER_H
#define LOGGER_H

#include <QFile>
#include <QString>

enum
{
    log_critical,
    log_error,
    log_warn,
    log_info,
    log_debug,
    log_debug_2,

    log_level_count
};

#define MAX_LOG_STRING_LEN  4096

class Logger
{
public:
    Logger(const QString & strLogFile, int level = log_debug_2);
    ~Logger();

    bool isValid();
    void setLogLevel(int level);
    void log(int level, const char * fmt, ...);
    void log(int level, const QString &content);
    void setMaxSize(int bytes){m_maxSize = bytes;}

protected:
    void log2file(const QString &log);
    void backup();

protected:
    int m_loglevel;
    QFile * m_file;
    int m_maxSize;
};

#ifdef Q_OS_WIN
#define INT64_FMT "%I64d"
#else
#define INT64_FMT "%lld"
#endif
#endif // LOGGER_H
