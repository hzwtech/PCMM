#include "ListTimerQueue.h"
#include "ITimer.h"
#include "TimeStat.h"
#include "Component.h"
#include "App.h"
#include "AppConst.h"
#include "Trace.h"
#include <iostream>



namespace TimerHandler {

ListTimerQueue::ListTimerQueue()
    :isExecuting_(false)
{

}

ListTimerQueue::~ListTimerQueue()
{
}

void ListTimerQueue::addTimer(ITimer* timer)
{
    if (!isExecuting_)
    {
        if (timersList_.empty())
        {
            timersList_.push_back(timer);
            return;
        }
        else
        {
            TimersList::iterator it = timersList_.end();
            TimersList::iterator lastIt = it--;
            for (; it != timersList_.begin(); lastIt = it--)
            {
                const ITimer* timerInList = *it;
                if (timer->getExpiredTime() >= timerInList->getExpiredTime())
                {
                    timersList_.insert(lastIt, timer);
                    return;
                }
            }
            timersList_.push_front( timer);
        }
    }
    else
    {
        timersCacheList_.push_back(TimerCache(TimerCache::Add, timer->getTimerId(), timer));
    }
}

void ListTimerQueue::deleteTimer(uint64_t timerID)
{
    if (!isExecuting_)
    {
        for (TimersList::iterator it = timersList_.begin(); it != timersList_.end(); ++it)
        {
           ITimer* timerInList = *it;
           if (timerInList->getTimerId() == timerID)
           {
               it = timersList_.erase(it);
           }
        }
    }
    else
    {
        timersCacheList_.push_back(TimerCache(TimerCache::Delete, timerID, nullptr));
    }
}

void ListTimerQueue::executeTimers()
{
    isExecuting_ = true;
    TimeStat totalStat;
    for (TimersList::iterator it = timersList_.begin(); it != timersList_.end(); ++it)
    {

        ITimer* timerInList = *it;
        if (timerInList->isExpired())
        {
             TimeStat singleStat;
             timerInList->onTime();
             if (timerInList->getTimerType() != TimerType::PeriodTimer)
             {
                it = timersList_.erase(it);
             }
             const uint64_t singleTimerElapse = singleStat.getElapseTimeAsMilliSecond();
             if (singleTimerElapse > MaxRunningDurationForSingleTimer)
             {
                 TRACE_NOTICE("Timer is executing more than " << MaxRunningDurationForSingleTimer
                              << "ms, Timer Information" << timerInList);
             }
        }
        else
        {
            break;
        }
        const uint64_t totalElapse = totalStat.getElapseTimeAsMilliSecond();
        if (totalElapse > MaxRunningDurationForTimersInOneLoop)
        {
            TRACE_DEBUG("Timers is executing more than " << MaxRunningDurationForTimersInOneLoop << "ms");
        }
    }
    isExecuting_ = false;

    refreshTimers();
}

std::ostream& ListTimerQueue::operator<<(std::ostream& os) const
{
    os << "[";
    for (TimersList::const_iterator it = timersList_.cbegin(); it != timersList_.cend(); ++it)
    {
        os << "timer=" << *it;
    }
    os << "]";\
    return os;
}

void ListTimerQueue::refreshTimers()
{
    if (isExecuting_)
    {
       TRACE_WARNING("Can not refresh timers during execution!");
       return;
    }

    for (TimersCacheList::iterator it = timersCacheList_.begin(); it != timersCacheList_.end(); ++it)
    {
        TimerCache& timerCache = *it;
        if (timerCache.op_ == TimerCache::Add)
        {
            addTimer(timerCache.timer_);
        }
        else if (timerCache.op_ == TimerCache::Delete)
        {
            deleteTimer(timerCache.timerId_);
        }
        else
        {
            TRACE_WARNING("unkown timer operator: timerId = " << timerCache.timerId_ << ", operator = " << static_cast<int>(timerCache.op_));
        }
    }
    timersCacheList_.clear();
}

std::ostream& operator<<(std::ostream& os, ITimerQueue* timerQueue)
{
    return timerQueue->operator <<(os);
}

}
