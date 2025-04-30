#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //initialize names field
    names.push_back("Maria");
    names.push_back("Xijing");
    names.push_back("Shilpa");
    names.push_back("Alexei");
    names.push_back("Hector");

    //set up table
    ui->nameTable->setColumnCount(1);
    ui->nameTable->setRowCount(names.size());
    for(std::size_t i=0; i<names.size(); ++i){
        QTableWidgetItem *spot = new QTableWidgetItem((QString::fromStdString(names[i])));
        ui->nameTable->setItem(i, 0, spot);
    }

    connect(ui->nameTable, &QTableWidget::cellClicked, this, &MainWindow::printCell);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printCell(int row, int col){
    QTableWidgetItem *spot = new QTableWidgetItem(QString::fromStdString(names[row]+" clicked!"));
    ui->nameTable->setItem(row, col, spot);
}
