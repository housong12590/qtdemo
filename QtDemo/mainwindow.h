#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private :
    int m_time_id;

private slots:

    void on_btn_open_file_clicked();

    void on_btn_save_file_clicked();

public :
    virtual void timerEvent(QTimerEvent *enevt);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
