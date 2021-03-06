/*
    Copyright (c) 2019, Lukas Holecek <hluk@email.cz>

    This file is part of CopyQ.

    CopyQ is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    CopyQ is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with CopyQ.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef DUMMYPLATFORM_H
#define DUMMYPLATFORM_H

#include "platform/platformnativeinterface.h"

#include <QKeyEvent>
#include <QString>

class DummyPlatform : public PlatformNativeInterface
{
public:
    PlatformWindowPtr getWindow(WId) override { return PlatformWindowPtr(); }

    PlatformWindowPtr getCurrentWindow() override { return PlatformWindowPtr(); }

    bool canGetWindowTitle() override { return false; }

    bool canAutostart() override { return false; }

    bool isAutostartEnabled() override { return false; }

    void setAutostartEnabled(bool) override {}

    QCoreApplication *createConsoleApplication(int &argc, char **argv) override;

    QApplication *createServerApplication(int &argc, char **argv) override;

    QGuiApplication *createMonitorApplication(int &argc, char **argv) override;

    QGuiApplication *createClipboardProviderApplication(int &argc, char **argv) override;

    QCoreApplication *createClientApplication(int &argc, char **argv) override;

    QGuiApplication *createTestApplication(int &argc, char **argv) override;

    void loadSettings() override {}

    PlatformClipboardPtr clipboard() override;

    int keyCode(const QKeyEvent &event) override { return event.key(); }

    QStringList getCommandLineArguments(int argc, char **argv) override;

    bool findPluginDir(QDir *pluginsDir) override;

    QString defaultEditorCommand() override;

    QString translationPrefix() override;

    QString themePrefix() override { return QString(); }
};

#endif // DUMMYPLATFORM_H
