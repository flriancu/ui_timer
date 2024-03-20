#include "TimerFrame.h"

#include <wx/app.h>


class TimerApp : public wxApp
{
public:
    virtual bool OnInit() override
    {
        (new view::TimerFrame())->Show();

        return true;
    }
};

wxIMPLEMENT_APP(TimerApp);
