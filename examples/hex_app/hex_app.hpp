#ifndef HEX_APP_INCLUDED
#define HEX_APP_INCLUDED

#include <tinyfsm.hpp>

// ----------------------------------------------------------------------------
// Event declarations
//

struct HexEvent: tinyfsm::Event
{
    int value;
}

struct Update : HexEvent{};

// ----------------------------------------------------------------------------
// HexApp (FSM base class) declaration
//

class HexApp : public tinyfsm::Fsm<HexApp>
{
    /* NOTE: react(), entry() and exit() functions need to be accessible
     * from tinyfsm::Fsm class. You might as well declare friendship to
     * tinyfsm::Fsm, and make these functions private:
     *
     * friend class Fsm;
     */
public:
    // default reaction for unhandled events
    void react(tinyfsm::Event const&) {};

    virtual void react(Update const&);

    virtual void entry(void) {};  // entry actions in some states
    void exit(void) {};  // no exit actions at all

protected:
    static constexpr int initial_value = 0;
    static int current_value;
};

#endif