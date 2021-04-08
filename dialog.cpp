#include "dialog.h"
#include "ui_dialog.h"
#include<QMessageBox>
#include<QDebug>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply=QMessageBox::question(this,"Pragna 6080","Confirm submission?",QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::Yes)
    {
        QMessageBox::information(this,"Pragna 6080","Submission is SUCCESSFUL");
    }
    if(reply==QMessageBox::No)
    {
        qDebug()<<"Submission Failed";
    }
}

void Dialog::on_lineEdit_2_returnPressed()
{
    QRegularExpression re("^[a-zA-Z0-9+_.-]+@[a-zA-Z0-9.-]+$");
    QRegularExpressionMatch match=re.match(ui->lineEdit_2->text());
    bool hasMatch=match.hasMatch();
    if(!hasMatch)
    {
        QMessageBox::information(this,"Pragna 6080","Invalid format");
    }
}
