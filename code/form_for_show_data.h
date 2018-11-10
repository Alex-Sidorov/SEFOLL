#ifndef FORM_FOR_SHOW_DATA_H
#define FORM_FOR_SHOW_DATA_H

#include <QWidget>

namespace Ui {
class Form_For_Show_Data;
}

class Form_For_Show_Data : public QWidget
{
    Q_OBJECT

public:
    explicit Form_For_Show_Data(QWidget *parent = 0);
    ~Form_For_Show_Data();

signals:
    void to_main_window();

private:
    Ui::Form_For_Show_Data *ui;
};

#endif // FORM_FOR_SHOW_DATA_H
