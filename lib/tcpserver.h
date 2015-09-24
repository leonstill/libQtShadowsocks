/*
 * tcpserver.h - Multi-threaded Shadowsocks TCP Server
 *
 * Copyright (C) 2015 Symeon Huang <hzwhuang@gmail.com>
 *
 * This file is part of the libQtShadowsocks.
 *
 * libQtShadowsocks is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * libQtShadowsocks is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with libQtShadowsocks; see the file LICENSE. If not, see
 * <http://www.gnu.org/licenses/>.
 */

#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QObjectCleanupHandler>
#include "address.h"
#include "encryptorprivate.h"
#include "export.h"

namespace QSS {

class QSS_EXPORT TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit TcpServer(const EncryptorPrivate &ep, const int &timeout, const bool &is_local, const bool &auto_ban, const bool &auth, const Address &serverAddress, QObject *parent = nullptr);
    ~TcpServer();

    void clear();

signals:
    void debug(const QString &);
    void info(const QString &);
    void bytesRead(const qint64 &);
    void bytesSend(const qint64 &);

protected:
    void incomingConnection(qintptr handler) Q_DECL_OVERRIDE;

private:
    QObjectCleanupHandler socketsCleaner;
    const bool &isLocal;
    const bool &autoBan;
    const bool &auth;
    const Address &serverAddress;
    const int &timeout;
    const EncryptorPrivate &ep;
};

}

#endif // TCPSERVER_H
