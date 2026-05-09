#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
