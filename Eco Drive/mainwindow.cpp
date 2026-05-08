#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QButtonGroup>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QButtonGroup *fuelGroup = new  QButtonGroup(this);

    ui->petrolButton->setCheckable(true);
    ui->dieselButton->setCheckable(true);

    fuelGroup->addButton(ui->petrolButton);
    fuelGroup->addButton(ui->dieselButton);

    connect(ui->routeAnalysisButton, &QPushButton::clicked, this, &MainWindow::on_routeAnalysisButton_clicked);
    connect(ui->dashboardButton, &QPushButton::clicked, this, &MainWindow::on_dashboardButton_clicked);
    connect(ui->settingsButton, &QPushButton::clicked, this, &MainWindow::on_settingsButton_clicked);
    connect(ui->saveProfileButton, &QPushButton::clicked, this, &MainWindow::on_saveProfileButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_routeAnalysisButton_clicked(){
    ui->stackedWidget->setCurrentWidget(ui->RouteAnalysisPage);
}
void MainWindow::on_dashboardButton_clicked(){
    ui->stackedWidget->setCurrentWidget(ui->travelHistoryPage);
}
void MainWindow::on_settingsButton_clicked(){
    ui->stackedWidget->setCurrentWidget(ui->settingsPage);
}
void MainWindow::on_saveProfileButton_clicked(){
    QString modelis = ui->carModelLine->text();
    QString sanaudos = ui->avgCansumptionEnterLine->text();
    QString kuroTipas = ui->dieselButton->isChecked() ? "Diesel" : "Petrol";

    if(!modelis.isEmpty()){
        ui->carModelLabel->setText(modelis);
    }
    if(!sanaudos.isEmpty()){
        ui->descriptionLabel->setText(sanaudos + " L/100km " + kuroTipas);
    }
    ui->consumptionLine->setText(sanaudos);
}
