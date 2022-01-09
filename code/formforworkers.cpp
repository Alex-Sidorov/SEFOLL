#include "formforworkers.h"
#include "ui_formforworkers.h"
#include <QMessageBox>

const Qt::GlobalColor FormForWorkers::SELECT_FIELD_COLOR  = Qt::blue;
const Qt::GlobalColor FormForWorkers::DEFAULT_FIELD_COLOR = Qt::white;

FormForWorkers::FormForWorkers(AbstractWorkersWorker* database, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormForWorkers),
    m_data_base(database),
    m_is_first_show(true)
{
    ui->setupUi(this);

    setWindowIcon(QIcon(":icons/icon.png"));
}

bool FormForWorkers::init_table()
{
    if(m_data_base)
    {
        auto workers = m_data_base->read_workers();
        for(auto &worker : workers)
        {
            auto count_row = ui->workers->rowCount();
            ui->workers->insertRow(count_row);
            ui->workers->setItem(count_row,0,new QTableWidgetItem(worker));
        }
        return true;
    }
    return false;
}

void FormForWorkers::show()
{
    if(m_is_first_show && !init_table())
    {
        QMessageBox::warning(this,"Ошибка","Невозможно показать работников");
    }
    m_is_first_show = false;
    QWidget::show();
}

FormForWorkers::~FormForWorkers()
{
    delete ui;
}

void FormForWorkers::on_back_button_clicked()
{
    this->close();
    emit to_main_window();
}


void FormForWorkers::on_addWorkerButton_clicked()
{
    auto name = ui->name_worker->text();
    if(m_data_base && !name.isEmpty())
    {
        if(m_data_base->add_worker(name))
        {
            auto count_row = ui->workers->rowCount();
            ui->workers->insertRow(count_row);
            ui->workers->setItem(count_row,0,new QTableWidgetItem(name));
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Невозможно добавить работника");
        }
    }
}


void FormForWorkers::on_workers_itemClicked(QTableWidgetItem *item)
{
    if(item->backgroundColor() != SELECT_FIELD_COLOR)
    {
        m_selected_items.append(item);
        item->setBackgroundColor(SELECT_FIELD_COLOR);
        item->setBackgroundColor(SELECT_FIELD_COLOR);
    }
    else
    {
        m_selected_items.removeOne(item);
        item->setBackgroundColor(DEFAULT_FIELD_COLOR);
        item->setBackgroundColor(DEFAULT_FIELD_COLOR);
    }

    if(m_selected_items.count() == 0)
    {
        ui->deleteWorkerButton->setEnabled(false);
    }
    else
    {
        ui->deleteWorkerButton->setEnabled(true);
    }
}

const QList<QString> FormForWorkers::get_names_workers()
{
    if(m_is_first_show)
    {
        init_table();
        m_is_first_show = false;
    }

    QList<QString> list;
    auto count = ui->workers->rowCount();
    list.reserve(count);
    for(int i = 0; i < count; i++)
    {
        list.append(ui->workers->item(i,0)->text());
    }
    return list;
}


void FormForWorkers::on_deleteWorkerButton_clicked()
{
    QVector<QTableWidgetItem*> temp;
    temp.reserve(m_selected_items.size());
    if(m_data_base && request_for_delete() == QMessageBox::Ok)
    {
        for(auto& item : qAsConst(m_selected_items))
        {
            if(m_data_base->remove_worker(item->text()))
            {
                temp.push_back(item);
                ui->workers->removeRow(item->row());
            }
            else
            {
                QMessageBox::warning(this,"Ошибка","Невозможно удалить некоторых работников");
                break;
            }
        }
        for(auto& item : qAsConst(temp))
        {
            m_selected_items.removeOne(item);
        }
    }

}

int FormForWorkers::request_for_delete()const
{
    QMessageBox message;
    message.setText("Вы уверены, что хотите удалить выбранные элементы?");
    message.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    return message.exec();
}

