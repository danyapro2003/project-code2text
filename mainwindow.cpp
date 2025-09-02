#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->treeWidget->setHeaderLabels({"Имя", "Путь"});
    ui->treeWidget->setColumnWidth(0, 250);

    connect(ui->treeWidget, &QTreeWidget::itemChanged,
            this, &MainWindow::onItemChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonBrowse_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this,
                                                    tr("Choose folder with input files"),
                                                    QString(),
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!dir.isEmpty()) {
        ui->lineEditBrowse->setText(dir);
        viewTreeFolder();
    }
}

void MainWindow::viewTreeFolder() {
    ui->treeWidget->clear();

    QString rootPath = ui->lineEditBrowse->text();
    QDir dir(rootPath);
    if (!dir.exists()) {
        qDebug() << "Нет такой папки:" << rootPath;
        return;
    }

    // Корневой элемент
    QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget);
    root->setText(0, dir.dirName().isEmpty() ? rootPath : dir.dirName());
    root->setText(1, rootPath);
    root->setCheckState(0, Qt::Checked);
    root->setIcon(0, QIcon(":/icons/folder.png"));

    // Добавляем содержимое
    addFolderItems(root, rootPath);

    ui->treeWidget->addTopLevelItem(root);
    root->setExpanded(true); // раскрыть сразу
}


void MainWindow::addFolderItems(QTreeWidgetItem *parent, const QString &path) {
    QDir dir(path);
    QFileInfoList entries = dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);

    for (const QFileInfo &entry : entries) {
        QTreeWidgetItem *item = new QTreeWidgetItem();
        item->setText(0, entry.fileName());   // имя файла/папки
        item->setText(1, entry.absoluteFilePath()); // полный путь
        item->setCheckState(0, Qt::Checked); // чекбокс

        if (entry.isDir()) {
            item->setIcon(0, QIcon(":/icons/folder.png")); // если есть иконка
            parent->addChild(item);
            // рекурсивно добавляем содержимое папки
            addFolderItems(item, entry.absoluteFilePath());
        } else {
            item->setIcon(0, QIcon(":/icons/file.png"));
            parent->addChild(item);
        }
    }
}

void MainWindow::onItemChanged(QTreeWidgetItem *item){
    Qt::CheckState state = item->checkState(0);

    for (int i = 0; i < item->childCount(); i++) {
        QTreeWidgetItem *child = item->child(i);
        child->setCheckState(0, state);
    }
}

void MainWindow::collectChecked(QTreeWidgetItem *item, QStringList &result)
{
    if (item->checkState(0) == Qt::Checked) {
        // Берём путь (во второй колонке)
        result << item->text(1);
    }

    for (int i = 0; i < item->childCount(); i++) {
        collectChecked(item->child(i), result);
    }
}

QStringList MainWindow::getCheckedFiles()
{
    QStringList result;

    for (int i = 0; i < ui->treeWidget->topLevelItemCount(); i++) {
        QTreeWidgetItem *root = ui->treeWidget->topLevelItem(i);
        collectChecked(root, result);
    }

    return result;
}


void MainWindow::on_pushButtonStart_clicked()
{
    if(ui->lineEditBrowse->text().trimmed().isEmpty()){
        QMessageBox::warning(this, "Ошибка", "Выберите папку!");
        return;
    }

    QStringList checkedFiles = getCheckedFiles();

    for(const QString &filePath : checkedFiles){
        QFile file(filePath);

        if(!file.open(QIODevice::ReadOnly)){
            qDebug() << "Failed to open file for reading:" << filePath;
            continue;
        }

        QByteArray data = file.readAll();
        QString text = "=== File: " + filePath + "===\n" + QString::fromUtf8(data) + "\n\n";

        ui->plainTextEdit->appendPlainText(text);
        file.close();
    }


    //воркер который заходит во все файлы и в другом потоке выписывает все из выбранных файлов и формирует файл, и выводит на экран.
}

