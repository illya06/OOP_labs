#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_pushButton_clicked();

    void on_add_clicked();

    void on_pushButton_2_clicked();

    void on_del_clicked();

    void on_copy_clicked();

    void on_change_clicked();

    void on_sort_clicked();

    void on_add_2_clicked();

    void on_add_3_clicked();

    void on_find_clicked();

    void on_show_set_clicked();

    void on_show_set_2_clicked();

    void on_find_2_clicked();

    void on_sort_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
