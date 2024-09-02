#include "TimerFrame.h"


namespace view
{
    void TimerFrame::Start()
    {
        m_startTime = wxDateTime::Now();

        /* Fire every second */
        m_timer.Start(1000);

        /* Update view immediately after starting */
        UpdateDisplayedTime();
    }

    void TimerFrame::Stop()
    {
        m_timer.Stop();

        /* Update view immediately after stopping */
        UpdateDisplayedTime();
    }

    TimerFrame::TimerFrame():
        TimerFrameBase(nullptr)
    {
        m_timer.Bind(wxEVT_TIMER, &TimerFrame::OnTimerUpdate, this);
    }

    void TimerFrame::OnTimerStart(
        wxCommandEvent&)
    {
        Start();
    }

    void TimerFrame::OnTimerStop(
        wxCommandEvent&)
    {
        Stop();
    }

    void TimerFrame::OnTimerUpdate(
        wxTimerEvent&)
    {
        UpdateDisplayedTime();
    }

    void TimerFrame::UpdateDisplayedTime()
    {
        if (m_timer.IsRunning())
        {
            const wxDateTime currentTime = wxDateTime::Now();
            const wxTimeSpan elapsedTime = currentTime - m_startTime;
        
            m_timerTextCtrl->SetLabel(elapsedTime.Format("%H:%M:%S"));
        }
        else
        {
            m_timerTextCtrl->SetLabel("");
        }
    }
}
