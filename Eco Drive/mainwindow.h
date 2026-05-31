#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "vehicleprofile.h"
#include "trip.h"
#include "route.h"
#include "fuelpriceapi.h"

class QTableWidgetItem;
class QKeyEvent;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_saveProfileButton_clicked();
    void on_dashboardButton_clicked();
    void on_routeAnalysisButton_clicked();
    void on_settingsButton_clicked();
    void on_calculateButton_clicked();
    void on_saveRouteButton_clicked();
    void on_deleteButton_clicked();
    void on_tableWidget_itemClicked(QTableWidgetItem *item);
    void on_petrolButton_clicked();
    void on_dieselButton_clicked();
    void on_refreshButton_clicked();

private:
    void requestFuelPrice(const QString &fuelType, bool forceRefresh = false);
    void updateFuelPriceDisplay(const QString &fuelType, double price);

    Ui::MainWindow *ui;

    VehicleProfile userProfile;
    FuelPriceAPI *m_fuelPriceApi = nullptr;

    double m_petrolPrice = 0.0;
    double m_dieselPrice = 0.0;
    QString m_pendingFuelType = "Diesel";

    int m_lastSelectedRow = -1;


protected:
    void keyPressEvent(QKeyEvent *event) override;
};
#endif // MAINWINDOW_H
