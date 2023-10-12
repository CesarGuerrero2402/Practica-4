#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Neuronas.h"
#include <string>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

Neuronas *neu=new Neuronas();

int i,px,py,r,g,b,neuronas=0;
double v;
QString mos;
char a='e';


MainWindow::~MainWindow()
{
    delete ui;
    int i,px,py,r,g,b;
    float v;
}

void MainWindow::on_pushButtonM_clicked()
{
    int n=1;
    ui->stackedWidget->setCurrentIndex(1);
    if(neuronas>0)
    {
        while(n<=neuronas)
        {
        neu->mostrar(i,v,px,py,r,g,b,n);
        QString mostrar;
        mostrar.setNum(i);
        ui->plainTextEditMostrar->insertPlainText(mostrar);
        mostrar.setNum(v);
        ui->plainTextEditMostrar->insertPlainText("\t" + mostrar);
        mostrar.setNum(px);
        ui->plainTextEditMostrar->insertPlainText("\t" + mostrar);
        mostrar.setNum(py);
        ui->plainTextEditMostrar->insertPlainText("\t" + mostrar);
        mostrar.setNum(r);
        ui->plainTextEditMostrar->insertPlainText("\t" + mostrar);
        mostrar.setNum(g);
        ui->plainTextEditMostrar->insertPlainText("\t" + mostrar);
        mostrar.setNum(b);
        ui->plainTextEditMostrar->insertPlainText("\t" + mostrar +"\n");
        n=n+1;
        }
    }
    else 
        {
             ui->plainTextEditMostrar->insertPlainText("No hay neuronas guardadas.\n");
        }
}

void MainWindow::on_pushButtonRegresar_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->plainTextEditMostrar->clear();
}


void MainWindow::on_pushButtonAI_clicked()
{
    neu->insertarinicio(i,v,px,py,r,g,b);
    neuronas++;
}


void MainWindow::on_spinBoxID_valueChanged(int arg1)
{
    i=arg1;
}


void MainWindow::on_doubleSpinBoxV_valueChanged(double arg1)
{
    v=arg1;
}


void MainWindow::on_spinBoxX_valueChanged(int arg1)
{
    px=arg1;
}

void MainWindow::on_spinBoxY_valueChanged(int arg1)
{
    py=arg1;
}


void MainWindow::on_spinBoxR_valueChanged(int arg1)
{
    r=arg1;
}


void MainWindow::on_spinBoxG_valueChanged(int arg1)
{
    g=arg1;
}


void MainWindow::on_spinBoxB_valueChanged(int arg1)
{
    b=arg1;
}




void MainWindow::on_pushButtonAF_clicked()
{
    neu->insertarfinal(i,v,px,py,r,g,b);
    neuronas++;
}

