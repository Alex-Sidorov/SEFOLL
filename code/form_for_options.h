#ifndef FORM_FOR_OPTIONS_H
#define FORM_FOR_OPTIONS_H

/*#include "ui_form_for_add_password.h"
#include "ui_form_for_change_password.h"
#include "ui_form_for_delete_password.h"
#include "ui_form_for_change_access.h"*/

#include <QWidget>

namespace Ui {
class Form_for_options;
}

class Form_for_options : public QWidget
{
    Q_OBJECT

public:
    explicit Form_for_options(QWidget *parent = 0);
    ~Form_for_options();

private:
    Ui::Form_for_options *ui;

};

#endif // FORM_FOR_OPTIONS_H
