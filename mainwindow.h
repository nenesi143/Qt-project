#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QLineSeries>
#include <QCategoryAxis>
#include <QDateEdit>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QSpinBox>

using namespace QtCharts;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Diagram3_clicked();

private slots:
    void on_addLabwork_clicked();
    void on_ImportButton_clicked();
    void on_DeleteRecord_clicked();
    void on_ExportButton_clicked();
    void on_DeleteRecord_2_clicked();
    void on_EditRecord_clicked();
    void on_newColumn_clicked();
    void on_Request1_clicked();
    void on_Request2_clicked();
    void on_Request3_clicked();
    void on_Request4_clicked();
    void on_Request5_clicked();
    void on_Request2_2_clicked();
    void on_Diagram1_clicked();
    void on_Diagram2_clicked();
    void on_graphic_clicked();
    void on_filterButton_clicked();

private:
    Ui::MainWindow *ui;
    int recordcount = 0;
    const int MAXRECORDS = 30;
    QChartView *chartView;
};
#endif // MAINWINDOW_H
