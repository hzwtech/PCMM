#ifndef _EVENTHANDLER_LISTEVENTQUEUE_H_
#define _EVENTHANDLER_LISTEVENTQUEUE_H_
#include "IEventQueue.h"
#include "Component.h"
#include "Macro.h"
#include <list>

namespace EventHandler {
class IEvent;

// using EventList = std::list<IEvent*>;
typedef std::list<IEvent*> EventList;

class ListEventQueue : public IEventQueue
{
    EventList eventsList_;
public:
    ListEventQueue();
    virtual ~ListEventQueue();
    virtual void AddEvent(IEvent*);
    virtual void deleteEvent(uint64_t eventID);
    virtual void executeEvents();
    virtual std::ostream& operator<<(std::ostream& os);

public:
     GETCLASSNAME(SocketImp)
};

}

#endif // _EVENTHANDLER_EVENTQUEUE_H_
