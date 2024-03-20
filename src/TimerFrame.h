#pragma once

#include "TimerFrameBase.h"

#include <wx/timer.h>


namespace view
{
    class TimerFrame : public TimerFrameBase
    {
    public:
        TimerFrame();

    private:
        wxTimer m_timer;

        wxDateTime m_startTime;

        void OnTimerStart(
            wxCommandEvent&) override;

        void OnTimerStop(
            wxCommandEvent&) override;

        void OnTimerUpdate(
            wxTimerEvent&);

        void UpdateDisplayedTime();
    };
}
