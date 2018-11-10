#ifndef NEW_SPINBOX_H
#define NEW_SPINBOX_H

#include <QSpinBox>

class New_SpinBox : public QSpinBox
{
    Q_OBJECT
public:
    void set_prev_value(int value);
    int get_prev_value()const;

    explicit New_SpinBox(QWidget *parent = 0);
    virtual ~New_SpinBox();

private:
    int _prev_value;

};

#endif // NEW_SPINBOX_H
