/*
 * MIT License
 *
 * Copyright (c) 2019 Alexey Edelev <semlanik@gmail.com>
 *
 * This file is part of qtprotobuf project https://git.semlanik.org/semlanik/qtprotobuf
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this
 * software and associated documentation files (the "Software"), to deal in the Software
 * without restriction, including without limitation the rights to use, copy, modify,
 * merge, publish, distribute, sublicense, and/or sell copies of the Software, and
 * to permit persons to whom the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies
 * or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
 * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include "testserviceclient.h"
#include "http2channel.h"
#include "blobmessage.h"
#include <sslcredentials.h>

#include <QTimer>
#include <QFile>
#include <QCryptographicHash>
#include <QSslConfiguration>

#include <QCoreApplication>
#include <gtest/gtest.h>

using namespace qtprotobufnamespace::tests;
using namespace qtprotobuf;

class ClientTest : public ::testing::Test
{
protected:
    static QCoreApplication m_app;
    static int m_argc;
    static QUrl m_echoServerAddress;
};

int ClientTest::m_argc(0);
QCoreApplication ClientTest::m_app(m_argc, nullptr);
QUrl ClientTest::m_echoServerAddress("https://localhost:60051", QUrl::StrictMode);

TEST_F(ClientTest, IncorrectSecureCredentialsTest)
{
    //Prepare ssl configuration
    QSslConfiguration conf = QSslConfiguration::defaultConfiguration();

    //NOTE: CA certificate setup is ommited on purpose
    //  QFile certFile("cert.pem");
    //  certFile.open(QIODevice::ReadOnly);
    //  QByteArray cert = certFile.readAll();
    //  conf.setCaCertificates({QSslCertificate(cert)});

    conf.setProtocol(QSsl::TlsV1_2);
    //conf.setAllowedNextProtocols({QSslConfiguration::ALPNProtocolHTTP2});

    std::shared_ptr<qtprotobuf::AbstractChannel> channel(new qtprotobuf::Http2Channel(m_echoServerAddress, qtprotobuf::SslCredentials(conf)));

    TestServiceClient testClient;
    testClient.attachChannel(channel);

    QPointer<SimpleStringMessage> result(new SimpleStringMessage);
    EXPECT_FALSE(testClient.testMethod(SimpleStringMessage{"Hello beach!"}, result));

    delete result;
}