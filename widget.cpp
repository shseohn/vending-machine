#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    if (money < 100) {
        ui->pbCoffee->setEnabled(false);
    }
    if (money < 200) {
        ui->pbTea->setEnabled(false);
    }
    if (money < 500) {
        ui->pbMilk->setEnabled(false);
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::increaseMoney(int value)
{
    if (money < 0) {
        return;
    }

    money += value;
    ui->lcdNumber->display(money);

    ui->pbCoffee->setEnabled(money >= 100);
    ui->pbTea->setEnabled(money >= 200);
    ui->pbMilk->setEnabled(money >= 500);
}
void Widget::on_pb10_clicked()
{
    increaseMoney(10);

}

void Widget::on_pb50_clicked()
{
    increaseMoney(50);
}

void Widget::on_pb100_clicked()
{
    increaseMoney(100);

}

void Widget::on_pb500_clicked()
{
    increaseMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    increaseMoney(-100);
}


void Widget::on_pbMilk_clicked()
{
    increaseMoney(-500);
}


void Widget::on_pbTea_clicked()
{
    increaseMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    int tempMoney = money;
    int coin500 = tempMoney / 500;
    tempMoney %= 500;
    int coin100 = tempMoney / 100;
    tempMoney %= 100;
    int coin50 = tempMoney / 50;
    tempMoney %= 50;
    int coin10 = tempMoney / 10;
    tempMoney %= 10;

    QString message = QString("Change\n₩500 : %1\n₩100 : %2\n₩50 : %3\n₩10 : %4")
                          .arg(coin500)
                          .arg(coin100)
                          .arg(coin50)
                          .arg(coin10);

    QMessageBox mb;
    mb.information(this, "Change Return", message);

    money = 0;
    ui->lcdNumber->display(money);
}

