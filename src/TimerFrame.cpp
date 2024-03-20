#include "TimerFrame.h"


namespace view
{
    TimerFrame::TimerFrame():
        TimerFrameBase(nullptr)
    {
        UpdateDisplayedTime();

        m_timer.Bind(wxEVT_TIMER, &TimerFrame::OnTimerUpdate, this);
    }

    void TimerFrame::OnTimerStart(
        wxCommandEvent&)
    {
        m_startTime = wxDateTime::Now();

        /* Fire every second */
        m_timer.Start(1000);

        /* Update view immediately after starting */
        UpdateDisplayedTime();
    }

    void TimerFrame::OnTimerStop(
        wxCommandEvent&)
    {
        m_timer.Stop();

        /* Update view immediately after stopping */
        UpdateDisplayedTime();
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
            const wxTimeSpan ellapsedTime = currentTime - m_startTime;
        
            m_timerTextCtrl->SetLabel(ellapsedTime.Format("%H:%M:%S"));
        }
        else
        {
            m_timerTextCtrl->SetLabel("");
        }
    }
}
