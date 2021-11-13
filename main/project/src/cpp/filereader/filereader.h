#ifndef FILEREADER_H
#define FILEREADER_H
#include <QString>
#include <QStringList>
#include <QMap>
#include <QVector>


struct yandeInfo {  //单个文件
    QString filePath;       //文件路径
    QString name;           //文件名
    QStringList taglist;    //文件标签
};

class FileReader
{
public:
    FileReader();

    void loadAllFiles(const QString &path);

    void loadAllTags();

    int getTagsNum(const QString &tag);

private:
    bool checkIsImage(const QString &path);

private:
    QMap<QString, int> m_tagsNum;   //所有标签及其数量的统计
    QVector<yandeInfo> m_allFiles;  //所有文件
};

#endif // FILEREADER_H
