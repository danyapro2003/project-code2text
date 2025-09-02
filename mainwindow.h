#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonBrowse_clicked();
    void onItemChanged(QTreeWidgetItem *item);

    void on_pushButtonStart_clicked();

private:
    void viewTreeFolder();
    void addFolderItems(QTreeWidgetItem* parent, const QString &path);

    void collectChecked(QTreeWidgetItem *item, QStringList &result);
    QStringList getCheckedFiles();


    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
