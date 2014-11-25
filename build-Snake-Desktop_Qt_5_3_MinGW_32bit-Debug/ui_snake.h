/********************************************************************************
** Form generated from reading UI file 'snake.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNAKE_H
#define UI_SNAKE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Snake
{
public:
    QAction *action_veryFast;
    QAction *action_fast;
    QAction *action_mid;
    QAction *action_slow;
    QAction *action_verySlow;
    QAction *action_help;
    QAction *action_Snake;
    QAction *action_startGame;
    QAction *action_pause;
    QAction *action_quit;
    QWidget *centralWidget;
    QLabel *label_Score;
    QLabel *label_Level;
    QMenuBar *menuBar;
    QMenu *menu_P;
    QMenu *menu_H;
    QMenu *menu_G;

    void setupUi(QMainWindow *Snake)
    {
        if (Snake->objectName().isEmpty())
            Snake->setObjectName(QStringLiteral("Snake"));
        Snake->resize(466, 473);
        action_veryFast = new QAction(Snake);
        action_veryFast->setObjectName(QStringLiteral("action_veryFast"));
        action_fast = new QAction(Snake);
        action_fast->setObjectName(QStringLiteral("action_fast"));
        action_mid = new QAction(Snake);
        action_mid->setObjectName(QStringLiteral("action_mid"));
        action_slow = new QAction(Snake);
        action_slow->setObjectName(QStringLiteral("action_slow"));
        action_verySlow = new QAction(Snake);
        action_verySlow->setObjectName(QStringLiteral("action_verySlow"));
        action_help = new QAction(Snake);
        action_help->setObjectName(QStringLiteral("action_help"));
        action_Snake = new QAction(Snake);
        action_Snake->setObjectName(QStringLiteral("action_Snake"));
        action_startGame = new QAction(Snake);
        action_startGame->setObjectName(QStringLiteral("action_startGame"));
        action_pause = new QAction(Snake);
        action_pause->setObjectName(QStringLiteral("action_pause"));
        action_quit = new QAction(Snake);
        action_quit->setObjectName(QStringLiteral("action_quit"));
        centralWidget = new QWidget(Snake);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_Score = new QLabel(centralWidget);
        label_Score->setObjectName(QStringLiteral("label_Score"));
        label_Score->setGeometry(QRect(100, 0, 81, 21));
        label_Score->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\346\245\267\344\275\223\";\n"
"color rgb(0, 255, 0)"));
        label_Level = new QLabel(centralWidget);
        label_Level->setObjectName(QStringLiteral("label_Level"));
        label_Level->setGeometry(QRect(270, 0, 81, 21));
        label_Level->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\346\245\267\344\275\223\";\n"
"color rgb(0 255,0);"));
        Snake->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Snake);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 466, 23));
        menu_P = new QMenu(menuBar);
        menu_P->setObjectName(QStringLiteral("menu_P"));
        menu_H = new QMenu(menuBar);
        menu_H->setObjectName(QStringLiteral("menu_H"));
        menu_G = new QMenu(menuBar);
        menu_G->setObjectName(QStringLiteral("menu_G"));
        Snake->setMenuBar(menuBar);

        menuBar->addAction(menu_G->menuAction());
        menuBar->addAction(menu_P->menuAction());
        menuBar->addAction(menu_H->menuAction());
        menu_P->addAction(action_veryFast);
        menu_P->addAction(action_fast);
        menu_P->addAction(action_mid);
        menu_P->addAction(action_slow);
        menu_P->addAction(action_verySlow);
        menu_H->addAction(action_help);
        menu_H->addAction(action_Snake);
        menu_G->addAction(action_startGame);
        menu_G->addAction(action_pause);
        menu_G->addAction(action_quit);

        retranslateUi(Snake);

        QMetaObject::connectSlotsByName(Snake);
    } // setupUi

    void retranslateUi(QMainWindow *Snake)
    {
        Snake->setWindowTitle(QApplication::translate("Snake", "Snake", 0));
        action_veryFast->setText(QApplication::translate("Snake", "\351\243\236\345\277\253", 0));
        action_fast->setText(QApplication::translate("Snake", "\350\276\203\345\277\253", 0));
        action_mid->setText(QApplication::translate("Snake", "\344\270\255\351\200\237", 0));
        action_slow->setText(QApplication::translate("Snake", "\350\276\203\346\205\242", 0));
        action_verySlow->setText(QApplication::translate("Snake", "\345\276\210\346\205\242", 0));
        action_help->setText(QApplication::translate("Snake", "\346\270\270\346\210\217\350\257\264\346\230\216", 0));
        action_Snake->setText(QApplication::translate("Snake", "\345\205\263\344\272\216Snake", 0));
        action_startGame->setText(QApplication::translate("Snake", "\345\274\200\345\247\213(&S)", 0));
        action_pause->setText(QApplication::translate("Snake", "\346\232\202\345\201\234(&P)", 0));
        action_quit->setText(QApplication::translate("Snake", "\351\200\200\345\207\272(&Q)", 0));
        label_Score->setText(QApplication::translate("Snake", "Score:", 0));
        label_Level->setText(QApplication::translate("Snake", "Level:", 0));
        menu_P->setTitle(QApplication::translate("Snake", "\351\200\237\345\272\246\350\256\276\345\256\232(&P)", 0));
        menu_H->setTitle(QApplication::translate("Snake", "\345\270\256\345\212\251(&H)", 0));
        menu_G->setTitle(QApplication::translate("Snake", "\346\270\270\346\210\217(&G)", 0));
    } // retranslateUi

};

namespace Ui {
    class Snake: public Ui_Snake {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNAKE_H
