#include "UnixProcess.h"
#include "FilePathHandler.h"
#include "Trace.h"
#ifndef _WIN32
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#endif

namespace ProcessManagementSupport
{

UnixProcess::UnixProcess(const std::string& executedBinaryPath)
    : executedBinaryPath_(executedBinaryPath)
{
}

UnixProcess::~UnixProcess()
{

}

void UnixProcess::startProcess()
{
    if (!FilePathHandler::isFileExist(executedBinaryPath_))
    {
        TRACE_ERROR("Can not fork the process:" << executedBinaryPath_ << ", the File is not exsited!");
        return;
    }
#ifndef _WIN32
    pid_t pid = fork();
    // parent process
    if (pid > 0)
    {
        pid_ = pid;
    }
    else if (pid == 0)
    {
        const std::string processName = FilePathHandler::getFileName(executedBinaryPath_);
        execl(executedBinaryPath_.c_str(), processName.c_str());
    }
    else
    {
        TRACE_ERROR("Can not fork the process:" << executedBinaryPath_);
    }
#endif
}

void UnixProcess::stopProcess()
{
#ifndef _WIN32
    if (pid_ > 0)
    {
        kill(pid_, 9);
    }
#endif
}

LPStatus UnixProcess::checkStatus()
{
    if (pid_ <= 0)
    {
        return LPStatus::STOPPED;
    }
#ifndef _WIN32
    int status = -1;
    waitpid(pid, &status, WNOHANG);
    if (WIFEXITED(status))
    {
        status_ = LPStatus::STOPPED;
        TRACE_NOTICE("process id=" << pid << " exit normally, exit status =" << WEXITSTATUS(status));
    }
    else if (WIFSIGNALED(status))
    {
        status_ = LPStatus::STOPPED;
        TRACE_NOTICE("process id=" << pid << " exit by signal, signal is " << WTERMSIG(status));
        if (WCOREDUMP(status))
        {
            TRACE_NOTICE("process id=" << pid << "core dumped");
        }
    }
    else
    {
        status_ = LPStatus::RUNNING;
    }
#endif
    return status_;
}

}
