#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "InputValidator.h"
#include <QButtonGroup>
#include <QMessageBox>

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
    QString model = ui->carModelLine->text();
    QString consumption = ui->avgCansumptionEnterLine->text();
    QString fuelType = ui->dieselButton->isChecked() ? "Diesel" : "Petrol";

    if (!ui->petrolButton->isChecked() && !ui->dieselButton->isChecked()) {
        QMessageBox::warning(this, "Invalid Input", "Please select a fuel type");
        return;
    }

    QString error = InputValidator::validateProfileInputs(consumption, ui->priceLine_2->text());
    if (!error.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", error);
        return;
    }

    if(!model.isEmpty()){
        ui->carModelLabel->setText(model);
    }
    if(!consumption.isEmpty()){
        ui->descriptionLabel->setText(consumption + " L/100km " + fuelType);
    }
    ui->consumptionLine->setText(consumption);
    ui->priceLine->setText(ui->priceLine_2->text());
}

void MainWindow::on_calculateButton_clicked(){
    QString error = InputValidator::validateRouteInputs(
        ui->startLine->text(),
        ui->destinationLine->text(),
        ui->priceLine->text(),
        ui->consumptionLine->text()
        );

    if (!error.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", error);
        return;
    }

    double consumption = ui->consumptionLine->text().toDouble();
    double price = ui->priceLine->text().toDouble();
    double distance = 180.0;

    double fuelNeeded = (distance / 100.0) * consumption;
    double totalCost = fuelNeeded * price;

    ui->distanceResult->setText(QString::number(distance, 'f', 0) + " km");
    ui->distanceResult_2->setText(QString::number(fuelNeeded, 'f', 1) + " L");
    ui->distanceResult_3->setText(QString::number(totalCost, 'f', 2) + " €");
}