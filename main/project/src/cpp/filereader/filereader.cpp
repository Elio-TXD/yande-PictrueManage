#include "filereader.h"

#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QMessageBox>
#include <QMimeType>
#include <QMimeDatabase>
#include <QDebug>
#include <QFileInfoList>

FileReader::FileReader()
{

}

//QString("E:/我的图片");
void FileReader::loadAllFiles(const QString &path) {
    QString dirpath = path;
    QDir dir(dirpath);
    if (!dir.exists()) {
        QMessageBox::warning(nullptr, "警告", "当前加载目录无效");
        return;
    }
    dir.setFilter(QDir::AllEntries | QDir::NoSymLinks | QDir::NoDotAndDotDot);
    dir.setSorting(QDir::DirsLast);
    QFileInfoList filelist = dir.entryInfoList();
    for (auto it : filelist) {
        if (it.isDir()) {
            qDebug() << "load dir: " << it.filePath();
            loadAllFiles(it.filePath());
        }
        if (checkIsImage(it.filePath())) {
            //是图片文件
            qDebug() << "load file: " << it.filePath();
            QString nameinfo = it.fileName().left(it.fileName().lastIndexOf("."));
            QStringList list = nameinfo.split(" ");
            if (list.count()) {
                if (list[0] == "yande.re") {
                    yandeInfo item;
                    item.filePath = it.filePath();
                    item.name = it.fileName();
                    item.taglist = list;
                    m_allFiles.push_back(item);
                }
            }
        }
    }
}

void FileReader::loadAllTags() {
    for (auto item : m_allFiles) {
        QStringList tmpList = item.taglist;
        //从第三项开始读取tag，前两项分别是yande.re和编号id
        for (int i = 2; i < tmpList.count(); i++) {
            QString tag = tmpList[i];
            if (m_tagsNum.count(tag)) {
                m_tagsNum[tag]++;
            } else {
                m_tagsNum[tag] = 1;
            }
        }
    }

    //test output
#if 0
    {
        QString anotherPath = "./output";
        QDir dir;
        bool canCopy = false;
        if (dir.mkdir(anotherPath)) {
            canCopy = true;
        }

        QString output = "./testLoadInfo.txt";
        QFile file(output);
        if (file.open(QFile::WriteOnly)) {
            //总体情况
            file.write("====== * 总体情况 * =======\n");
            for (auto it = m_tagsNum.begin(); it != m_tagsNum.end(); it++) {
                QString outText = QString("%2\t%1\n").arg(it.key()).arg(it.value());
                file.write(outText.toUtf8().data());
            }
            //文件情况
            file.write("====== * 其他yande系列图片路径 * =======\n");
            for (auto it = m_allFiles.begin(); it != m_allFiles.end(); it++) {
                QString outText = QString("%1\n").arg(it->filePath);
                file.write(outText.toUtf8().data());

                if (canCopy) {
                    QFile copyFile(it->filePath);
                    if (!copyFile.copy(QString("%1/%2").arg(anotherPath).arg(it->name))) {
                        qDebug() << "[file]" << it->name << "复制失败";
                    }
                }
            }
            file.write("====== * 统计结束 * =======\n");
        }
        file.close();
    }
#endif
}

int FileReader::getTagsNum(const QString &tag) {
    if (m_tagsNum.count(tag)) {
        return m_tagsNum.value(tag);
    }
    return 0;
}

bool FileReader::checkIsImage(const QString &path) {
    QMimeDatabase db;
    QMimeType mime = db.mimeTypeForFile(path);
    if (mime.name().startsWith("image/")) {
        return true;
    }
    return false    ;
}
