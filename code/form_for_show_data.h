#ifndef FORM_FOR_SHOW_DATA_H
#define FORM_FOR_SHOW_DATA_H

#include <QWidget>

namespace Ui {
class Form_For_Show_Data;
}

class FormForShowData : public QWidget
{
    Q_OBJECT

public:
    explicit FormForShowData(QWidget *parent = 0);
    FormForShowData(const FormForShowData&) = delete;
    ~FormForShowData();

signals:
    void to_main_window();

private:
    Ui::Form_For_Show_Data *ui;
};

#endif // FORM_FOR_SHOW_DATA_H
