// Header file for FileInsight

#include <magic.h>
#include <iostream>

#ifndef FILEINSIGHT_H
#define FILEINSIGHT_H

#include <QMainWindow>
#include <QIcon>
#include <QPaintEvent>
#include <QWidget>
#include <QFileDialog>
#include <QByteArray>
#include <QFileIconProvider>
#include <QMimeType>

namespace Ui {
class FileInsight;
}

class FileInsight : public QMainWindow
{
    Q_OBJECT

    public:
        explicit FileInsight(QWidget *parent = 0);
        ~FileInsight();
        void openFile(QString filename);
        void chooseFile();
        void showIcon(QString mimetype);
        QString getMimeType();
        QString getMagicInfo();

    private slots:
        void on_actionQuit_triggered();

        void on_selectFileButton_clicked();

        void on_actionSelect_triggered();

    private:
        Ui::FileInsight *ui;
        magic_t magic_cookie = 0;
        magic_t magic_cookie_mime = 0;
        QFileIconProvider iconprovider;
        const char * cfilename;
        QByteArray filename_bytes;
        QString last_filename;
        QIcon icon;
};

#endif // FILEINSIGHT_H
