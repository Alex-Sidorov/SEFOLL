#include "new_spinbox.h"

void New_SpinBox::set_prev_value(int value)
{
    _prev_value = value;
}

int New_SpinBox::get_prev_value()const
{
    return _prev_value;
}

New_SpinBox::New_SpinBox(QWidget *parent) :
    QSpinBox(parent),
    _prev_value(0)
{
}

New_SpinBox::~New_SpinBox()
{

}
