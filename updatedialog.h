#ifndef UPDATEDIALOG_H
#define UPDATEDIALOG_H

#include <QDialog>

#include "settings.h"
#include "logger.h"
#include "downloadmanager.h"

namespace Ui {
class UpdateDialog;
}

class UpdateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateDialog(QWidget *parent = 0);
    ~UpdateDialog();

private:
    Ui::UpdateDialog *ui;
    Settings* settings;
    Logger* logger;
    DownloadManager* dm;

    QString clientVersion;
    QStringList removeList;

    bool updateState;

    bool downloadIfNotExists(QString url, QString fileName);
    bool addToQueryIfNeed(QString url,
                          QString fileName,
                          QString displayName,
                          QString checkSumm,
                          quint64 size);

private slots:
    void clientChanged();

    void doCheck();
    void doUpdate();

    void downloadStarted(QString displayName);
    void error(QString errorString);
    void updateFinished();

};

#endif // UPDATEDIALOG_H
