#include "maindialog.h"
#include "ui_maindialog.h"


#include <QDesktopServices> /// open site
#include <QUrl>
#include <QColorDialog>
#include <QFile>
#include <QDir>
#include <QFileDialog>

#include "src/dialogs/about/about.h"
#include "src/defines/defines.h"

#include "src/test/testdialog.h"
#include "src/test/testmainwindow.h"

#include "src/debug/debughelper.h"


//------------------------------------------------------------------------------
void MainDialog::slotQuit()
{
    // save or not
    myDebug() << "Quit";
    qApp->quit();
}
//------------------------------------------------------------------------------
void MainDialog::slotSaveStyle()
{
    QString filename = QFileDialog::getSaveFileName(
                this,
                tr("Save Document"),
                QDir::currentPath(),
                tr("Qt Style Sheets (*.qss)") );
    if( !filename.isNull() )
    {
        QString text = ui->TECode->toPlainText();

        QFile fileOut(filename);
        if (!fileOut.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            return ;
        }

        QTextStream streamFileOut(&fileOut);
        streamFileOut.setCodec("UTF-8");
        streamFileOut << text;
        streamFileOut.flush();

        fileOut.close();
    }
}
//------------------------------------------------------------------------------
void MainDialog::slotLoadExample()
{
    myDebug() << "Load style";
}
//------------------------------------------------------------------------------
void MainDialog::slotUpdatePreview()
{
    myDebug() << "update preview";
}
//------------------------------------------------------------------------------
void MainDialog::slotShowAboutDialog()
{
    GUI_AboutDialog = new AboutDialog();
    GUI_AboutDialog->show();
}
//------------------------------------------------------------------------------
void MainDialog::slotOpenHomePage()
{
    QDesktopServices::openUrl(QUrl(D_WEB_SITE));
}
//------------------------------------------------------------------------------
void MainDialog::slotSelectTab(int f_numberTab)
{
    ui->comBElements->clear();
    switch ( f_numberTab )
    {
    case TAB_MAIN:
        ui->comBElements->addItems(m_listMainSettings);
        break;
    case TAB_INNER:
        ui->comBElements->addItems(m_listInnerSettings);
        break;
    default:
        myDebug() << "[ERROR]";
    }
}
//------------------------------------------------------------------------------
void MainDialog::slotPickColor()
{
    QColor color;
    color = QColorDialog::getColor(Qt::green, this);
    if (color.isValid()) {
        ui->LAColor->setText(color.name());
        ui->LAColor->setPalette(QPalette(color));
        ui->LAColor->setAutoFillBackground(true);
    }
}
//------------------------------------------------------------------------------
void MainDialog::slotShowTestDialog()
{
    GUI_TestDialog->show();
}
//------------------------------------------------------------------------------
void MainDialog::slotShowTestMainWindow()
{
    GUI_TestMainWindow->show();
}
//------------------------------------------------------------------------------


