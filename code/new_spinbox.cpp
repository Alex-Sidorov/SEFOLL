#include "new_spinbox.h"

const int NewSpinBox::MAX_COUNT = 1000;

void NewSpinBox::set_prev_value(int value)
{
    _prev_value = value;
}

int NewSpinBox::get_prev_value()const
{
    return _prev_value;
}

NewSpinBox::NewSpinBox(QWidget *parent) :
    QSpinBox(parent),
    _prev_value(0)
{
    this->setMaximum(MAX_COUNT);
}

NewSpinBox::~NewSpinBox()
{

}
