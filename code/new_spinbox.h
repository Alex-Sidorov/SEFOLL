#ifndef NEW_SPINBOX_H
#define NEW_SPINBOX_H

#include <QSpinBox>

class NewSpinBox : public QSpinBox
{
    Q_OBJECT
public:
    void set_prev_value(int value);
    int get_prev_value()const;

    explicit NewSpinBox(QWidget *parent = 0);
    virtual ~NewSpinBox();

private:
    int _prev_value;

    static const int MAX_COUNT;
};

#endif // NEW_SPINBOX_H
